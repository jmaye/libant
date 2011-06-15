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

#ifndef INT32ARRAY_H
#define INT32ARRAY_H

#include "Object.h"
#include "OutOfBoundException.h"
#include "IOException.h"

#include <iosfwd>
#include <vector>

#include <stdint.h>

class Connection;

class Int32Array : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Int32Array &obj);
  friend std::istream& operator >> (std::istream &stream,
    Int32Array &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Int32Array &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Int32Array &obj);
  friend Connection& operator << (Connection &stream,
    const Int32Array &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    Int32Array &obj) throw(IOException);

  Int32Array(const Int32Array &other);
  Int32Array& operator = (const Int32Array &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream) throw(IOException);
  virtual void write(Connection &stream) const throw(IOException);

  std::vector<int32_t> mArray;

public:
  Int32Array();
  ~Int32Array();

  virtual Int32Array* clone() const;

  uint32_t getLength() const;

  int32_t getElement(uint32_t u32Pos) const throw(OutOfBoundException);

  void pushElement(int32_t i32Value);

  static const Int32Array mProto;

protected:
};

#endif // INT32ARRAY_H
