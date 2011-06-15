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

#include "Boolean.h"

#include "Connection.h"

#include <iostream>
#include <fstream>

#include <stdint.h>

using namespace std;

const Boolean Boolean::mProto;

Boolean::Boolean() : Object(0x01),
                     mbValue(false) {
}

Boolean::Boolean(bool bValue) : Object(mProto),
                                mbValue(bValue) {
}

Boolean::Boolean(const Boolean &other) : Object(other),
                                         mbValue(other.mbValue) {
}

Boolean::~Boolean() {
}

void Boolean::read(istream &stream) {
}

void Boolean::write(ostream &stream) const {
}

void Boolean::read(ifstream &stream) {
}

void Boolean::write(ofstream &stream) const {
}

void Boolean::read(Connection &stream) throw(IOException) {
  uint8_t u8Value;
  stream >> u8Value;
  (u8Value == 1) ? mbValue = true : mbValue = false;
}

void Boolean::write(Connection &stream) const throw(IOException) {
  stream << mu8TypeID;
  (mbValue == true) ? stream << (uint8_t)1 : stream << (uint8_t)0;
}

Boolean* Boolean::clone() const {
  return new Boolean(*this);
}

bool Boolean::getValue() const {
  return mbValue;
}

ostream& operator << (ostream &stream,
  const Boolean &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Boolean &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Boolean &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Boolean &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Boolean &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Boolean &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
