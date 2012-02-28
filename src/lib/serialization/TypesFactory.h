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

#ifndef TYPESFACTORY_H
#define TYPESFACTORY_H

#include "ObjectCreationException.h"

#include <map>

#include <stdint.h>

class Object;

class TypesFactory {
  std::map<uint8_t, const Object*> mTypesMap;

  TypesFactory();

public:
  static void registerType(const Object *objPtr, uint8_t u8TypeID);

  static Object* createObject(uint8_t u8TypeID) throw(ObjectCreationException);

  static TypesFactory& getInstance();

protected:

};

#endif // TYPESFACTORY_H
