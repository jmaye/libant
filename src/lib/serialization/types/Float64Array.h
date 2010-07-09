#ifndef FLOAT64ARRAY_H
#define FLOAT64ARRAY_H

#include "Object.h"
#include "OutOfBoundException.h"
#include "IOException.h"

#include <iosfwd>
#include <vector>

#include <stdint.h>

class Connection;

class Float64Array : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Float64Array &obj);
  friend std::istream& operator >> (std::istream &stream,
    Float64Array &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Float64Array &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Float64Array &obj);
  friend Connection& operator << (Connection &stream,
    const Float64Array &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    Float64Array &obj) throw(IOException);

  Float64Array(const Float64Array &other);
  Float64Array& operator = (const Float64Array &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream) throw(IOException);
  virtual void write(Connection &stream) const throw(IOException);

  std::vector<double> mArray;

public:
  Float64Array();
  ~Float64Array();

  virtual Float64Array* clone() const;

  uint32_t getLength() const;

  double getElement(uint32_t u32Pos) const throw(OutOfBoundException);

  void pushElement(double f64Value);

  static const Float64Array mProto;

protected:
};

#endif // FLOAT64ARRAY_H
