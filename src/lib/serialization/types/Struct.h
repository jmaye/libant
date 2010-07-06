#ifndef STRUCT_H
#define STRUCT_H

#include "Object.h"
#include "String.h"

#include <iosfwd>
#include <map>

class Connection;

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
    const Struct &obj);
  friend Connection& operator >> (Connection &stream,
    Struct &obj);

  Struct();
  Struct(const Struct &other);
  Struct& operator = (const Struct &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream);
  virtual void write(Connection &stream) const;

  std::map<const String*, const Object*> mStructMap;

public:
  ~Struct();

  virtual Struct* clone() const;

  static const Struct mProto;

protected:
};

#endif // STRUCT_H
