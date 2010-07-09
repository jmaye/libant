#include "Float64.h"

#include "Connection.h"

#include <iostream>
#include <fstream>

#include <stdint.h>

using namespace std;

const Float64 Float64::mProto;

Float64::Float64() : Object(0x0d),
                     mf64Value(0) {
}

Float64::Float64(double f64Value) : Object(mProto),
                                    mf64Value(f64Value) {
}

Float64::Float64(const Float64 &other) : Object(other),
                                         mf64Value(other.mf64Value) {
}

Float64::~Float64() {
}

void Float64::read(istream &stream) {
}

void Float64::write(ostream &stream) const {
}

void Float64::read(ifstream &stream) {
}

void Float64::write(ofstream &stream) const {
}

void Float64::read(Connection &stream) throw(IOException) {
  stream >> mf64Value;
}

void Float64::write(Connection &stream) const throw(IOException) {
  stream << mu8TypeID << mf64Value;
}

Float64* Float64::clone() const {
  return new Float64(*this);
}

double Float64::getValue() const {
  return mf64Value;
}

ostream& operator << (ostream &stream,
  const Float64 &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Float64 &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Float64 &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Float64 &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Float64 &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Float64 &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
