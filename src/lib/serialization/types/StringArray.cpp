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

void StringArray::read(Connection &stream) throw(IOException) {
  uint32_t u32Length;

  stream >> u32Length;
  for (uint32_t i = 0; i < u32Length; i++) {
    string str;
    stream >> str;
    mArray.push_back(str);
  }
}

void StringArray::write(Connection &stream) const throw(IOException) {
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
  const StringArray &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  StringArray &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
