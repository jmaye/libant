#include "Float32.h"

#include "Connection.h"

#include <iostream>
#include <fstream>

#include <stdint.h>

using namespace std;

const Float32 Float32::mProto;

Float32::Float32() : Object(0x0b),
                     mf32Value(0) {
}

Float32::Float32(float f32Value) : Object(mProto),
                                   mf32Value(f32Value) {
}

Float32::Float32(const Float32 &other) : Object(other),
                                         mf32Value(other.mf32Value) {
}

Float32::~Float32() {
}

void Float32::read(istream &stream) {
}

void Float32::write(ostream &stream) const {
}

void Float32::read(ifstream &stream) {
}

void Float32::write(ofstream &stream) const {
}

void Float32::read(Connection &stream) {
  stream >> mf32Value;
}

void Float32::write(Connection &stream) const {
  stream << mu8TypeID << mf32Value;
}

Float32* Float32::clone() const {
  return new Float32(*this);
}

float Float32::getValue() const {
  return mf32Value;
}

ostream& operator << (ostream &stream,
  const Float32 &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Float32 &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Float32 &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Float32 &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Float32 &obj) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Float32 &obj) {
  obj.read(stream);
  return stream;
}
