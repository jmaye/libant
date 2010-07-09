#ifndef STRUCT_H
#define STRUCT_H

#include "Object.h"
#include "ObjectCreationException.h"
#include "OutOfBoundException.h"
#include "IOException.h"

#include <iosfwd>
#include <map>

#include <stdint.h>

class Connection;
class String;

class Struct : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Struct &obj);
  friend std::istream& operator >> (std::istream &stream,
    Struct &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Struct &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Struct &obj);
  friend Connection& operator << (Connection &stream,
    const Struct &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    Struct &obj) throw(IOException);

  Struct();
  Struct(const Struct &other);
  Struct& operator = (const Struct &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream)
    throw(ObjectCreationException, IOException);
  virtual void write(Connection &stream) const throw(IOException);

  std::map<std::string, const Object*> mStructMap;

public:
  ~Struct();

  virtual Struct* clone() const;

  uint32_t getLength() const;

  const Object* getObject(const std::string &strRequest) const
    throw(OutOfBoundException);

  static const Struct mProto;

protected:
};

#endif // STRUCT_H
