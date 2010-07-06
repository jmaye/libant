#include "OutOfBoundException.h"

using namespace std;

OutOfBoundException::OutOfBoundException(const string &msg)
  : runtime_error(msg) {
}
