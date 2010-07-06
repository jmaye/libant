#ifndef VOID_H
#define VOID_H

#include "Object.h"

#include <iosfwd>

class Connection;

class Void : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Void &obj);
  friend std::istream& operator >> (std::istream &stream,
    Void &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Void &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Void &obj);
  friend Connection& operator << (Connection &stream,
    const Void &obj);
  friend Connection& operator >> (Connection &stream,
    Void &obj);

  Void(const Void &other);
  Void& operator = (const Void &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream);
  virtual void write(Connection &stream) const;

public:
  Void();
  ~Void();

  virtual Void* clone() const;

  static const Void mProto;

protected:
};

#endif // VOID_H
