#ifndef STRING_H
#define STRING_H

#include "Object.h"

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
    const String &obj);
  friend Connection& operator >> (Connection &stream,
    String &obj);

  String(const String &other);
  String& operator = (const String &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream);
  virtual void write(Connection &stream) const;

  std::string mstrValue;

public:
  String();
  String(const std::string &strValue);
  ~String();

  virtual String* clone() const;

  const std::string& getValue() const;

  void callWrite(Connection &stream) const;

  static const String mProto;

protected:
};

#endif // STRING_H
