#include "RemoteException.h"

using namespace std;

RemoteException::RemoteException(const string &msg) : runtime_error(msg) {
}
