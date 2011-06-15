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

#include "Int32Array.h"

#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const Int32Array Int32Array::mProto;

Int32Array::Int32Array() : Object(0x08) {
}

Int32Array::Int32Array(const Int32Array &other) : Object(other) {
  uint32_t u32Length = other.mArray.size();
  for (uint32_t i = 0; i < u32Length; i++)
    mArray.push_back(other.mArray[i]);
}

Int32Array::~Int32Array() {
}

void Int32Array::read(istream &stream) {
}

void Int32Array::write(ostream &stream) const {
}

void Int32Array::read(ifstream &stream) {
}

void Int32Array::write(ofstream &stream) const {
}

void Int32Array::read(Connection &stream) throw(IOException) {
  uint32_t u32Length;
  stream >> u32Length;
  for (uint32_t i = 0; i < u32Length; i++) {
    int32_t i32Value;
    stream >> i32Value;
    mArray.push_back(i32Value);
  }
}

void Int32Array::write(Connection &stream) const throw(IOException){
  uint32_t u32Length = mArray.size();
  stream << mu8TypeID << u32Length;
  for (uint32_t i = 0; i < u32Length; i++) {
    stream << mArray[i];
  }
}

Int32Array* Int32Array::clone() const {
  return new Int32Array(*this);
}

uint32_t Int32Array::getLength() const {
  return mArray.size();
}

int32_t Int32Array::getElement(uint32_t u32Pos) const
  throw(OutOfBoundException){
  if (u32Pos >= mArray.size())
    throw OutOfBoundException("Int32Array");
  else
    return mArray[u32Pos];
}

void Int32Array::pushElement(int32_t i32Value) {
  mArray.push_back(i32Value);
}

ostream& operator << (ostream &stream,
  const Int32Array &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Int32Array &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Int32Array &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Int32Array &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Int32Array &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Int32Array &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
