#ifndef REMOTEEXCEPTION_H
#define REMOTEEXCEPTION_H

#include <stdexcept>
#include <string>

class RemoteException : public std::runtime_error {
  RemoteException& operator = (const RemoteException &other);

public:
  RemoteException(const std::string &msg = "");
  RemoteException(const RemoteException &other);

protected:

};

#endif // REMOTEEXCEPTION_H
