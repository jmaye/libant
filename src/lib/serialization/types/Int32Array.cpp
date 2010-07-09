#include "Int32Array.h"

#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const Int32Array Int32Array::mProto;

Int32Array::Int32Array() : Object(0x08) {
}

Int32Array::Int32Array(const Int32Array &other) : Object(other) {
  uint32_t u32Length = other.mArray.size();
  for (uint32_t i = 0; i < u32Length; i++)
    mArray.push_back(other.mArray[i]);
}

Int32Array::~Int32Array() {
}

void Int32Array::read(istream &stream) {
}

void Int32Array::write(ostream &stream) const {
}

void Int32Array::read(ifstream &stream) {
}

void Int32Array::write(ofstream &stream) const {
}

void Int32Array::read(Connection &stream) throw(IOException) {
  uint32_t u32Length;
  stream >> u32Length;
  for (uint32_t i = 0; i < u32Length; i++) {
    int32_t i32Value;
    stream >> i32Value;
    mArray.push_back(i32Value);
  }
}

void Int32Array::write(Connection &stream) const throw(IOException){
  uint32_t u32Length = mArray.size();
  stream << mu8TypeID << u32Length;
  for (uint32_t i = 0; i < u32Length; i++) {
    stream << mArray[i];
  }
}

Int32Array* Int32Array::clone() const {
  return new Int32Array(*this);
}

uint32_t Int32Array::getLength() const {
  return mArray.size();
}

int32_t Int32Array::getElement(uint32_t u32Pos) const
  throw(OutOfBoundException){
  if (u32Pos >= mArray.size())
    throw OutOfBoundException("Int32Array");
  else
    return mArray[u32Pos];
}

void Int32Array::pushElement(int32_t i32Value) {
  mArray.push_back(i32Value);
}

ostream& operator << (ostream &stream,
  const Int32Array &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Int32Array &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Int32Array &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Int32Array &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Int32Array &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Int32Array &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
