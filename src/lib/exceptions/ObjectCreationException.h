#ifndef OBJECTCREATIONEXCEPTION_H
#define OBJECTCREATIONEXCEPTION_H

#include <stdexcept>
#include <string>

class ObjectCreationException : public std::out_of_range {
  ObjectCreationException& operator = (const ObjectCreationException &other);

public:
  ObjectCreationException(const std::string &msg = "");
  ObjectCreationException(const ObjectCreationException &other);

protected:

};

#endif // OBJECTCREATIONEXCEPTION_H
