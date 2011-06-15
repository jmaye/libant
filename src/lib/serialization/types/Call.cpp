/******************************************************************************
 * Copyright (C) 2011 by Jerome Maye                                          *
 * jerome.maye@gmail.com                                                      *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

#include "Call.h"

#include "Connection.h"
#include "String.h"
#include "Array.h"

#include <iostream>
#include <fstream>

using namespace std;

const Call Call::mProto;

Call::Call() : Object(0x12),
               mProcStrPtr(0),
               mArgsArrayPtr(0) {
}

Call::Call(const String *procStrPtr, const Array *argsArrayPtr)
  : Object(mProto),
    mProcStrPtr(procStrPtr),
    mArgsArrayPtr(argsArrayPtr) {
}

Call::Call(const Call &other) : Object(other) {
}

Call::~Call() {
  if (mProcStrPtr != 0)
    delete mProcStrPtr;
  if (mArgsArrayPtr != 0)
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

void Call::read(Connection &stream) throw(IOException) {
}

void Call::write(Connection &stream) const throw(IOException) {
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
  const Call &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Call &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
