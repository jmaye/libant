#include "TypesFactory.h"

#include <iostream>

using namespace std;

map<uint8_t, const Object*> TypesFactory::mTypesMap;

TypesFactory::TypesFactory() {
}

TypesFactory& TypesFactory::getInstance() {
  static TypesFactory instance;
  return instance;
}

void TypesFactory::registerType(const Object *objPtr, uint8_t u8TypeID) {
  if (mTypesMap.find(u8TypeID) == mTypesMap.end())
    mTypesMap[u8TypeID] = objPtr;
}

Object* TypesFactory::createObject(uint8_t u8TypeID)
  throw(ObjectCreationException)
{
  if (mTypesMap.find(u8TypeID) != mTypesMap.end())
    return mTypesMap[u8TypeID]->clone();
  else
    throw ObjectCreationException("TypesFactory: Unknown object ID");
}
