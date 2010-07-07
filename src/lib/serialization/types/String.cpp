#include "String.h"

#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const String String::mProto;

String::String() : Object(0x0f) {
}

String::String(const string &strValue) : Object(mProto),
                                         mstrValue(strValue) {
}

String::String(const String &other) : Object(other),
                                      mstrValue(other.mstrValue) {
}

String::~String() {
}

void String::read(istream &stream) {
}

void String::write(ostream &stream) const {
}

void String::read(ifstream &stream) {
}

void String::write(ofstream &stream) const {
}

void String::read(Connection &stream) {
  uint32_t u32Length;
  stream >> u32Length;

  for (uint32_t i = 0; i < u32Length; i++) {
    uint8_t u8Byte;
    stream >> u8Byte;
    mstrValue.push_back(u8Byte);
  }
}

void String::write(Connection &stream) const {
  uint32_t u32Length = mstrValue.length();
  stream << mu8TypeID << u32Length << mstrValue;
}

String* String::clone() const {
  return new String(*this);
}

const string& String::getValue() const {
  return mstrValue;
}

void String::callWrite(Connection &stream) const {
  uint32_t u32Length = mstrValue.length();
  stream << u32Length << mstrValue;
}

ostream& operator << (ostream &stream,
  const String &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  String &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const String &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  String &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const String &obj) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  String &obj) {
  obj.read(stream);
  return stream;
}
