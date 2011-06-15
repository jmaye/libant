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

#ifndef FLOAT64_H
#define FLOAT64_H

#include "Object.h"
#include "IOException.h"

#include <iosfwd>

class Connection;

class Float64 : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Float64 &obj);
  friend std::istream& operator >> (std::istream &stream,
    Float64 &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Float64 &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Float64 &obj);
  friend Connection& operator << (Connection &stream,
    const Float64 &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    Float64 &obj) throw(IOException);

  Float64();
  Float64(const Float64 &other);
  Float64& operator = (const Float64 &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream) throw(IOException);
  virtual void write(Connection &stream) const throw(IOException);

  double mf64Value;

public:
  Float64(double f64Value);
  ~Float64();

  virtual Float64* clone() const;

  double getValue() const;

  static const Float64 mProto;

protected:

};

#endif // FLOAT64_H
