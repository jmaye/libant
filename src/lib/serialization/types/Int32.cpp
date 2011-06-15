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

#include "Int32.h"

#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const Int32 Int32::mProto;

Int32::Int32() : Object(0x07),
                 ms32Value(0) {
}

Int32::Int32(int32_t s32Value) : Object(mProto),
                                 ms32Value(s32Value) {
}

Int32::Int32(const Int32 &other) : Object(other),
                                   ms32Value(other.ms32Value) {
}

Int32::~Int32() {
}

void Int32::read(istream &stream) {
}

void Int32::write(ostream &stream) const {
}

void Int32::read(ifstream &stream) {
}

void Int32::write(ofstream &stream) const {
}

void Int32::read(Connection &stream) throw(IOException) {
  stream >> ms32Value;
}

void Int32::write(Connection &stream) const throw(IOException) {
  stream << mu8TypeID << ms32Value;
}

Int32* Int32::clone() const {
  return new Int32(*this);
}

int32_t Int32::getValue() const {
  return ms32Value;
}

ostream& operator << (ostream &stream,
  const Int32 &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Int32 &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Int32 &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Int32 &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Int32 &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Int32 &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
