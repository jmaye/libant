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

#ifndef ARRAY_H
#define ARRAY_H

#include "Object.h"
#include "OutOfBoundException.h"
#include "ObjectCreationException.h"
#include "IOException.h"

#include <iosfwd>
#include <vector>

#include <stdint.h>

class Connection;

class Array : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Array &obj);
  friend std::istream& operator >> (std::istream &stream,
    Array &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Array &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Array &obj);
  friend Connection& operator << (Connection &stream,
    const Array &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    Array &obj) throw(ObjectCreationException, IOException);

  Array(const Array &other);
  Array& operator = (const Array &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream)
    throw(ObjectCreationException, IOException);
  virtual void write(Connection &stream) const throw(IOException);

  std::vector<const Object*> mArray;

public:
  Array();
  ~Array();

  virtual Array* clone() const;

  void callWrite(Connection &stream) const throw(IOException);

  uint32_t getLength() const;

  const Object* getElement(uint32_t u32Pos) const throw(OutOfBoundException);

  void pushElement(const Object *objPtr);

  static const Array mProto;

protected:

};

#endif // ARRAY_H
