#include "Int32.h"
#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const Int32 Int32::mProto;

Int32::Int32() : Object(0x07) {
}

Int32::Int32(int32_t s32Value) : Object(mProto),
                                 ms32Value(s32Value) {
}

Int32::Int32(const Int32 &other) : Object(other),
                                   ms32Value(other.ms32Value) {
}

Int32::~Int32() {
}

void Int32::read(istream &stream) {
}

void Int32::write(ostream &stream) const {
}

void Int32::read(ifstream &stream) {
}

void Int32::write(ofstream &stream) const {
}

void Int32::read(Connection &stream) {
  stream >> ms32Value;
}

void Int32::write(Connection &stream) const {
  stream << mu8TypeID << ms32Value;
}

Int32* Int32::clone() const {
  return new Int32(*this);
}

int32_t Int32::getValue() const {
  return ms32Value;
}

ostream& operator << (ostream &stream,
  const Int32 &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Int32 &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Int32 &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Int32 &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Int32 &obj) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Int32 &obj) {
  obj.read(stream);
  return stream;
}
