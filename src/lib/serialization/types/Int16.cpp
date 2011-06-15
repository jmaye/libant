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

#include "Int16.h"

#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const Int16 Int16::mProto;

Int16::Int16() : Object(0x05),
                 ms16Value(0) {
}

Int16::Int16(int16_t s16Value) : Object(mProto),
                                 ms16Value(s16Value) {
}

Int16::Int16(const Int16 &other) : Object(other),
                                   ms16Value(other.ms16Value) {
}

Int16::~Int16() {
}

void Int16::read(istream &stream) {
}

void Int16::write(ostream &stream) const {
}

void Int16::read(ifstream &stream) {
}

void Int16::write(ofstream &stream) const {
}

void Int16::read(Connection &stream) throw(IOException) {
  stream >> ms16Value;
}

void Int16::write(Connection &stream) const throw(IOException) {
  stream << mu8TypeID << ms16Value;
}

Int16* Int16::clone() const {
  return new Int16(*this);
}

int16_t Int16::getValue() const {
  return ms16Value;
}

ostream& operator << (ostream &stream,
  const Int16 &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Int16 &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Int16 &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Int16 &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Int16 &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Int16 &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
