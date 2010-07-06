#ifndef FLOAT32ARRAY_H
#define FLOAT32ARRAY_H

#include "Object.h"
#include "OutOfBoundException.h"

#include <iosfwd>
#include <vector>

#include <stdint.h>

class Connection;

class Float32Array : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Float32Array &obj);
  friend std::istream& operator >> (std::istream &stream,
    Float32Array &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Float32Array &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Float32Array &obj);
  friend Connection& operator << (Connection &stream,
    const Float32Array &obj);
  friend Connection& operator >> (Connection &stream,
    Float32Array &obj);

  Float32Array(const Float32Array &other);
  Float32Array& operator = (const Float32Array &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream);
  virtual void write(Connection &stream) const;

  std::vector<float> mArray;

public:
  Float32Array();
  ~Float32Array();

  virtual Float32Array* clone() const;

  uint32_t getLength() const;

  float getElement(uint32_t u32Pos) const throw(OutOfBoundException);

  void pushElement(float f32Value);

  static const Float32Array mProto;

protected:
};

#endif // FLOAT32ARRAY_H
