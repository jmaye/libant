#include "Connection.h"

#include "Object.h"
#include "Void.h"
#include "Call.h"
#include "CallResult.h"
#include "CallException.h"
#include "Array.h"
#include "String.h"
#include "TypesFactory.h"

#include <iostream>
#include <fstream>

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>
#include <fcntl.h>

using namespace std;

Connection::Connection(const string &strHost, uint32_t u32Port,
  double f64Timeout)
 : mstrHost(strHost),
   mu32Port(u32Port),
   mf64Timeout(f64Timeout),
   mi32Socket(0) {
}

Connection::~Connection() {
  doClose();
}

const string& Connection::getHost() const {
  return mstrHost;
}

uint32_t Connection::getPort() const {
  return mu32Port;
}

void Connection::setTimeout(double f64Time) {
  mf64Timeout = f64Time;
}

void Connection::open() throw(IOException) {
  doOpen();
}

void Connection::close() throw(IOException) {
  doClose();
}

bool Connection::isOpen() const {
  return (mi32Socket != 0);
}

const Object* Connection::call(const String &procStr, const Array &argsArray)
  throw(IOException, RemoteException, TypeCastException,
  ObjectCreationException) {
  Call callObject(procStr.clone(), argsArray.clone());
  const Object *result = sendRequest(callObject);
  if (result->instanceof<CallResult>() == false) {
    doClose();
    if (result->instanceof<CallException>() == false) {
      delete result;
      throw IOException("call: Invalid result type");
    }
    else {
      const string nameStr =
        result->typeCast<CallException>().getNameStrPtr()->getValue();
      const string msgStr =
        result->typeCast<CallException>().getMsgStrPtr()->getValue();
      delete result;
      throw RemoteException(nameStr + ": " + msgStr);
    }
  }
  return result;
}

void Connection::ping() throw(IOException, RemoteException, TypeCastException,
  ObjectCreationException) {
  Void voidObject;
  const Object *result = sendRequest(voidObject);
  if (result->instanceof<Void>() == false) {
    doClose();
    if (result->instanceof<CallException>() == false) {
      delete result;
      throw IOException("ping: Invalid result type");
    }
    else {
      const string nameStr =
        result->typeCast<CallException>().getNameStrPtr()->getValue();
      const string msgStr =
        result->typeCast<CallException>().getMsgStrPtr()->getValue();
      delete result;
      throw RemoteException(nameStr + ": " + msgStr);
    }
  }
  delete result;
}

void Connection::doOpen() throw(IOException) {
  mi32Socket = socket(AF_INET, SOCK_STREAM, 0);
  if (mi32Socket == -1)
    throw IOException("doOpen: Socket creation failed");

  struct sockaddr_in server;
  memset(&server, 0, sizeof(struct sockaddr_in));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(mstrHost.c_str());
  server.sin_port = htons(mu32Port);
  int32_t i32Res = connect(mi32Socket, (struct sockaddr*)&server,
    sizeof(server));
  if (i32Res == -1)
    throw IOException("doOpen: Socket connection failed");
}

void Connection::doClose() throw(IOException) {
  if (mi32Socket != 0) {
    int32_t i32Res = ::close(mi32Socket);
    if (i32Res == -1)
      throw IOException("doClose: Socket closing failed");
  }
  mi32Socket = 0;
}

const Object* Connection::sendRequest(const Object &object)
  throw(IOException, ObjectCreationException) {
  if(mi32Socket == 0)
    doOpen();

  *this << object;

  uint8_t u8TypeID;
  *this >> u8TypeID;

  Object *objRead = TypesFactory::createObject(u8TypeID);

  *this >> *objRead;

  return objRead;
}

void Connection::writeBuffer(uint8_t *au8Buffer, uint32_t u32NbBytes)
  const throw(IOException) {
  fd_set writeFlags;
  struct timeval waitd;
  waitd.tv_sec = floor(mf64Timeout);
  waitd.tv_usec = 0;
  FD_ZERO(&writeFlags);
  FD_SET(mi32Socket, &writeFlags);
  int32_t i32Res = select(mi32Socket + 1, (fd_set*)0, &writeFlags,
    (fd_set*)0, &waitd);
  if(i32Res < 0)
    throw IOException("writeBuffer: Write select failed");
  if (FD_ISSET(mi32Socket, &writeFlags)) {
    FD_CLR(mi32Socket, &writeFlags);
    if (::write(mi32Socket, au8Buffer, u32NbBytes) != u32NbBytes)
      throw IOException("writeBuffer: Write failed");
  }
  else
    throw IOException("writeBuffer: Write timeout");
}

uint8_t Connection::readByte() const throw(IOException) {
  fd_set readFlags;
  struct timeval waitd;
  waitd.tv_sec = floor(mf64Timeout);
  waitd.tv_usec = 0;
  FD_ZERO(&readFlags);
  FD_SET(mi32Socket, &readFlags);
  int32_t i32Res = select(mi32Socket + 1, &readFlags, (fd_set*)0,
    (fd_set*)0, &waitd);
  if(i32Res < 0)
    throw IOException("readByte: Read select failed");
  uint8_t u8Byte;
  if (FD_ISSET(mi32Socket, &readFlags)) {
    FD_CLR(mi32Socket, &readFlags);
    if (::read(mi32Socket, &u8Byte, 1) == -1)
      throw IOException("readByte: Read failed");
  }
  else
    throw IOException("readByte: Read timeout");
  return u8Byte;
}

