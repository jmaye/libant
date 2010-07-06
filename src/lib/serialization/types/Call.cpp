#include "Call.h"
#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const Call Call::mProto;

Call::Call() : Object(0x12) {
}

Call::Call(const String *procStrPtr, const Array *argsArrayPtr)
  : Object(mProto),
    mProcStrPtr(procStrPtr),
    mArgsArrayPtr(argsArrayPtr) {
}

Call::Call(const Call &other) : Object(other) {
}

Call::~Call() {
  delete mProcStrPtr;
  delete mArgsArrayPtr;
}

void Call::read(istream &stream) {
}

void Call::write(ostream &stream) const {
}

void Call::read(ifstream &stream) {
}

void Call::write(ofstream &stream) const {
}

void Call::read(Connection &stream) {
}

void Call::write(Connection &stream) const {
  stream << mu8TypeID;
  mProcStrPtr->callWrite(stream);
  mArgsArrayPtr->callWrite(stream);
}

Call* Call::clone() const {
  return new Call(*this);
}

const String* Call::getProcStrPtr() const {
  return mProcStrPtr;
}

const Array* Call::getArgsArrayPtr() const {
  return mArgsArrayPtr;
}

ostream& operator << (ostream &stream,
  const Call &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Call &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Call &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Call &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Call &obj) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Call &obj) {
  obj.read(stream);
  return stream;
}
