#ifndef BOOLEANARRAY_H
#define BOOLEANARRAY_H

#include "Object.h"
#include "OutOfBoundException.h"

#include <iosfwd>
#include <vector>

#include <stdint.h>

class Connection;

class BooleanArray : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const BooleanArray &obj);
  friend std::istream& operator >> (std::istream &stream,
    BooleanArray &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const BooleanArray &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    BooleanArray &obj);
  friend Connection& operator << (Connection &stream,
    const BooleanArray &obj);
  friend Connection& operator >> (Connection &stream,
    BooleanArray &obj);

  BooleanArray(const BooleanArray &other);
  BooleanArray& operator = (const BooleanArray &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream);
  virtual void write(Connection &stream) const;

  std::vector<bool> mArray;

public:
  BooleanArray();
  ~BooleanArray();

  virtual BooleanArray* clone() const;

  uint32_t getLength() const;

  bool getElement(uint32_t u32Pos) const throw(OutOfBoundException);

  void pushElement(bool bValue);

  static const BooleanArray mProto;

protected:
};

#endif // BOOLEANARRAY_H
