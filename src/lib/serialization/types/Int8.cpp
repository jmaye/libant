#include "Int8.h"
#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const Int8 Int8::mProto;

Int8::Int8() : Object(0x03) {
}

Int8::Int8(int8_t s8Value) : Object(mProto),
                             ms8Value(s8Value) {
}

Int8::Int8(const Int8 &other) : Object(other),
                                ms8Value(other.ms8Value) {
}

Int8::~Int8() {
}

void Int8::read(istream &stream) {
}

void Int8::write(ostream &stream) const {
}

void Int8::read(ifstream &stream) {
}

void Int8::write(ofstream &stream) const {
}

void Int8::read(Connection &stream) {
  stream >> ms8Value;
}

void Int8::write(Connection &stream) const {
  stream << mu8TypeID << ms8Value;
}

Int8* Int8::clone() const {
  return new Int8(*this);
}

int8_t Int8::getValue() const {
  return ms8Value;
}

ostream& operator << (ostream &stream,
  const Int8 &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Int8 &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Int8 &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Int8 &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Int8 &obj) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Int8 &obj) {
  obj.read(stream);
  return stream;
}
