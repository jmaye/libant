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
  RawOdometry rawOdometry = proxy.getRawOdometry();
  cout << "Last raw odometry: time = " << rawOdometry.f64Time << " [s], left = "
       << rawOdometry.f64Left << " [tick], right = "
       << rawOdometry.f64Right << " [tick]" << endl;
  return 0;
}
