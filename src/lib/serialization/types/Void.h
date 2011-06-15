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

#ifndef VOID_H
#define VOID_H

#include "Object.h"
#include "IOException.h"

#include <iosfwd>

class Connection;

class Void : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const Void &obj);
  friend std::istream& operator >> (std::istream &stream,
    Void &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Void &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Void &obj);
  friend Connection& operator << (Connection &stream,
    const Void &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    Void &obj) throw(IOException);

  Void(const Void &other);
  Void& operator = (const Void &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream) throw(IOException);
  virtual void write(Connection &stream) const throw(IOException);

public:
  Void();
  ~Void();

  virtual Void* clone() const;

  static const Void mProto;

protected:
};

#endif // VOID_H
