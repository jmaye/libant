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

#include "Int64.h"

#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const Int64 Int64::mProto;

Int64::Int64() : Object(0x09),
                 ms64Value(0) {
}

Int64::Int64(int64_t s64Value) : Object(mProto),
                                 ms64Value(s64Value) {
}

Int64::Int64(const Int64 &other) : Object(other),
                                   ms64Value(other.ms64Value) {
}

Int64::~Int64() {
}

void Int64::read(istream &stream) {
}

void Int64::write(ostream &stream) const {
}

void Int64::read(ifstream &stream) {
}

void Int64::write(ofstream &stream) const {
}

void Int64::read(Connection &stream) throw(IOException) {
  stream >> ms64Value;
}

void Int64::write(Connection &stream) const throw(IOException) {
  stream << mu8TypeID << ms64Value;
}

Int64* Int64::clone() const {
  return new Int64(*this);
}

int64_t Int64::getValue() const {
  return ms64Value;
}

ostream& operator << (ostream &stream,
  const Int64 &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Int64 &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Int64 &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Int64 &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Int64 &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Int64 &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
