#ifndef CALL_H
#define CALL_H

#include "Object.h"
#include "IOException.h"

#include <iosfwd>

class String;
class Array;
class Connection;

class Call : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Call &obj);
  friend std::istream& operator >> (std::istream &stream,
    Call &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Call &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Call &obj);
  friend Connection& operator << (Connection &stream,
    const Call &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    Call &obj) throw(IOException);

  Call();
  Call(const Call &other);
  Call& operator = (const Call &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream) throw(IOException);
  virtual void write(Connection &stream) const throw(IOException);

  const String *mProcStrPtr;
  const Array *mArgsArrayPtr;

public:
  Call(const String *procStrPtr, const Array *argsArrayPtr);
  ~Call();

  virtual Call* clone() const;

  const String* getProcStrPtr() const;

  const Array* getArgsArrayPtr() const;

  static const Call mProto;

protected:
};

#endif // CALL_H
