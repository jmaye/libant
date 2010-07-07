#include "ObjectCreationException.h"

using namespace std;

ObjectCreationException::ObjectCreationException(const string &msg)
  : range_error(msg) {
}
