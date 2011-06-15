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

#ifndef STRING_H
#define STRING_H

#include "Object.h"
#include "IOException.h"

#include <iosfwd>
#include <string>

class Connection;

class String : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const String &obj);
  friend std::istream& operator >> (std::istream &stream,
    String &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const String &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    String &obj);
  friend Connection& operator << (Connection &stream,
    const String &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    String &obj) throw(IOException);

  String(const String &other);
  String& operator = (const String &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream) throw(IOException);
  virtual void write(Connection &stream) const throw(IOException);

  std::string mstrValue;

public:
  String();
  String(const std::string &strValue);
  ~String();

  virtual String* clone() const;

  const std::string& getValue() const;

  void callWrite(Connection &stream) const throw(IOException);

  static const String mProto;

protected:
};

#endif // STRING_H
