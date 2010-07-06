#ifndef INT32_H
#define INT32_H

#include "Object.h"

#include <iosfwd>

class Connection;

class Int32 : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Int32 &obj);
  friend std::istream& operator >> (std::istream &stream,
    Int32 &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Int32 &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Int32 &obj);
  friend Connection& operator << (Connection &stream,
    const Int32 &obj);
  friend Connection& operator >> (Connection &stream,
    Int32 &obj);

  Int32();
  Int32(const Int32 &other);
  Int32& operator = (const Int32 &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream);
  virtual void write(Connection &stream) const;

  int32_t ms32Value;

public:
  Int32(int32_t s32Value);
  ~Int32();

  virtual Int32* clone() const;

  int32_t getValue() const;

  static const Int32 mProto;

protected:
};

#endif // INT32_H
