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

#ifndef INT64_H
#define INT64_H

#include "Object.h"
#include "IOException.h"

#include <iosfwd>

#include <stdint.h>

class Connection;

class Int64 : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Int64 &obj);
  friend std::istream& operator >> (std::istream &stream,
    Int64 &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Int64 &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Int64 &obj);
  friend Connection& operator << (Connection &stream,
    const Int64 &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    Int64 &obj) throw(IOException);

  Int64();
  Int64(const Int64 &other);
  Int64& operator = (const Int64 &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream) throw(IOException);
  virtual void write(Connection &stream) const throw(IOException);

  int64_t ms64Value;

public:
  Int64(int64_t s64Value);
  ~Int64();

  virtual Int64* clone() const;

  int64_t getValue() const;

  static const Int64 mProto;

protected:

};

#endif // INT64_H
