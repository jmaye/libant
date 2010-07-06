#include "CallResult.h"
#include "Connection.h"
#include "TypesFactory.h"

#include <iostream>
#include <fstream>

using namespace std;

const CallResult CallResult::mProto;

CallResult::CallResult() : Object(0x13) {
}

CallResult::CallResult(const CallResult &other) : Object(other) {
}

CallResult::~CallResult() {
  delete mObjectPtr;
}

void CallResult::read(istream &stream) {
}

void CallResult::write(ostream &stream) const {
}

void CallResult::read(ifstream &stream) {
}

void CallResult::write(ofstream &stream) const {
}

void CallResult::read(Connection &stream) {
  uint8_t u8TypeID;
  stream >> u8TypeID;
  mObjectPtr = TypesFactory::createObject(u8TypeID);
  stream >> (Object&)*mObjectPtr;
}

void CallResult::write(Connection &stream) const {
}

CallResult* CallResult::clone() const {
  return new CallResult(*this);
}

const Object* CallResult::getObject() const {
  return mObjectPtr;
}

ostream& operator << (ostream &stream,
  const CallResult &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  CallResult &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const CallResult &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  CallResult &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const CallResult &obj) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  CallResult &obj) {
  obj.read(stream);
  return stream;
}
