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

#include "Void.h"

#include "Connection.h"
#include "IOException.h"

#include <iostream>
#include <fstream>

using namespace std;

const Void Void::mProto;

Void::Void() : Object(0x00) {
}

Void::Void(const Void &other) : Object(other) {
}

Void::~Void() {
}

void Void::read(istream &stream) {
}

void Void::write(ostream &stream) const {
}

void Void::read(ifstream &stream) {
}

void Void::write(ofstream &stream) const {
}

void Void::read(Connection &stream) throw(IOException) {
}

void Void::write(Connection &stream) const throw(IOException) {
  stream << mu8TypeID;
}

Void* Void::clone() const {
  return new Void(*this);
}

ostream& operator << (ostream &stream,
  const Void &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Void &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Void &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Void &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Void &obj) throw(IOException) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Void &obj) throw(IOException) {
  obj.read(stream);
  return stream;
}
