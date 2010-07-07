#include "StringArray.h"

#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const StringArray StringArray::mProto;

StringArray::StringArray() : Object(0x10) {
}

StringArray::StringArray(const StringArray &other) : Object(other) {
  uint32_t u32Length = other.mArray.size();
  for (uint32_t i = 0; i < u32Length; i++)
    mArray.push_back(other.mArray[i]);
}

StringArray::~StringArray() {
}

void StringArray::read(istream &stream) {
}

void StringArray::write(ostream &stream) const {
}

void StringArray::read(ifstream &stream) {
}

void StringArray::write(ofstream &stream) const {
}

void StringArray::read(Connection &stream) {
  uint32_t u32Length;

  stream >> u32Length;
  for (uint32_t i = 0; i < u32Length; i++) {
    string str;
    stream >> str;
    mArray.push_back(str);
  }
}

void StringArray::write(Connection &stream) const {
  uint32_t u32Length = mArray.size();
  stream << mu8TypeID << u32Length;

  for (uint32_t i = 0; i < u32Length; i++) {
    stream << (uint32_t)mArray[i].size() << mArray[i];
  }
}

StringArray* StringArray::clone() const {
  return new StringArray(*this);
}

uint32_t StringArray::getLength() const {
  return mArray.size();
}

const string& StringArray::getElement(uint32_t u32Pos) const
  throw(OutOfBoundException) {
  if (u32Pos >= mArray.size())
    throw OutOfBoundException("StringArray");
  else
    return mArray[u32Pos];
}

void StringArray::pushElement(const string &strValue) {
  mArray.push_back(strValue);
}

ostream& operator << (ostream &stream,
  const StringArray &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  StringArray &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const StringArray &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  StringArray &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const StringArray &obj) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  StringArray &obj) {
  obj.read(stream);
  return stream;
}
