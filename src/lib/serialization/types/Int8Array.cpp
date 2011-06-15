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

#include "Int8Array.h"

#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const Int8Array Int8Array::mProto;

Int8Array::Int8Array() : Object(0x04) {
}

Int8Array::Int8Array(const Int8Array &other) : Object(other) {
  uint32_t u32Length = other.mArray.size();
  for (uint32_t i = 0; i < u32Length; i++)
    mArray.push_back(other.mArray[i]);
}

Int8Array::~Int8Array() {
}

void Int8Array::read(istream &stream) {
}

void Int8Array::write(ostream &stream) const {
}

void Int8Array::read(ifstream &stream) {
}

void Int8Array::write(ofstream &stream) const {
}

void Int8Array::read(Connection &stream) throw(IOException) {
  uint32_t u32Length;
  stream >> u32Length;

  for (uint32_t i = 0; i < u32Length; i++) {
    int8_t i8Value;
    stream >> i8Value;
    mArray.push_back(i8Value);
  }
}

void Int8Array::write(Connection &stream) const throw(IOException) {
  uint32_t u32Length = mArray.size();
  stream << mu8TypeID << u32Length;

  for (uint32_t i = 0; i < u32Length; i++)
    stream << mArray[i];
}

Int8Array* Int8Array::clone() const {
  return new Int8Array(*this);
}

uint32_t Int8Array::getLength() const {
  return mArray.size();
}

int8_t Int8Array::getElement(uint32_t u32Pos) const
 throw(OutOfBoundException) {
  if (u32Pos >= mArray.size())
    throw OutOfBoundException("Int8Array");
  else
    return mArray[u32Pos];
}

void Int8Array::pushElement(int8_t i8Value) {
  mArray.push_back(i8Value);
}

ostream& operator << (ostream &stream,
  const Int8Array &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Int8Array &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Int8Array &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Int8Array &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Int8Array &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Int8Array &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
