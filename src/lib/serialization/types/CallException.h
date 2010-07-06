#ifndef CALLEXCEPTION_H
#define CALLEXCEPTION_H

#include "Object.h"
#include "String.h"

#include <iosfwd>

class Connection;

class CallException : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const CallException &obj);
  friend std::istream& operator >> (std::istream &stream,
    CallException &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const CallException &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    CallException &obj);
  friend Connection& operator << (Connection &stream,
    const CallException &obj);
  friend Connection& operator >> (Connection &stream,
    CallException &obj);

  CallException();
  CallException(const CallException &other);
  CallException& operator = (const CallException &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream);
  virtual void write(Connection &stream) const;

  const String *mNameStrPtr;
  const String *mMsgStrPtr;
  const Object *mObjectPtr;

public:
  ~CallException();

  virtual CallException* clone() const;

  const String* getNameStrPtr() const;

  const String* getMsgStrPtr() const;

  const Object* getObjectPtr() const;

  static const CallException mProto;

protected:

};

#endif // CALLEXCEPTION_H
