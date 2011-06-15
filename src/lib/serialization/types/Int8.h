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

#ifndef INT8_H
#define INT8_H

#include "Object.h"
#include "IOException.h"

#include <iosfwd>

#include <stdint.h>

class Connection;

class Int8 : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Int8 &obj);
  friend std::istream& operator >> (std::istream &stream,
    Int8 &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Int8 &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Int8 &obj);
  friend Connection& operator << (Connection &stream,
    const Int8 &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    Int8 &obj) throw(IOException);

  Int8();
  Int8(const Int8 &other);
  Int8& operator = (const Int8 &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream) throw(IOException);
  virtual void write(Connection &stream) const throw(IOException);

  int8_t ms8Value;

public:
  Int8(int8_t s8Value);
  ~Int8();

  virtual Int8* clone() const;

  int8_t getValue() const;

  static const Int8 mProto;

protected:
};

#endif // INT8_H
