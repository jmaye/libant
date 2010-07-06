#ifndef BOOLEAN_H
#define BOOLEAN_H

#include "Object.h"

#include <iosfwd>

class Connection;

class Boolean : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Boolean &obj);
  friend std::istream& operator >> (std::istream &stream,
    Boolean &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Boolean &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Boolean &obj);
  friend Connection& operator << (Connection &stream,
    const Boolean &obj);
  friend Connection& operator >> (Connection &stream,
    Boolean &obj);

  Boolean();
  Boolean(const Boolean &other);
  Boolean& operator = (const Boolean &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream);
  virtual void write(Connection &stream) const;

  bool mbValue;

public:
  Boolean(bool bValue);
  ~Boolean();

  virtual Boolean* clone() const;

  bool getValue() const;

  static const Boolean mProto;

protected:
};

#endif // BOOLEAN_H
