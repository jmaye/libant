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

#ifndef INT8ARRAY_H
#define INT8ARRAY_H

#include "Object.h"
#include "OutOfBoundException.h"
#include "IOException.h"

#include <iosfwd>
#include <vector>

#include <stdint.h>

class Connection;

class Int8Array : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Int8Array &obj);
  friend std::istream& operator >> (std::istream &stream,
    Int8Array &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Int8Array &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Int8Array &obj);
  friend Connection& operator << (Connection &stream,
    const Int8Array &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    Int8Array &obj) throw(IOException);

  Int8Array(const Int8Array &other);
  Int8Array& operator = (const Int8Array &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream) throw(IOException);
  virtual void write(Connection &stream) const throw(IOException);

  std::vector<int8_t> mArray;

public:
  Int8Array();
  ~Int8Array();

  virtual Int8Array* clone() const;

  uint32_t getLength() const;

  int8_t getElement(uint32_t u32Pos) const throw(OutOfBoundException);

  void pushElement(int8_t i8Value);

  static const Int8Array mProto;

protected:
};

#endif // INT8ARRAY_H
