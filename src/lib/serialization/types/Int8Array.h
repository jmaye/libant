#ifndef INT8ARRAY_H
#define INT8ARRAY_H

#include "Object.h"
#include "OutOfBoundException.h"

#include <iosfwd>
#include <vector>

#include <stdint.h>

class Connection;

class Int8Array : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Int8Array &obj);
  friend std::istream& operator >> (std::istream &stream,
    Int8Array &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Int8Array &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Int8Array &obj);
  friend Connection& operator << (Connection &stream,
    const Int8Array &obj);
  friend Connection& operator >> (Connection &stream,
    Int8Array &obj);

  Int8Array(const Int8Array &other);
  Int8Array& operator = (const Int8Array &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream);
  virtual void write(Connection &stream) const;

  std::vector<int8_t> mArray;

public:
  Int8Array();
  ~Int8Array();

  virtual Int8Array* clone() const;

  uint32_t getLength() const;

  int8_t getElement(uint32_t u32Pos) const throw(OutOfBoundException);

  void pushElement(int8_t i8Value);

  static const Int8Array mProto;

protected:
};

#endif // INT8ARRAY_H
