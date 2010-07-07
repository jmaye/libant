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
  Pose pose = proxy.odometryGetPose();
  cout << "Odometry: " << pose.f64Time << " [s], "
       << "x = " << pose.f64X << " [m], y = " << pose.f64Y << " [m], "
       << "angle = " << pose.f64Angle << "[rad]" << endl;
  return 0;
}
