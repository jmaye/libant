#ifndef CALLRESULT_H
#define CALLRESULT_H

#include "Object.h"

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
    const CallResult &obj);
  friend Connection& operator >> (Connection &stream,
    CallResult &obj);

  CallResult();
  CallResult(const CallResult &other);
  CallResult& operator = (const CallResult &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;
  virtual void read(Connection &stream);
  virtual void write(Connection &stream) const;

  const Object *mObjectPtr;

public:
  ~CallResult();

  virtual CallResult* clone() const;

  const Object* getObject() const;

  static const CallResult mProto;

protected:
};

#endif // CALLRESULT_H
