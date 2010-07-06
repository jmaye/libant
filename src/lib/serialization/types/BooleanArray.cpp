#include "BooleanArray.h"
#include "Connection.h"

#include <iostream>
#include <fstream>

using namespace std;

const BooleanArray BooleanArray::mProto;

BooleanArray::BooleanArray() : Object(0x02) {
}

BooleanArray::BooleanArray(const BooleanArray &other) : Object(other) {
  uint32_t u32Length = other.mArray.size();
  for (uint32_t i = 0; i < u32Length; i++)
    mArray.push_back(other.mArray[i]);
}

BooleanArray::~BooleanArray() {
}

void BooleanArray::read(istream &stream) {
}

void BooleanArray::write(ostream &stream) const {
}

void BooleanArray::read(ifstream &stream) {
}

void BooleanArray::write(ofstream &stream) const {
}

void BooleanArray::read(Connection &stream) {
  uint32_t u32Length;
  stream >> u32Length;

  for (uint32_t i = 0; i < u32Length; i += 8) {
    uint8_t u8Byte;
    stream >> u8Byte;
    for (uint32_t j = 0; j < 8; j++) {
      if ((i + j) < u32Length) 
        (u8Byte & (0x01 << j)) ? mArray.push_back(true) :
          mArray.push_back(false);
      else
        break;
    }
  }
}

void BooleanArray::write(Connection &stream) const {
  uint32_t u32Length = mArray.size();
  stream << mu8TypeID << u32Length;

  for (uint32_t i = 0; i < u32Length; i += 8) {
    uint8_t u8Byte = 0;
    for (uint32_t j = 0; j < 8; j++) {
      if ((i + j) < u32Length)
        u8Byte |= ((mArray[i + j] == true) ? 0x01 : 0x00) << j;
      else
        break;
    }
    stream << u8Byte;
  }
}

BooleanArray* BooleanArray::clone() const {
  return new BooleanArray(*this);
}

uint32_t BooleanArray::getLength() const {
  return mArray.size();
}

bool BooleanArray::getElement(uint32_t u32Pos) const
  throw(OutOfBoundException) {
  if (u32Pos >= mArray.size())
    throw OutOfBoundException("BooleanArray");
  else
    return mArray[u32Pos];
}

void BooleanArray::pushElement(bool bValue) {
  mArray.push_back(bValue);
}

ostream& operator << (ostream &stream,
  const BooleanArray &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  BooleanArray &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const BooleanArray &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  BooleanArray &obj) {
  obj.read(stream);
  return stream;
}

Connection& operator << (Connection &stream,
  const BooleanArray &obj) {
  obj.write(stream);
  return stream;
}

Connection& operator >> (Connection &stream,
  BooleanArray &obj) {
  obj.read(stream);
  return stream;
}
