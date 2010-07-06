#include "Int64.h"
#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const Int64 Int64::mProto;

Int64::Int64() : Object(0x09) {
}

Int64::Int64(int64_t s64Value) : Object(mProto),
                                 ms64Value(s64Value) {
}

Int64::Int64(const Int64 &other) : Object(other),
                                   ms64Value(other.ms64Value) {
}

Int64::~Int64() {
}

void Int64::read(istream &stream) {
}

void Int64::write(ostream &stream) const {
}

void Int64::read(ifstream &stream) {
}

void Int64::write(ofstream &stream) const {
}

void Int64::read(Connection &stream) {
  stream >> ms64Value;
}

void Int64::write(Connection &stream) const {
  stream << mu8TypeID << ms64Value;
}

Int64* Int64::clone() const {
  return new Int64(*this);
}

int64_t Int64::getValue() const {
  return ms64Value;
}

ostream& operator << (ostream &stream,
  const Int64 &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Int64 &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Int64 &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Int64 &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Int64 &obj) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Int64 &obj) {
  obj.read(stream);
  return stream;
}
