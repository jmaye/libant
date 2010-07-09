#ifndef INT64_H
#define INT64_H

#include "Object.h"
#include "IOException.h"

#include <iosfwd>

#include <stdint.h>

class Connection;

class Int64 : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Int64 &obj);
  friend std::istream& operator >> (std::istream &stream,
    Int64 &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Int64 &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Int64 &obj);
  friend Connection& operator << (Connection &stream,
    const Int64 &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    Int64 &obj) throw(IOException);

  Int64();
  Int64(const Int64 &other);
  Int64& operator = (const Int64 &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream) throw(IOException);
  virtual void write(Connection &stream) const throw(IOException);

  int64_t ms64Value;

public:
  Int64(int64_t s64Value);
  ~Int64();

  virtual Int64* clone() const;

  int64_t getValue() const;

  static const Int64 mProto;

protected:

};

#endif // INT64_H
