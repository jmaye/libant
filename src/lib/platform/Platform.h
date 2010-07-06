#ifndef PLATFORM_H
#define PLATFORM_H

#include "Connection.h"
#include "IOException.h"
#include "RemoteException.h"
#include "TypeCastException.h"
#include "ObjectCreationException.h"
#include "OutOfBoundException.h"

#include <iosfwd>
#include <string>
#include <vector>

#include <stdint.h>

struct Version {
  int32_t i32Major;
  int32_t i32Minor;
};

struct Speed {
  double f64Time;
  double f64Translation;
  double f64Rotation;
};

struct Status {
  double f64Time;
  std::string strState;
  std::string strResult;
};

struct Pose {
  double f64Time;
  double f64X;
  double f64Y;
  double f64Angle;
  double f64XVar;
  double f64YVar;
  double f64AngleVar;
  double f64XYCoVar;
  double f64XAngleCoVar;
  double f64YAngleCoVar;
};

class Platform : public Connection {
  friend std::ostream& operator << (std::ostream &stream,
    const Platform &obj);
  friend std::istream& operator >> (std::istream &stream,
    Platform &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Platform &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Platform &obj);

  Platform(const Platform &other);
  Platform& operator = (const Platform &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;

public:
  Platform(const std::string &strHost, uint32_t u32Port);
  ~Platform();

  void login(const std::string &strUser, const std::string &strPwd)
    throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException);

  void watchdogReset(double f64Interval) throw(IOException, RemoteException,
    TypeCastException, ObjectCreationException);

  Version version() throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException, OutOfBoundException);

  void motionSetSpeed(double f64Sd, double f64Thetad) throw(IOException,
    RemoteException, TypeCastException, ObjectCreationException);

  Speed motionGetSpeed() throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException, OutOfBoundException);

  Status motionGetStatus() throw(IOException, RemoteException,
    TypeCastException, ObjectCreationException, OutOfBoundException);

  void motionStop() throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException);

  void motionStop(bool bForce) throw(IOException, RemoteException,
    TypeCastException, ObjectCreationException);

  void motionTurn(double f64Angle) throw(IOException, RemoteException,
    TypeCastException, ObjectCreationException);

  void motionTurn(double f64Angle, bool bAbsolute) throw(IOException,
    RemoteException, TypeCastException, ObjectCreationException);

  void motionMoveToPose(double f64X, double f64Y, double f64Theta)
    throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException);

  void motionMoveToPose(double f64X, double f64Y, double f64Theta,
    bool bBackward) throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException);

  Pose odometryGetPose() throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException, OutOfBoundException);

  Pose odometryGetPose(double f64Time) throw(IOException, RemoteException,
    TypeCastException, ObjectCreationException, OutOfBoundException);

  void odometryUpdate(Pose pose) throw(IOException, RemoteException,
    TypeCastException, ObjectCreationException);

  void testCrash() throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException);

  double testNop() throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException);

  void testThrow(std::string strName, std::string strMessage) throw(IOException,
    RemoteException, TypeCastException, ObjectCreationException);

  std::vector<std::string> getCalls() throw(IOException, RemoteException,
    TypeCastException, ObjectCreationException, OutOfBoundException);

protected:

};

#endif // PLATFORM_H
