#ifndef STRINGARRAY_H
#define STRINGARRAY_H

#include "Object.h"
#include "OutOfBoundException.h"

#include <iosfwd>
#include <vector>
#include <string>

#include <stdint.h>

class Connection;

class StringArray : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const StringArray &obj);
  friend std::istream& operator >> (std::istream &stream,
    StringArray &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const StringArray &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    StringArray &obj);
  friend Connection& operator << (Connection &stream,
    const StringArray &obj);
  friend Connection& operator >> (Connection &stream,
    StringArray &obj);

  StringArray(const StringArray &other);
  StringArray& operator = (const StringArray &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream);
  virtual void write(Connection &stream) const;

  std::vector<std::string> mArray;

public:
  StringArray();
  ~StringArray();

  virtual StringArray* clone() const;

  uint32_t getLength() const;

  const std::string& getElement(uint32_t u32Pos) const
    throw(OutOfBoundException);

  void pushElement(const std::string &strValue);

  static const StringArray mProto;

protected:
};

#endif // STRINGARRAY_H
