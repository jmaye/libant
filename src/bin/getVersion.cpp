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
  Version ver = proxy.version();
  cout << "LOS version is: " << ver.i32Major << "." << ver.i32Minor << endl;
  return 0;
}
