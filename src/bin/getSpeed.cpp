#include "Platform.h"

#include <iostream>

#include <stdlib.h>

using namespace std;

int main(int argc, char **argv) {
  if (argc != 3) {
    cerr << "Usage: " << argv[0] << " <IP> <Port>" << endl;
    return -1;
  }
  Platform proxy(argv[1], atoi(argv[2]));
  proxy.open();
  Speed speed = proxy.motionGetSpeed();
  cout << "Speed: " << speed.f64Translation << " [m/s], "
       << speed.f64Rotation << " [rad/s], " << speed.f64Time << " [s]" << endl;
  return 0;
}
