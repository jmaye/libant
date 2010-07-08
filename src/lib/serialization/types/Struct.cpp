#include "Struct.h"

#include "String.h"

#include <iostream>
#include <fstream>

using namespace std;

const Struct Struct::mProto;

Struct::Struct() : Object(0x15) {
}

Struct::Struct(const Struct &other) : Object(other) {
}

Struct::~Struct() {
  std::map<const String*, const Object*>::const_iterator it;
  for (it = mStructMap.begin(); it != mStructMap.end(); it++) {
    delete (*it).first;
    delete (*it).second;
  }
}

void Struct::read(istream &stream) {
}

void Struct::write(ostream &stream) const {
}

void Struct::read(ifstream &stream) {
}

void Struct::write(ofstream &stream) const {
}

void Struct::read(Connection &stream) {
}

void Struct::write(Connection &stream) const {
}

Struct* Struct::clone() const {
  return new Struct(*this);
}

ostream& operator << (ostream &stream,
  const Struct &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Struct &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Struct &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Struct &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Struct &obj) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Struct &obj) {
  obj.read(stream);
  return stream;
}
