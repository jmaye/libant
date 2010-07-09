#include "Int16Array.h"

#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const Int16Array Int16Array::mProto;

Int16Array::Int16Array() : Object(0x06) {
}

Int16Array::Int16Array(const Int16Array &other) : Object(other) {
  uint32_t u32Length = other.mArray.size();
  for (uint32_t i = 0; i < u32Length; i++)
    mArray.push_back(other.mArray[i]);
}

Int16Array::~Int16Array() {
}

void Int16Array::read(istream &stream) {
}

void Int16Array::write(ostream &stream) const {
}

void Int16Array::read(ifstream &stream) {
}

void Int16Array::write(ofstream &stream) const {
}

void Int16Array::read(Connection &stream) throw(IOException) {
  uint32_t u32Length;
  stream >> u32Length;

  for (uint32_t i = 0; i < u32Length; i++) {
    int16_t i16Value;
    stream >> i16Value;
    mArray.push_back(i16Value);
  }
}

void Int16Array::write(Connection &stream) const throw(IOException) {
  uint32_t u32Length = mArray.size();
  stream << mu8TypeID << u32Length;

  for (uint32_t i = 0; i < u32Length; i++) {
    stream << mArray[i];
  }
}

Int16Array* Int16Array::clone() const {
  return new Int16Array(*this);
}

uint32_t Int16Array::getLength() const {
  return mArray.size();
}

int16_t Int16Array::getElement(uint32_t u32Pos) const
  throw(OutOfBoundException) {
  if (u32Pos >= mArray.size())
    throw OutOfBoundException("Int16Array");
  else
    return mArray[u32Pos];
}

void Int16Array::pushElement(int16_t i16Value) {
  mArray.push_back(i16Value);
}

ostream& operator << (ostream &stream,
  const Int16Array &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Int16Array &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Int16Array &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Int16Array &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Int16Array &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Int16Array &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
