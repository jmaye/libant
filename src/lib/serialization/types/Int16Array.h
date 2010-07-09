#ifndef INT16ARRAY_H
#define INT16ARRAY_H

#include "Object.h"
#include "OutOfBoundException.h"
#include "IOException.h"

#include <iosfwd>
#include <vector>

#include <stdint.h>

class Connection;

class Int16Array : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Int16Array &obj);
  friend std::istream& operator >> (std::istream &stream,
    Int16Array &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Int16Array &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Int16Array &obj);
  friend Connection& operator << (Connection &stream,
    const Int16Array &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    Int16Array &obj) throw(IOException);

  Int16Array(const Int16Array &other);
  Int16Array& operator = (const Int16Array &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream) throw(IOException);
  virtual void write(Connection &stream) const throw(IOException);

  std::vector<int16_t> mArray;

public:
  Int16Array();
  ~Int16Array();

  virtual Int16Array* clone() const;

  uint32_t getLength() const;

  int16_t getElement(uint32_t u32Pos) const throw(OutOfBoundException);

  void pushElement(int16_t i16Value);

  static const Int16Array mProto;

protected:
};

#endif // INT16ARRAY_H
