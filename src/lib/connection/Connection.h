#ifndef CONNECTION_H
#define CONNECTION_H

#include "Object.h"
#include "IOException.h"
#include "RemoteException.h"
#include "Array.h"
#include "String.h"

#include <iosfwd>
#include <string>

#include <stdint.h>

class Connection {
  friend std::ostream& operator << (std::ostream &stream,
    const Connection &obj);
  friend std::istream& operator >> (std::istream &stream,
    Connection &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Connection &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Connection &obj);

  Connection(const Connection &other);
  Connection& operator = (const Connection &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;

  void doOpen() throw(IOException);

  void doClose() throw(IOException);

  const Object* sendRequest(const Object &object) throw(IOException);

  void writeBuffer(uint8_t *au8Buffer, uint32_t u32NbBytes)
    const throw(IOException);

  uint8_t readByte() const throw(IOException);

  std::string mstrHost;
  uint32_t mu32Port;
  double mf64Timeout;
  int32_t mi32Socket;

public:
  Connection(const std::string &strHost, uint32_t u32Port,
    double f64Timeout = 2.5);
  ~Connection();

  const std::string& getHost() const;

  uint32_t getPort() const;

  void setTimeout(double f64Time);

  void open() throw(IOException);

  void close() throw(IOException);

  bool isOpen() const;

  const Object* call(const String &procStr, const Array &argsArray)
    throw(IOException);

  void ping() throw(IOException);

  Connection& operator << (int8_t i8Value);
  Connection& operator << (uint8_t u8Value);
  Connection& operator << (int16_t i16Value);
  Connection& operator << (int32_t i32Value);
  Connection& operator << (uint32_t u32Value);
  Connection& operator << (int64_t i64Value);
  Connection& operator << (const std::string &strValue);
  Connection& operator << (float f32Value);
  Connection& operator << (double f64Value);

  Connection& operator >> (int8_t &i8Value);
  Connection& operator >> (uint8_t &u8Value);
  Connection& operator >> (int16_t &i16Value);
  Connection& operator >> (int32_t &i32Value);
  Connection& operator >> (uint32_t &u32Value);
  Connection& operator >> (int64_t &i64Value);
  Connection& operator >> (std::string &strValue);
  Connection& operator >> (float &f32Value);
  Connection& operator >> (double &f64Value);

protected:

};

#endif // CONNECTION_H
