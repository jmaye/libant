#ifndef TYPESFACTORY_H
#define TYPESFACTORY_H

#include "ObjectCreationException.h"

#include <map>

#include <stdint.h>

class Object;

class TypesFactory {
  static std::map<uint8_t, const Object*> mTypesMap;

  TypesFactory();

public:
  static void registerType(const Object *objPtr, uint8_t u8TypeID);

  static Object* createObject(uint8_t u8TypeID) throw(ObjectCreationException);

  static TypesFactory& getInstance();

protected:

};

#endif // TYPESFACTORY_H
