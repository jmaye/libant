#include "Float64Array.h"

#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const Float64Array Float64Array::mProto;

Float64Array::Float64Array() : Object(0x0e) {
}

Float64Array::Float64Array(const Float64Array &other) : Object(other) {
  uint32_t u32Length = other.mArray.size();
  for (uint32_t i = 0; i < u32Length; i++)
    mArray.push_back(other.mArray[i]);
}

Float64Array::~Float64Array() {
}

void Float64Array::read(istream &stream) {
}

void Float64Array::write(ostream &stream) const {
}

void Float64Array::read(ifstream &stream) {
}

void Float64Array::write(ofstream &stream) const {
}

void Float64Array::read(Connection &stream) throw(IOException) {
  uint32_t u32Length;
  stream >> u32Length;

  for (uint32_t i = 0; i < u32Length; i++) {
    double f64Value;
    stream >> f64Value;
    mArray.push_back(f64Value);
  }
}

void Float64Array::write(Connection &stream) const throw(IOException) {
  uint32_t u32Length = mArray.size();
  stream << mu8TypeID << u32Length;

  for (uint32_t i = 0; i < u32Length; i++) {
    stream << mArray[i];
  }
}

Float64Array* Float64Array::clone() const {
  return new Float64Array(*this);
}

uint32_t Float64Array::getLength() const {
  return mArray.size();
}

double Float64Array::getElement(uint32_t u32Pos) const
  throw(OutOfBoundException) {
  if (u32Pos >= mArray.size())
    throw OutOfBoundException("Float64Array");
  else
    return mArray[u32Pos];
}

void Float64Array::pushElement(double f64Value) {
  mArray.push_back(f64Value);
}

ostream& operator << (ostream &stream,
  const Float64Array &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Float64Array &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Float64Array &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Float64Array &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Float64Array &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Float64Array &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
