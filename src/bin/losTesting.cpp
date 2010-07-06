#include "Platform.h"

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  Platform proxy("172.30.50.162", 1234);
  cout << "Opening connection to platform..." << endl;
  proxy.open();
  cout << "Done." << endl;
  cout << "Asking version..." << endl;
  Version ver = proxy.version();
  cout << "LOS version is: " << ver.i32Major << "." << ver.i32Minor << endl;
  cout << "Pinging platform..." << endl;
  proxy.ping();
  cout << "Done." << endl;
  cout << "Logging to platform..." << endl;
  proxy.login("User", "none");
  cout << "Done." << endl;
  cout << "Resetting watchdog..." << endl;
  proxy.watchdogReset(1.0);
  cout << "Done." << endl;
  cout << "Getting speed... " << endl;
  Speed speed = proxy.motionGetSpeed();
  cout << "Speed: " << speed.f64Translation << " [m/s], "
       << speed.f64Rotation << " [rad/s], " << speed.f64Time << " [s]" << endl;
  cout << "Getting motion status... " << endl;
  Status status = proxy.motionGetStatus();
  cout << "Status: " << status.f64Time << " [s], "
       << status.strState << ", " << status.strResult << endl;
  cout << "Getting odometry... " << endl;
  Pose pose = proxy.odometryGetPose();
  cout << "Odometry: " << pose.f64Time << " [s], "
       << "x = " << pose.f64X << " [m], y = " << pose.f64Y << " [m]" << endl;
  cout << "Testing NOP... " << endl;
  cout << "NOP says: " << proxy.testNop() << endl;
  cout << "Testing trow... " << endl;
  //proxy.testThrow("Martin", "Rufli");
  cout << "Getting calls... " << endl;
  vector<string> stringVector = proxy.getCalls();
  cout << "Available calls: ";
  for (uint32_t i = 0; i < stringVector.size(); i++)
    cout << stringVector[i] << endl;
  return 0;
}
