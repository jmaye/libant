#include "CallException.h"
#include "Connection.h"
#include "TypesFactory.h"

#include <iostream>
#include <fstream>

using namespace std;

const CallException CallException::mProto;

CallException::CallException() : Object(0x14) {
}

CallException::CallException(const CallException &other) : Object(other) {
}

CallException::~CallException() {
  delete mNameStrPtr;
  delete mMsgStrPtr;
  delete mObjectPtr;
}

void CallException::read(istream &stream) {
}

void CallException::write(ostream &stream) const {
}

void CallException::read(ifstream &stream) {
}

void CallException::write(ofstream &stream) const {
}

void CallException::read(Connection &stream) {
  mNameStrPtr = new String();
  stream >> (Object&)*mNameStrPtr;
  mMsgStrPtr = new String();
  stream >> (Object&)*mMsgStrPtr;
  uint8_t u8TypeID;
  stream >> u8TypeID;
  mObjectPtr = TypesFactory::createObject(u8TypeID);
  stream >> (Object&)*mObjectPtr;
}

void CallException::write(Connection &stream) const {
}

CallException* CallException::clone() const {
  return new CallException(*this);
}

const String* CallException::getNameStrPtr() const {
  return mNameStrPtr;
}

const String* CallException::getMsgStrPtr() const {
  return mMsgStrPtr;
}

const Object* CallException::getObjectPtr() const {
  return mObjectPtr;
}

ostream& operator << (ostream &stream,
  const CallException &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  CallException &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const CallException &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  CallException &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const CallException &obj) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  CallException &obj) {
  obj.read(stream);
  return stream;
}
