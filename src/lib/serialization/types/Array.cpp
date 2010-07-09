#include "Array.h"

#include "Connection.h"
#include "TypesFactory.h"

#include <iostream>
#include <fstream>

using namespace std;

const Array Array::mProto;

Array::Array() : Object(0x11) {
}

Array::Array(const Array &other) : Object(other) {
  uint32_t u32Length = other.mArray.size();
  for (uint32_t i = 0; i < u32Length; i++)
    mArray.push_back(other.mArray[i]->clone());
}

Array::~Array() {
  uint32_t u32Length = mArray.size();
  for (uint32_t i = 0; i < u32Length; i++) {
    delete mArray[i];
  }
}

void Array::read(istream &stream) {
}

void Array::write(ostream &stream) const {
}

void Array::read(ifstream &stream) {
}

void Array::write(ofstream &stream) const {
}

void Array::read(Connection &stream)
  throw(ObjectCreationException, IOException) {
  uint32_t u32Length;
  stream >> u32Length;
  for (uint32_t i = 0; i < u32Length; i++) {
    uint8_t u8TypeID;
    stream >> u8TypeID;
    const Object *objectPtr = TypesFactory::createObject(u8TypeID);
    stream >> (Object&)*objectPtr;
    mArray.push_back(objectPtr);
  }
}

void Array::write(Connection &stream) const throw(IOException) {
  uint32_t u32Length = mArray.size();
  stream << mu8TypeID << u32Length;
  for (uint32_t i = 0; i < u32Length; i++) {
    stream << (const Object&)*(mArray[i]);
  }
}

Array* Array::clone() const {
  return new Array(*this);
}

void Array::callWrite(Connection &stream) const throw(IOException) {
  uint32_t u32Length = mArray.size();
  stream << u32Length;
  for (uint32_t i = 0; i < u32Length; i++) {
    stream << (const Object&)*(mArray[i]);
  }
}

uint32_t Array::getLength() const {
  return mArray.size();
}

const Object* Array::getElement(uint32_t u32Pos) const
  throw(OutOfBoundException) {
  if (u32Pos >= mArray.size())
    throw OutOfBoundException("Array");
  else
    return mArray[u32Pos];
}

void Array::pushElement(const Object *objPtr) {
  mArray.push_back(objPtr);
}

ostream& operator << (ostream &stream,
  const Array &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Array &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Array &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Array &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Array &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Array &obj) throw(ObjectCreationException, IOException) {
  obj.read(stream);
  return stream;
}