void Connection::read(istream &stream) {
}

void Connection::write(ostream &stream) const {
}

void Connection::read(ifstream &stream) {
}

void Connection::write(ofstream &stream) const {
}

ostream& operator << (ostream &stream,
  const Connection &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Connection &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Connection &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Connection &obj) {
  obj.read(stream);
  return stream;
}

Connection& Connection::operator << (int8_t i8Value) throw(IOException) {
  writeBuffer((uint8_t*)&i8Value, 1);
  return *this;
}

Connection& Connection::operator << (uint8_t u8Value) throw(IOException) {
  writeBuffer(&u8Value, 1);
  return *this;
}

Connection& Connection::operator << (int16_t i16Value) throw(IOException) {
  writeBuffer((uint8_t*)&i16Value, 2);
  return *this;
}

Connection& Connection::operator << (int32_t i32Value) throw(IOException) {
  writeBuffer((uint8_t*)&i32Value, 4);
  return *this;
}

Connection& Connection::operator << (uint32_t u32Value) throw(IOException) {
  writeBuffer((uint8_t*)&u32Value, 4);
  return *this;
}

Connection& Connection::operator << (int64_t i64Value) throw(IOException) {
  writeBuffer((uint8_t*)&i64Value, 8);
  return *this;
}

Connection& Connection::operator << (const string &strValue)
  throw(IOException) {
  writeBuffer((uint8_t*)strValue.c_str(), strValue.length());
  return *this;
}

Connection& Connection::operator << (float f32Value) throw(IOException) {
  writeBuffer((uint8_t*)&f32Value, 4);
  return *this;
}

Connection& Connection::operator << (double f64Value) throw(IOException) {
  writeBuffer((uint8_t*)&f64Value, 8);
  return *this;
}

Connection& Connection::operator >> (int8_t &i8Value) throw(IOException) {
  i8Value = (int8_t)readByte();
  return *this;
}

Connection& Connection::operator >> (uint8_t &u8Value) throw(IOException) {
  u8Value = readByte();
  return *this;
}

Connection& Connection::operator >> (int16_t &i16Value) throw(IOException) {
  ((uint8_t*)&i16Value)[0] = readByte();
  ((uint8_t*)&i16Value)[1] = readByte();
  return *this;
}

Connection& Connection::operator >> (int32_t &i32Value) throw(IOException) {
  ((uint8_t*)&i32Value)[0] = readByte();
  ((uint8_t*)&i32Value)[1] = readByte();
  ((uint8_t*)&i32Value)[2] = readByte();
  ((uint8_t*)&i32Value)[3] = readByte();
  return *this;
}

Connection& Connection::operator >> (uint32_t &u32Value) throw(IOException) {
  ((uint8_t*)&u32Value)[0] = readByte();
  ((uint8_t*)&u32Value)[1] = readByte();
  ((uint8_t*)&u32Value)[2] = readByte();
  ((uint8_t*)&u32Value)[3] = readByte();
  return *this;
}

Connection& Connection::operator >> (int64_t &i64Value) throw(IOException) {
  ((uint8_t*)&i64Value)[0] = readByte();
  ((uint8_t*)&i64Value)[1] = readByte();
  ((uint8_t*)&i64Value)[2] = readByte();
  ((uint8_t*)&i64Value)[3] = readByte();
  ((uint8_t*)&i64Value)[4] = readByte();
  ((uint8_t*)&i64Value)[5] = readByte();
  ((uint8_t*)&i64Value)[6] = readByte();
  ((uint8_t*)&i64Value)[7] = readByte();
  return *this;
}

Connection& Connection::operator >> (std::string &strValue) throw(IOException) {
  uint32_t u32Length;
  ((uint8_t*)&u32Length)[0] = readByte();
  ((uint8_t*)&u32Length)[1] = readByte();
  ((uint8_t*)&u32Length)[2] = readByte();
  ((uint8_t*)&u32Length)[3] = readByte();
  for (uint32_t i = 0; i < u32Length; i++)
    strValue.push_back(readByte());
  return *this;
}

Connection& Connection::operator >> (float &f32Value) throw(IOException) {
  ((uint8_t*)&f32Value)[0] = readByte();
  ((uint8_t*)&f32Value)[1] = readByte();
  ((uint8_t*)&f32Value)[2] = readByte();
  ((uint8_t*)&f32Value)[3] = readByte();
  return *this;
}

Connection& Connection::operator >> (double &f64Value) throw(IOException) {
  ((uint8_t*)&f64Value)[0] = readByte();
  ((uint8_t*)&f64Value)[1] = readByte();
  ((uint8_t*)&f64Value)[2] = readByte();
  ((uint8_t*)&f64Value)[3] = readByte();
  ((uint8_t*)&f64Value)[4] = readByte();
  ((uint8_t*)&f64Value)[5] = readByte();
  ((uint8_t*)&f64Value)[6] = readByte();
  ((uint8_t*)&f64Value)[7] = readByte();
  return *this;
}
