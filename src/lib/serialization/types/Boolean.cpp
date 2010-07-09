#include "Boolean.h"

#include "Connection.h"

#include <iostream>
#include <fstream>

#include <stdint.h>

using namespace std;

const Boolean Boolean::mProto;

Boolean::Boolean() : Object(0x01),
                     mbValue(false) {
}

Boolean::Boolean(bool bValue) : Object(mProto),
                                mbValue(bValue) {
}

Boolean::Boolean(const Boolean &other) : Object(other),
                                         mbValue(other.mbValue) {
}

Boolean::~Boolean() {
}

void Boolean::read(istream &stream) {
}

void Boolean::write(ostream &stream) const {
}

void Boolean::read(ifstream &stream) {
}

void Boolean::write(ofstream &stream) const {
}

void Boolean::read(Connection &stream) throw(IOException) {
  uint8_t u8Value;
  stream >> u8Value;
  (u8Value == 1) ? mbValue = true : mbValue = false;
}

void Boolean::write(Connection &stream) const throw(IOException) {
  stream << mu8TypeID;
  (mbValue == true) ? stream << (uint8_t)1 : stream << (uint8_t)0;
}

Boolean* Boolean::clone() const {
  return new Boolean(*this);
}

bool Boolean::getValue() const {
  return mbValue;
}

ostream& operator << (ostream &stream,
  const Boolean &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Boolean &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Boolean &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Boolean &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Boolean &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Boolean &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
