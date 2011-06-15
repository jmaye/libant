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

#ifndef BOOLEANARRAY_H
#define BOOLEANARRAY_H

#include "Object.h"
#include "OutOfBoundException.h"
#include "IOException.h"

#include <iosfwd>
#include <vector>

#include <stdint.h>

class Connection;

class BooleanArray : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const BooleanArray &obj);
  friend std::istream& operator >> (std::istream &stream,
    BooleanArray &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const BooleanArray &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    BooleanArray &obj);
  friend Connection& operator << (Connection &stream,
    const BooleanArray &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    BooleanArray &obj) throw(IOException);

  BooleanArray(const BooleanArray &other);
  BooleanArray& operator = (const BooleanArray &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream) throw(IOException);
  virtual void write(Connection &stream) const throw(IOException);

  std::vector<bool> mArray;

public:
  BooleanArray();
  ~BooleanArray();

  virtual BooleanArray* clone() const;

  uint32_t getLength() const;

  bool getElement(uint32_t u32Pos) const throw(OutOfBoundException);

  void pushElement(bool bValue);

  static const BooleanArray mProto;

protected:
};

#endif // BOOLEANARRAY_H
