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

#include "Int64Array.h"

#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const Int64Array Int64Array::mProto;

Int64Array::Int64Array() : Object(0x0a) {
}

Int64Array::Int64Array(const Int64Array &other) : Object(other) {
  uint32_t u32Length = other.mArray.size();
  for (uint32_t i = 0; i < u32Length; i++)
    mArray.push_back(other.mArray[i]);
}

Int64Array::~Int64Array() {
}

void Int64Array::read(istream &stream) {
}

void Int64Array::write(ostream &stream) const {
}

void Int64Array::read(ifstream &stream) {
}

void Int64Array::write(ofstream &stream) const {
}

void Int64Array::read(Connection &stream) throw(IOException) {
  uint32_t u32Length;
  stream >> u32Length;
  for (uint32_t i = 0; i < u32Length; i++) {
    int64_t i64Value;
    stream >> i64Value;
    mArray.push_back(i64Value);
  }
}

void Int64Array::write(Connection &stream) const throw(IOException) {
  uint32_t u32Length = mArray.size();
  stream << mu8TypeID << u32Length;

  for (uint32_t i = 0; i < u32Length; i++) {
    stream << mArray[i];
  }
}

Int64Array* Int64Array::clone() const {
  return new Int64Array(*this);
}

uint32_t Int64Array::getLength() const {
  return mArray.size();
}

int64_t Int64Array::getElement(uint32_t u32Pos) const
  throw(OutOfBoundException) {
  if (u32Pos >= mArray.size())
    throw OutOfBoundException("Int64Array");
  else
    return mArray[u32Pos];
}

void Int64Array::pushElement(int64_t i64Value) {
  mArray.push_back(i64Value);
}

ostream& operator << (ostream &stream,
  const Int64Array &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Int64Array &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Int64Array &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Int64Array &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Int64Array &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Int64Array &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
