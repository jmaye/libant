#include "Int16.h"
#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const Int16 Int16::mProto;

Int16::Int16() : Object(0x05) {
}

Int16::Int16(int16_t s16Value) : Object(mProto),
                                 ms16Value(s16Value) {
}

Int16::Int16(const Int16 &other) : Object(other),
                                   ms16Value(other.ms16Value) {
}

Int16::~Int16() {
}

void Int16::read(istream &stream) {
}

void Int16::write(ostream &stream) const {
}

void Int16::read(ifstream &stream) {
}

void Int16::write(ofstream &stream) const {
}

void Int16::read(Connection &stream) {
  stream >> ms16Value;
}

void Int16::write(Connection &stream) const {
  stream << mu8TypeID << ms16Value;
}

Int16* Int16::clone() const {
  return new Int16(*this);
}

int16_t Int16::getValue() const {
  return ms16Value;
}

ostream& operator << (ostream &stream,
  const Int16 &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Int16 &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Int16 &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Int16 &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Int16 &obj) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Int16 &obj) {
  obj.read(stream);
  return stream;
}
