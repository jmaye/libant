#ifndef FLOAT32_H
#define FLOAT32_H

#include "Object.h"

#include <iosfwd>

class Connection;

class Float32 : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Float32 &obj);
  friend std::istream& operator >> (std::istream &stream,
    Float32 &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Float32 &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Float32 &obj);
  friend Connection& operator << (Connection &stream,
    const Float32 &obj);
  friend Connection& operator >> (Connection &stream,
    Float32 &obj);

  Float32();
  Float32(const Float32 &other);
  Float32& operator = (const Float32 &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream);
  virtual void write(Connection &stream) const;

  float mf32Value;

public:
  Float32(float f32Value);
  ~Float32();

  virtual Float32* clone() const;

  float getValue() const;

  static const Float32 mProto;

protected:
};

#endif // FLOAT32_H
