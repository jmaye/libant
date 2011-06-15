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

#include "CallResult.h"

#include "Connection.h"
#include "TypesFactory.h"

#include <iostream>
#include <fstream>

using namespace std;

const CallResult CallResult::mProto;

CallResult::CallResult() : Object(0x13),
                           mObjectPtr(0) {
}

CallResult::CallResult(const CallResult &other) : Object(other) {
}

CallResult::~CallResult() {
  if (mObjectPtr != 0)
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

void CallResult::read(Connection &stream)
  throw(ObjectCreationException, IOException) {
  uint8_t u8TypeID;
  stream >> u8TypeID;
  mObjectPtr = TypesFactory::createObject(u8TypeID);
  stream >> (Object&)*mObjectPtr;
}

void CallResult::write(Connection &stream) const throw(IOException) {
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
  const CallResult &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  CallResult &obj) throw(ObjectCreationException, IOException) {
  obj.read(stream);
  return stream;
}
