#ifndef PLATFORM_H
#define PLATFORM_H

#include "Connection.h"

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
    throw(IOException);

  void watchdogReset(double f64Interval) throw(IOException);

  Version version() throw(IOException);

  void motionSetSpeed(double f64Sd, double f64Thetad) throw(IOException);

  Speed motionGetSpeed() throw(IOException);

  Status motionGetStatus() throw(IOException);

  void motionStop() throw(IOException);

  void motionStop(bool bForce) throw(IOException);

  void motionTurn(double f64Angle) throw(IOException);

  void motionTurn(double f64Angle, bool bAbsolute) throw(IOException);

  void motionMoveToPose(double f64X, double f64Y, double f64Theta)
    throw(IOException);

  void motionMoveToPose(double f64X, double f64Y, double f64Theta,
    bool bBackward) throw(IOException);

  Pose odometryGetPose() throw(IOException);

  Pose odometryGetPose(double f64Time) throw(IOException);

  void odometryUpdate(Pose pose) throw(IOException);

  void testCrash() throw(IOException);

  double testNop() throw(IOException);

  void testThrow(std::string strName, std::string strMessage)
    throw(IOException);

  std::vector<std::string> getCalls() throw(IOException);

protected:

};

#endif // PLATFORM_H
