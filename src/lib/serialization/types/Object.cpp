#include "Object.h"

#include "TypesFactory.h"

#include <iostream>
#include <fstream>

using namespace std;

Object::Object() throw(ObjectCreationException) : mu8TypeID(0xff) {
  throw ObjectCreationException("Wrong object");
}

Object::Object(uint8_t u8TypeID) : mu8TypeID(u8TypeID) {
  TypesFactory::getInstance().registerType(this, u8TypeID);
}

Object::Object(const Object &other) : mu8TypeID(other.mu8TypeID) {
}

Object::~Object() {
}

uint8_t Object::getTypeID() const {
  return mu8TypeID;
}

ostream& operator << (ostream &stream,
  const Object &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Object &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Object &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Object &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Object &obj) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Object &obj) {
  obj.read(stream);
  return stream;
}
