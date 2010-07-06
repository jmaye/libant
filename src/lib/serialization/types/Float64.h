#ifndef FLOAT64_H
#define FLOAT64_H

#include "Object.h"

#include <iosfwd>

class Connection;

class Float64 : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Float64 &obj);
  friend std::istream& operator >> (std::istream &stream,
    Float64 &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Float64 &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Float64 &obj);
  friend Connection& operator << (Connection &stream,
    const Float64 &obj);
  friend Connection& operator >> (Connection &stream,
    Float64 &obj);

  Float64();
  Float64(const Float64 &other);
  Float64& operator = (const Float64 &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream);
  virtual void write(Connection &stream) const;

  double mf64Value;

public:
  Float64(double f64Value);
  ~Float64();

  virtual Float64* clone() const;

  double getValue() const;

  static const Float64 mProto;

protected:

};

#endif // FLOAT64_H
