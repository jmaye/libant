#include "Platform.h"

#include <iostream>
#include <vector>
#include <string>

#include <stdlib.h>
#include <stdint.h>

using namespace std;

int main(int argc, char **argv) {
  if (argc != 3) {
    cerr << "Usage: " << argv[0] << " <IP> <Port>" << endl;
    return -1;
  }
  Platform proxy(argv[1], atoi(argv[2]));
  proxy.open();
  vector<string> stringVector = proxy.getCalls();
  cout << "Available calls: " << endl;
  for (uint32_t i = 0; i < stringVector.size(); i++)
    cout << stringVector[i] << endl;
  return 0;
}
