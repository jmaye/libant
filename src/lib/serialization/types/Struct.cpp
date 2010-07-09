#include "Struct.h"

#include "Connection.h"
#include "TypesFactory.h"
#include "String.h"

#include <iostream>
#include <fstream>

using namespace std;

const Struct Struct::mProto;

Struct::Struct() : Object(0x15) {
}

Struct::Struct(const Struct &other) : Object(other) {
}

Struct::~Struct() {
  std::map<string, const Object*>::const_iterator it;
  for (it = mStructMap.begin(); it != mStructMap.end(); it++) {
    delete (*it).second;
  }
}

void Struct::read(istream &stream) {
}

void Struct::write(ostream &stream) const {
}

void Struct::read(ifstream &stream) {
}

void Struct::write(ofstream &stream) const {
}

void Struct::read(Connection &stream)
  throw(ObjectCreationException, IOException) {
  uint32_t u32Length;

  stream >> u32Length;

  for (uint32_t i = 0; i < u32Length; i++) {
    String keyString;
    stream >> keyString;
    uint8_t u8TypeID;
    stream >> u8TypeID;
    const Object *objectPtr = TypesFactory::createObject(u8TypeID);
    stream >> (Object&)*objectPtr;
    mStructMap[keyString.getValue()] = objectPtr;
  }
}

const Object* Struct::getObject(const std::string &strRequest) const
  throw(OutOfBoundException) {
  std::map<string, const Object*>::const_iterator it =
    mStructMap.find(strRequest);
  if (it == mStructMap.end())
    throw OutOfBoundException("Struct");
  else
    return (*it).second;
}

void Struct::write(Connection &stream) const throw(IOException) {
  uint32_t u32Length = mStructMap.size();
  stream << u32Length;

  std::map<string, const Object*>::const_iterator it;
  for (it = mStructMap.begin(); it != mStructMap.end(); it++) {
    String keyString((*it).first);
    stream << keyString;
    stream << (Object&)*(*it).second;
  }
}

Struct* Struct::clone() const {
  return new Struct(*this);
}

uint32_t Struct::getLength() const {
  return mStructMap.size();
}

ostream& operator << (ostream &stream,
  const Struct &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Struct &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Struct &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Struct &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Struct &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Struct &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
