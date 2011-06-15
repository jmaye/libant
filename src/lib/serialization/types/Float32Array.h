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

#ifndef FLOAT32ARRAY_H
#define FLOAT32ARRAY_H

#include "Object.h"
#include "OutOfBoundException.h"
#include "IOException.h"

#include <iosfwd>
#include <vector>

#include <stdint.h>

class Connection;

class Float32Array : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Float32Array &obj);
  friend std::istream& operator >> (std::istream &stream,
    Float32Array &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Float32Array &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Float32Array &obj);
  friend Connection& operator << (Connection &stream,
    const Float32Array &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    Float32Array &obj) throw(IOException);

  Float32Array(const Float32Array &other);
  Float32Array& operator = (const Float32Array &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream) throw(IOException);
  virtual void write(Connection &stream) const throw(IOException);

  std::vector<float> mArray;

public:
  Float32Array();
  ~Float32Array();

  virtual Float32Array* clone() const;

  uint32_t getLength() const;

  float getElement(uint32_t u32Pos) const throw(OutOfBoundException);

  void pushElement(float f32Value);

  static const Float32Array mProto;

protected:
};

#endif // FLOAT32ARRAY_H
