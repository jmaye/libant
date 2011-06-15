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

#include "Object.h"

#include "TypesFactory.h"

#include <iostream>
#include <fstream>

using namespace std;

Object::Object() throw(ObjectCreationException) : mu8TypeID(0xff) {
  throw ObjectCreationException("Wrong object");
}

Object::Object(uint8_t u8TypeID) : mu8TypeID(u8TypeID) {
  TypesFactory::getInstance().registerType(this, u8TypeID);
}

Object::Object(const Object &other) : mu8TypeID(other.mu8TypeID) {
}

Object::~Object() {
}

uint8_t Object::getTypeID() const {
  return mu8TypeID;
}

ostream& operator << (ostream &stream,
  const Object &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Object &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Object &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Object &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const Object &obj) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  Object &obj) {
  obj.read(stream);
  return stream;
}
