#ifndef INT16_H
#define INT16_H

#include "Object.h"

#include <iosfwd>

class Connection;

class Int16 : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Int16 &obj);
  friend std::istream& operator >> (std::istream &stream,
    Int16 &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Int16 &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Int16 &obj);
  friend Connection& operator << (Connection &stream,
    const Int16 &obj);
  friend Connection& operator >> (Connection &stream,
    Int16 &obj);

  Int16();
  Int16(const Int16 &other);
  Int16& operator = (const Int16 &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream);
  virtual void write(Connection &stream) const;

  int16_t ms16Value;

public:
  Int16(int16_t s16Value);
  ~Int16();

  virtual Int16* clone() const;

  int16_t getValue() const;

  static const Int16 mProto;

protected:
};

#endif // INT16_H
