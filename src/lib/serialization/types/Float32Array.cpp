#include "Float32Array.h"
#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const Float32Array Float32Array::mProto;

Float32Array::Float32Array() : Object(0x0c) {
}

Float32Array::Float32Array(const Float32Array &other) : Object(other) {
  uint32_t u32Length = other.mArray.size();
  for (uint32_t i = 0; i < u32Length; i++)
    mArray.push_back(other.mArray[i]);
}

Float32Array::~Float32Array() {
}

void Float32Array::read(istream &stream) {
}

void Float32Array::write(ostream &stream) const {
}

void Float32Array::read(ifstream &stream) {
}

void Float32Array::write(ofstream &stream) const {
}

void Float32Array::read(Connection &stream) {
  uint32_t u32Length;
  stream >> u32Length;
  for (uint32_t i = 0; i < u32Length; i++) {
    float f32Value;
    stream >> f32Value;
    mArray.push_back(f32Value);
  }
}

void Float32Array::write(Connection &stream) const {
  uint32_t u32Length = mArray.size();
  stream << mu8TypeID << u32Length;
  for (uint32_t i = 0; i < u32Length; i++) {
    stream << mArray[i];
  }
}

Float32Array* Float32Array::clone() const {
  return new Float32Array(*this);
}

uint32_t Float32Array::getLength() const {
  return mArray.size();
}

float Float32Array::getElement(uint32_t u32Pos) const
  throw(OutOfBoundException) {
  if (u32Pos >= mArray.size())
    throw OutOfBoundException("Float32Array");
  else
    return mArray[u32Pos];
}

void Float32Array::pushElement(float f32Value) {
  mArray.push_back(f32Value);
}

ostream& operator << (ostream &stream,
  const Float32Array &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Float32Array &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Float32Array &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Float32Array &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Float32Array &obj) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Float32Array &obj) {
  obj.read(stream);
  return stream;
}
