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

#ifndef FLOAT32_H
#define FLOAT32_H

#include "Object.h"
#include "IOException.h"

#include <iosfwd>

class Connection;

class Float32 : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Float32 &obj);
  friend std::istream& operator >> (std::istream &stream,
    Float32 &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Float32 &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Float32 &obj);
  friend Connection& operator << (Connection &stream,
    const Float32 &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    Float32 &obj) throw(IOException);

  Float32();
  Float32(const Float32 &other);
  Float32& operator = (const Float32 &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream) throw(IOException);
  virtual void write(Connection &stream) const throw(IOException);

  float mf32Value;

public:
  Float32(float f32Value);
  ~Float32();

  virtual Float32* clone() const;

  float getValue() const;

  static const Float32 mProto;

protected:
};

#endif // FLOAT32_H
