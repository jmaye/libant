/******************************************************************************
 * Copyright (C) 2011 by Jerome Maye                                          *
 * jerome.maye@gmail.com                                                      *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

#include "Platform.h"

#include <iostream>

#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <errno.h>
#include <sys/signal.h>
#include <limits.h>

using namespace std;

static vector<uint32_t> timeVector;

static uint32_t getMsCount() {
  struct timeval now;
  if (gettimeofday(&now, 0L)) {
    perror("get_ms_count");
    raise(SIGINT);
    return 0;
  }
  else
    return ((now.tv_sec * 1000000) + (now.tv_usec)) / 1000;
}

static void terminationHandler(int signum, siginfo_t *siginfo, void* data)
{
  double f64Mean = 0;
  uint32_t u32Max = 0;
  uint32_t u32Min = INT_MAX;
  for (uint32_t i = 0; i < timeVector.size(); i++) {
    f64Mean += timeVector[i];
    if (timeVector[i] > u32Max)
      u32Max = timeVector[i];
    if (timeVector[i] < u32Min)
      u32Min = timeVector[i];
  }
  f64Mean /= (double)timeVector.size();
  double f64Variance = 0;
  for (uint32_t i = 0; i < timeVector.size(); i++)
    f64Variance += (timeVector[i] - f64Mean) * (timeVector[i] - f64Mean);
  f64Variance /= (double)timeVector.size();
  cout << "Mean time: " << f64Mean << endl;
  cout << "Variance time: " << f64Variance << endl;
  cout << "Min time: " << u32Min << endl;
  cout << "Max time: " << u32Max << endl;
  exit(0);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    cerr << "Usage: " << argv[0] << " <IP> <Port>" << endl;
    return -1;
  }

  Platform proxy(argv[1], atoi(argv[2]));
  proxy.open();
  proxy.login("User", "none");
  proxy.configureLocalization(false);

  struct sigaction signal_handling;
  signal_handling.sa_sigaction = terminationHandler;
  signal_handling.sa_flags     = SA_SIGINFO;

  if (sigaction(SIGINT, &signal_handling, NULL)) {
    perror("sigaction");
    return -1;
  }

  while (1) {
    uint32_t u32Before = getMsCount();
    try {
    Pose pose = proxy.odometryGetPose();
    } catch (IOException &e) {
      cout << "Exception occured" << endl;
      cout << "Closing proxy" << endl;
      proxy.close();
      cout << "Opening proxy" << endl;
      proxy.open();
      cout << "Login proxy" << endl;
      proxy.login("User", "none");
      cout << "Confiure loc" << endl;
      proxy.configureLocalization(false);
      continue;
    }
    uint32_t u32After = getMsCount();
    timeVector.push_back(u32After - u32Before);
    //proxy.motionSetSpeed(0, 0);
  }

  return 0;
}
