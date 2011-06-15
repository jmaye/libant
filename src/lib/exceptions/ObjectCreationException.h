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

#ifndef OBJECTCREATIONEXCEPTION_H
#define OBJECTCREATIONEXCEPTION_H

#include <stdexcept>
#include <string>

class ObjectCreationException : public std::range_error {
  ObjectCreationException& operator = (const ObjectCreationException &other);

public:
  ObjectCreationException(const std::string &msg = "");
  ObjectCreationException(const ObjectCreationException &other);

protected:

};

#endif // OBJECTCREATIONEXCEPTION_H
