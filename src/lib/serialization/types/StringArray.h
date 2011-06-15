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

#ifndef STRINGARRAY_H
#define STRINGARRAY_H

#include "Object.h"
#include "OutOfBoundException.h"
#include "IOException.h"

#include <iosfwd>
#include <vector>
#include <string>

#include <stdint.h>

class Connection;

class StringArray : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const StringArray &obj);
  friend std::istream& operator >> (std::istream &stream,
    StringArray &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const StringArray &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    StringArray &obj);
  friend Connection& operator << (Connection &stream,
    const StringArray &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    StringArray &obj) throw(IOException);

  StringArray(const StringArray &other);
  StringArray& operator = (const StringArray &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream) throw(IOException);
  virtual void write(Connection &stream) const throw(IOException);

  std::vector<std::string> mArray;

public:
  StringArray();
  ~StringArray();

  virtual StringArray* clone() const;

  uint32_t getLength() const;

  const std::string& getElement(uint32_t u32Pos) const
    throw(OutOfBoundException);

  void pushElement(const std::string &strValue);

  static const StringArray mProto;

protected:
};

#endif // STRINGARRAY_H
