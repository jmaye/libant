#include "ObjectCreationException.h"

using namespace std;

ObjectCreationException::ObjectCreationException(const string &msg)
  : out_of_range(msg) {
}
