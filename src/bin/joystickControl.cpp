#include "Platform.h"

#include <iostream>

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/joystick.h>
#include <string.h>
#include <signal.h>

#define JOYSTICK_NAME_SIZE     128
#define JOYSTICK_SLEEP_TIME    0.05
#define JOYSTICK_AXE_MAX       32767
#define JOYSTICK_TRANS_AXE     1
#define JOYSTICK_ROT_AXE       0
#define JOYSTICK_DEAD_BUTTON   0
#define PLATFORM_WATCHDOG_TIME 1.0
#define PLATFORM_MAX_TV        0.2
#define PLATFORM_MAX_RV        0.8

struct Joystick {
  uint32_t mu32Nb;
  uint32_t mu32Na;
  int32_t *mai32Axes;
  int32_t *mai32Buttons;
  Joystick() : mu32Nb(0),
               mu32Na(0),
               mai32Axes(0),
               mai32Buttons(0) {
  }
  ~Joystick() {
    if (mai32Axes != 0)
      delete[] mai32Axes;
    if (mai32Buttons != 0)
      delete[] mai32Buttons;
  }
};

using namespace std;

static void termination_handler(int signum, siginfo_t *siginfo, void *data)
{
  cout << "Exiting..." << endl;
  exit(0);
}

int main(int argc, char **argv) {
  if (argc != 4) {
    cerr << "Usage: " << argv[0] << " <IP> <Port> <Joystick Dev>" << endl;
    return -1;
  }

  int32_t i32JoystickHandle = open(argv[3], O_RDONLY);
  if (i32JoystickHandle == -1) {
    perror("Opening joystick");
    return -1;
  }

  uint32_t u32Version = 0;
  if (ioctl(i32JoystickHandle, JSIOCGVERSION, &u32Version) == -1) {
    perror("Getting version");
    return -1;
  }

  uint32_t u32Na = 0;
  if (ioctl(i32JoystickHandle, JSIOCGAXES, &u32Na) == -1) {
    perror("Getting number of axes");
    return -1;
  }

  uint32_t u32Nb = 0;
  if (ioctl(i32JoystickHandle, JSIOCGBUTTONS, &u32Nb) == -1) {
    perror("Getting number of buttons");
    return -1;
  }

  uint8_t au8Name[JOYSTICK_NAME_SIZE];
  if (ioctl(i32JoystickHandle, JSIOCGNAME(JOYSTICK_NAME_SIZE), au8Name) == -1) {
    perror("Getting name");
    return -1;
  }

  cout << "Joystick detected: " << endl
       << au8Name << endl
       << "Axis: " << u32Na << endl
       << "Buttons: " << u32Nb << endl;

  Joystick joystick;
  joystick.mu32Na = u32Na;
  joystick.mu32Nb = u32Nb;
  joystick.mai32Axes = new int32_t[u32Na];
  memset(joystick.mai32Axes, 0, u32Na * sizeof(int32_t));
  joystick.mai32Buttons = new int32_t[u32Nb];
  memset(joystick.mai32Buttons, 0, u32Nb * sizeof(int32_t));

  if (fcntl(i32JoystickHandle, F_SETFL, O_NONBLOCK) == -1) {
    perror("Setting non-blocking");
    return -1;
  }

  Platform proxy(argv[1], atoi(argv[2]));
  proxy.open();
  proxy.login("User", "none");
  proxy.configureLocalization(false);

  struct sigaction signal_handling;
  signal_handling.sa_sigaction = termination_handler;
  signal_handling.sa_flags     = SA_SIGINFO;
  if (sigaction(SIGINT, &signal_handling, NULL) == -1) {
    perror("Signal registration");
    return -1;
  }

  struct js_event js; 

  while (1) {
    proxy.watchdogReset(PLATFORM_WATCHDOG_TIME);

    if (read(i32JoystickHandle, &js, sizeof(struct js_event)) == -1) {
    } else {
      switch (js.type & ~JS_EVENT_INIT) {
        case JS_EVENT_AXIS:
          joystick.mai32Axes[js.number] = js.value;
          break;
        case JS_EVENT_BUTTON:
          joystick.mai32Buttons[js.number] = js.value;
          break;
      }
    }

    double f64RV = -1 * joystick.mai32Axes[JOYSTICK_ROT_AXE] /
      (double)JOYSTICK_AXE_MAX * PLATFORM_MAX_RV;
    double f64TV = -1 * joystick.mai32Axes[JOYSTICK_TRANS_AXE] /
      (double)JOYSTICK_AXE_MAX * PLATFORM_MAX_TV;

    if (joystick.mai32Buttons[JOYSTICK_DEAD_BUTTON] == 1)
      proxy.motionSetSpeed(f64TV, f64RV);
    else
      proxy.motionStop(true);

    sleep(JOYSTICK_SLEEP_TIME);
  }

  return 0;
}
