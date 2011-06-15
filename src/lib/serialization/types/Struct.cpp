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

#include "Struct.h"

#include "Connection.h"
#include "TypesFactory.h"
#include "String.h"

#include <iostream>
#include <fstream>

using namespace std;

const Struct Struct::mProto;

Struct::Struct() : Object(0x15) {
}

Struct::Struct(const Struct &other) : Object(other) {
  std::map<string, const Object*>::const_iterator it;
  for (it = other.mStructMap.begin(); it != other.mStructMap.end(); it++) {
    mStructMap[(*it).first] = (*it).second->clone();
  }
}

Struct::~Struct() {
  std::map<string, const Object*>::const_iterator it;
  for (it = mStructMap.begin(); it != mStructMap.end(); it++) {
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

void Struct::read(Connection &stream)
  throw(ObjectCreationException, IOException) {
  uint32_t u32Length;

  stream >> u32Length;

  for (uint32_t i = 0; i < u32Length; i++) {
    String keyString;
    stream >> keyString;
    uint8_t u8TypeID;
    stream >> u8TypeID;
    const Object *objectPtr = TypesFactory::createObject(u8TypeID);
    stream >> (Object&)*objectPtr;
    mStructMap[keyString.getValue()] = objectPtr;
  }
}

const Object* Struct::getObject(const std::string &strRequest) const
  throw(OutOfBoundException) {
  std::map<string, const Object*>::const_iterator it =
    mStructMap.find(strRequest);
  if (it == mStructMap.end())
    throw OutOfBoundException("Struct");
  else
    return (*it).second;
}

void Struct::write(Connection &stream) const throw(IOException) {
  stream << mu8TypeID;
  uint32_t u32Length = mStructMap.size();
  stream << u32Length;

  std::map<string, const Object*>::const_iterator it;
  for (it = mStructMap.begin(); it != mStructMap.end(); it++) {
    String keyString((*it).first);
    keyString.callWrite(stream);
    stream << (Object&)*(*it).second;
  }
}

Struct* Struct::clone() const {
  return new Struct(*this);
}

uint32_t Struct::getLength() const {
  return mStructMap.size();
}

void Struct::pushObject(const string &strKey, const Object *objectPtr) {
  mStructMap[strKey] = objectPtr;
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
  const Struct &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Struct &obj) throw(IOException, ObjectCreationException) {
  obj.read(stream);
  return stream;
}
