#ifndef INT8_H
#define INT8_H

#include "Object.h"

#include <iosfwd>

#include <stdint.h>

class Connection;

class Int8 : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Int8 &obj);
  friend std::istream& operator >> (std::istream &stream,
    Int8 &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Int8 &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Int8 &obj);
  friend Connection& operator << (Connection &stream,
    const Int8 &obj);
  friend Connection& operator >> (Connection &stream,
    Int8 &obj);

  Int8();
  Int8(const Int8 &other);
  Int8& operator = (const Int8 &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream);
  virtual void write(Connection &stream) const;

  int8_t ms8Value;

public:
  Int8(int8_t s8Value);
  ~Int8();

  virtual Int8* clone() const;

  int8_t getValue() const;

  static const Int8 mProto;

protected:
};

#endif // INT8_H
