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

#ifndef CALLEXCEPTION_H
#define CALLEXCEPTION_H

#include "Object.h"
#include "ObjectCreationException.h"
#include "IOException.h"

#include <iosfwd>

class Connection;
class String;

class CallException : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const CallException &obj);
  friend std::istream& operator >> (std::istream &stream,
    CallException &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const CallException &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    CallException &obj);
  friend Connection& operator << (Connection &stream,
    const CallException &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    CallException &obj) throw(ObjectCreationException, IOException);

  CallException();
  CallException(const CallException &other);
  CallException& operator = (const CallException &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream)
    throw(ObjectCreationException, IOException);
  virtual void write(Connection &stream) const throw(IOException);

  const String *mNameStrPtr;
  const String *mMsgStrPtr;
  const Object *mObjectPtr;

public:
  ~CallException();

  virtual CallException* clone() const;

  const String* getNameStrPtr() const;

  const String* getMsgStrPtr() const;

  const Object* getObjectPtr() const;

  static const CallException mProto;

protected:

};

#endif // CALLEXCEPTION_H
