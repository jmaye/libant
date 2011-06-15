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

void String::read(Connection &stream) throw(IOException) {
  uint32_t u32Length;
  stream >> u32Length;

  for (uint32_t i = 0; i < u32Length; i++) {
    uint8_t u8Byte;
    stream >> u8Byte;
    mstrValue.push_back(u8Byte);
  }
}

void String::write(Connection &stream) const throw(IOException) {
  uint32_t u32Length = mstrValue.length();
  stream << mu8TypeID << u32Length << mstrValue;
}

String* String::clone() const {
  return new String(*this);
}

const string& String::getValue() const {
  return mstrValue;
}

void String::callWrite(Connection &stream) const throw(IOException) {
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
  const String &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  String &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
