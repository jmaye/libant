#ifndef OBJECT_H
#define OBJECT_H

#include "ObjectCreationException.h"
#include "TypeCastException.h"

#include <iosfwd>

#include <stdint.h>

class Connection;

class Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Object &obj);
  friend std::istream& operator >> (std::istream &stream,
    Object &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Object &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Object &obj);
  friend Connection& operator << (Connection &stream,
    const Object &obj);
  friend Connection& operator >> (Connection &stream,
    Object &obj);

  virtual void read(std::istream &stream) = 0;
  virtual void write(std::ostream &stream) const = 0;
  virtual void read(std::ifstream &stream) = 0;
  virtual void write(std::ofstream &stream) const = 0;
  virtual void read(Connection &stream) = 0;
  virtual void write(Connection &stream) const = 0;

public:
  virtual ~Object();

  virtual Object* clone() const = 0;

  virtual uint8_t getTypeID() const;

  template<class O> const O& typeCast() const throw(TypeCastException) {
    if (this->mu8TypeID == O::mProto.mu8TypeID)
      return (const O&)*this;
    else
      throw TypeCastException("Cast failed");
  }

  template<class O> O& typeCast() throw(TypeCastException) {
    if (this->mu8TypeID == O::mProto.mu8TypeID)
      return (O&)*this;
    else
      throw TypeCastException("Cast failed");
  }

  template<class O> bool instanceof() const {
    if (this->mu8TypeID == O::mProto.mu8TypeID)
      return true;
    else
      return false;
  }

  template<class O> bool instanceof() {
    if (this->mu8TypeID == O::mProto.mu8TypeID)
      return true;
    else
      return false;
  }

protected:
  Object() throw(ObjectCreationException);
  Object(uint8_t u8TypeID);
  Object(const Object &other);

  const uint8_t mu8TypeID;
};

#endif // OBJECT_H
