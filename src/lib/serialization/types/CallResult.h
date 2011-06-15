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

#ifndef CALLRESULT_H
#define CALLRESULT_H

#include "Object.h"
#include "ObjectCreationException.h"
#include "IOException.h"

#include <iosfwd>

class Connection;

class CallResult : public Object {
  friend std::ostream& operator << (std::ostream &stream,
    const CallResult &obj);
  friend std::istream& operator >> (std::istream &stream,
    CallResult &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const CallResult &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    CallResult &obj);
  friend Connection& operator << (Connection &stream,
    const CallResult &obj) throw(IOException);
  friend Connection& operator >> (Connection &stream,
    CallResult &obj) throw(ObjectCreationException, IOException);

  CallResult();
  CallResult(const CallResult &other);
  CallResult& operator = (const CallResult &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream)
    throw(ObjectCreationException, IOException);
  virtual void write(Connection &stream) const throw(IOException);

  const Object *mObjectPtr;

public:
  ~CallResult();

  virtual CallResult* clone() const;

  const Object* getObject() const;

  static const CallResult mProto;

protected:
};

#endif // CALLRESULT_H
