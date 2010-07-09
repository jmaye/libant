#ifndef ARRAY_H
#define ARRAY_H

#include "Object.h"
#include "OutOfBoundException.h"
#include "ObjectCreationException.h"
#include "IOException.h"

#include <iosfwd>
#include <vector>

#include <stdint.h>

class Connection;

class Array : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Array &obj);
  friend std::istream& operator >> (std::istream &stream,
    Array &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Array &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Array &obj);
  friend Connection& operator << (Connection &stream,
    const Array &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    Array &obj) throw(ObjectCreationException, IOException);

  Array(const Array &other);
  Array& operator = (const Array &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream)
    throw(ObjectCreationException, IOException);
  virtual void write(Connection &stream) const throw(IOException);

  std::vector<const Object*> mArray;

public:
  Array();
  ~Array();

  virtual Array* clone() const;

  void callWrite(Connection &stream) const throw(IOException);

  uint32_t getLength() const;

  const Object* getElement(uint32_t u32Pos) const throw(OutOfBoundException);

  void pushElement(const Object *objPtr);

  static const Array mProto;

protected:

};

#endif // ARRAY_H
