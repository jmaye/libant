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
  Safety safety = proxy.getSafety();
  cout << "Battery power: " << (int)safety.u8BatteryPower << endl
       << "Battery voltage: " << safety.f32BatteryVoltage << endl
       << "Messages: " << endl;
  for (uint32_t i = 0; i < safety.strvMessages.size(); i++)
    cout << safety.strvMessages[i] << endl;
  return 0;
}
