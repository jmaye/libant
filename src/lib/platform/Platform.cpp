#include "Platform.h"

#include "String.h"
#include "Float64.h"
#include "Float64Array.h"
#include "Array.h"
#include "Boolean.h"
#include "Int32Array.h"
#include "CallResult.h"
#include "StringArray.h"
#include "Struct.h"

#include <iostream>
#include <fstream>

using namespace std;

Platform::Platform(const string &strHost, uint32_t u32Port)
  : Connection(strHost, u32Port) {
}

Platform::~Platform() {
}

void Platform::read(istream &stream) {
}

void Platform::write(ostream &stream) const {
}

void Platform::read(ifstream &stream) {
}

void Platform::write(ofstream &stream) const {
}

void Platform::login(const string &strUser, const string &strPwd)
  throw(IOException, RemoteException, TypeCastException,
  ObjectCreationException) {
  String procString("login");
  String userString(strUser);
  String pwdString(strPwd);
  Array argsArray;
  argsArray.pushElement(userString.clone());
  argsArray.pushElement(pwdString.clone());
  const Object *result = call(procString, argsArray);
  delete result;
}

void Platform::watchdogReset(double f64Interval) throw(IOException,
  RemoteException, TypeCastException, ObjectCreationException) {
  String procString("Watchdog.reset");
  Float64 intervalFloat64(f64Interval);
  Array argsArray;
  argsArray.pushElement(intervalFloat64.clone());
  const Object *result = call(procString, argsArray);
  delete result;
}

void Platform::motionSetSpeed(double f64Sd, double f64Thetad) throw(IOException,
  RemoteException, TypeCastException, ObjectCreationException) {
  String procString("Motion.setSpeed");
  Float64 sdFloat64(f64Sd);
  Float64 thetadFloat64(f64Thetad);
  Array argsArray;
  argsArray.pushElement(sdFloat64.clone());
  argsArray.pushElement(thetadFloat64.clone());
  const Object *result = call(procString, argsArray);
  delete result;
}

Speed Platform::motionGetSpeed() throw(IOException, RemoteException,
  TypeCastException, ObjectCreationException, OutOfBoundException) {
  String procString("Motion.getSpeed");
  Array argsArray;
  const Object *result = call(procString, argsArray);
  const Float64Array &speedFloat64Array = 
    result->typeCast<CallResult>().getObject()->typeCast<Float64Array>();
  Speed speed;
  speed.f64Time        = speedFloat64Array.getElement(0);
  speed.f64Translation = speedFloat64Array.getElement(1);
  speed.f64Rotation    = speedFloat64Array.getElement(2);
  delete result;
  return speed;
}

Status Platform::motionGetStatus() throw(IOException, RemoteException,
  TypeCastException, ObjectCreationException, OutOfBoundException) {
  String procString("Motion.getStatus");
  Array argsArray;
  const Object *result = call(procString, argsArray);
  const Array &statusArray = 
    result->typeCast<CallResult>().getObject()->typeCast<Array>();
  Status status;
  status.f64Time   = statusArray.getElement(0)->typeCast<Float64>().getValue();
  status.strState  = statusArray.getElement(1)->typeCast<String>().getValue();
  status.strResult = statusArray.getElement(2)->typeCast<String>().getValue();
  delete result;
  return status;
}

void Platform::motionStop() throw(IOException, RemoteException,
  TypeCastException, ObjectCreationException) {
  String procString("Motion.stop");
  Array argsArray;
  const Object *result = call(procString, argsArray);
  delete result;
}

void Platform::motionStop(bool bForce) throw(IOException, RemoteException,
  TypeCastException, ObjectCreationException) {
  String procString("Motion.stop");
  Boolean forceBoolean(bForce);
  Array argsArray;
  argsArray.pushElement(forceBoolean.clone());
  const Object *result = call(procString, argsArray);
  delete result;
}

void Platform::motionTurn(double f64Angle) throw(IOException, RemoteException,
  TypeCastException, ObjectCreationException) {
  String procString("Motion.turn");
  Float64 angleFloat64(f64Angle);
  Array argsArray;
  argsArray.pushElement(angleFloat64.clone());
  const Object *result = call(procString, argsArray);
  delete result;
}

void Platform::motionTurn(double f64Angle, bool bAbsolute) throw(IOException,
  RemoteException, TypeCastException, ObjectCreationException) {
  String procString("Motion.turn");
  Float64 angleFloat64(f64Angle);
  Boolean absBoolean(bAbsolute);
  Array argsArray;
  argsArray.pushElement(angleFloat64.clone());
  argsArray.pushElement(absBoolean.clone());
  const Object *result = call(procString, argsArray);
  delete result;
}

void Platform::motionMoveToPose(double f64X, double f64Y, double f64Theta)
  throw(IOException, RemoteException, TypeCastException,
  ObjectCreationException) {
  String procString("Motion.moveToPose");
  Float64 xFloat64(f64X);
  Float64 yFloat64(f64Y);
  Float64 thetaFloat64(f64Theta);
  Array argsArray;
  argsArray.pushElement(xFloat64.clone());
  argsArray.pushElement(yFloat64.clone());
  argsArray.pushElement(thetaFloat64.clone());
  const Object *result = call(procString, argsArray);
  delete result;
}

void Platform::motionMoveToPose(double f64X, double f64Y, double f64Theta,
  bool bBackward) throw(IOException, RemoteException, TypeCastException,
  ObjectCreationException) {
  String procString("Motion.moveToPose");
  Float64 xFloat64(f64X);
  Float64 yFloat64(f64Y);
  Float64 thetaFloat64(f64Theta);
  Boolean backBoolean(bBackward);
  Array argsArray;
  argsArray.pushElement(xFloat64.clone());
  argsArray.pushElement(yFloat64.clone());
  argsArray.pushElement(thetaFloat64.clone());
  argsArray.pushElement(backBoolean.clone());
  const Object *result = call(procString, argsArray);
  delete result;
}

Pose Platform::odometryGetPose()
  throw(IOException, RemoteException, TypeCastException,
  ObjectCreationException, OutOfBoundException) {
  String procString("Odometry.getPose");
  Array argsArray;
  const Object *result = call(procString, argsArray);
  const Float64Array &odoFloat64Array =
    result->typeCast<CallResult>().getObject()->typeCast<Array>().getElement(1)
    ->typeCast<Float64Array>();
  Pose pose;
  pose.f64Time = result->typeCast<CallResult>().getObject()
    ->typeCast<Array>().getElement(0)->typeCast<Float64>().getValue();
  pose.f64X           = odoFloat64Array.getElement(0);
  pose.f64Y           = odoFloat64Array.getElement(1);
  pose.f64Angle       = odoFloat64Array.getElement(2);
  pose.f64XVar        = odoFloat64Array.getElement(3);
  pose.f64YVar        = odoFloat64Array.getElement(4);
  pose.f64AngleVar    = odoFloat64Array.getElement(5);
  pose.f64XYCoVar     = odoFloat64Array.getElement(6);
  pose.f64XAngleCoVar = odoFloat64Array.getElement(7);
  pose.f64YAngleCoVar = odoFloat64Array.getElement(8);
  delete result;
  return pose;
}

Pose Platform::odometryGetPose(double f64Time)
  throw(IOException, RemoteException, TypeCastException,
  ObjectCreationException, OutOfBoundException) {
  String procString("Odometry.getPose");
  Float64 timeFloat64(f64Time);
  Array argsArray;
  argsArray.pushElement(timeFloat64.clone());
  const Object *result = call(procString, argsArray);
  const Float64Array &odoFloat64Array =
    result->typeCast<CallResult>().getObject()->typeCast<Array>().getElement(1)
    ->typeCast<Float64Array>();
  Pose pose;
  pose.f64Time = result->typeCast<CallResult>().getObject()
    ->typeCast<Array>().getElement(0)->typeCast<Float64>().getValue();
  pose.f64X           = odoFloat64Array.getElement(0);
  pose.f64Y           = odoFloat64Array.getElement(1);
  pose.f64Angle       = odoFloat64Array.getElement(2);
  pose.f64XVar        = odoFloat64Array.getElement(3);
  pose.f64YVar        = odoFloat64Array.getElement(4);
  pose.f64AngleVar    = odoFloat64Array.getElement(5);
  pose.f64XYCoVar     = odoFloat64Array.getElement(6);
  pose.f64XAngleCoVar = odoFloat64Array.getElement(7);
  pose.f64YAngleCoVar = odoFloat64Array.getElement(8);
  delete result;
  return pose;
}

void Platform::odometryUpdate(Pose pose) throw(IOException, RemoteException,
  TypeCastException, ObjectCreationException) {
  String procString("Odometry.update");
  Float64 timeFloat64(pose.f64Time);
  Float64Array poseFloat64Array;
  poseFloat64Array.pushElement(pose.f64X);
  poseFloat64Array.pushElement(pose.f64Y);
  poseFloat64Array.pushElement(pose.f64Angle);
  poseFloat64Array.pushElement(pose.f64XVar);
  poseFloat64Array.pushElement(pose.f64YVar);
  poseFloat64Array.pushElement(pose.f64AngleVar);
  poseFloat64Array.pushElement(pose.f64XYCoVar);
  poseFloat64Array.pushElement(pose.f64XAngleCoVar);
  poseFloat64Array.pushElement(pose.f64YAngleCoVar);
  Array argsArray;
  argsArray.pushElement(timeFloat64.clone());
  argsArray.pushElement(poseFloat64Array.clone());
  const Object *result = call(procString, argsArray);
  delete result;
}

Version Platform::version() throw(IOException, RemoteException,
  TypeCastException, ObjectCreationException, OutOfBoundException) {
  String procString("version");
  Array argsArray;
  const Object *result = call(procString, argsArray);
  const Int32Array &verInt32Array =
    result->typeCast<CallResult>().getObject()->typeCast<Int32Array>();
  Version ver;
  ver.i32Major = verInt32Array.getElement(0);
  ver.i32Minor = verInt32Array.getElement(1);
  delete result;
  return ver;
}

void Platform::testCrash() throw(IOException, RemoteException,
  TypeCastException, ObjectCreationException) {
  String procString("Test.crash");
  Array argsArray;
  const Object *result = call(procString, argsArray);
  delete result;
}

double Platform::testNop() throw(IOException, RemoteException,
  TypeCastException, ObjectCreationException) {
  String procString("Test.nop");
  Array argsArray;
  const Object *result = call(procString, argsArray);
  double f64Res = result->typeCast<CallResult>().getObject()
    ->typeCast<Float64>().getValue();
  delete result;
  return f64Res;
}

void Platform::testThrow(const string &strName, const string &strMessage)
  throw(IOException, RemoteException, TypeCastException,
  ObjectCreationException) {
  String procString("Test.throw");
  String nameString(strName);
  String msgString(strMessage);
  Array argsArray;
  argsArray.pushElement(nameString.clone());
  argsArray.pushElement(msgString.clone());
  const Object *result = call(procString, argsArray);
  delete result;
}

vector<string> Platform::getCalls() throw(IOException, RemoteException,
  TypeCastException, ObjectCreationException, OutOfBoundException) {
  String procString("getCalls");
  Array argsArray;
  const Object *result = call(procString, argsArray);
  vector<string> strVector;
  const StringArray &callsStringArray =
    result->typeCast<CallResult>().getObject()->typeCast<StringArray>();
  uint32_t u32Length = callsStringArray.getLength();
  for (uint32_t i = 0; i < u32Length; i++)
    strVector.push_back(callsStringArray.getElement(i));
  delete result;
  return strVector;
}

RawOdometry Platform::getRawOdometry() throw(IOException, RemoteException,
  TypeCastException, ObjectCreationException, OutOfBoundException) {
  String procString("inspect");
  StringArray stringArray;
  stringArray.pushElement("OdometryPipe");
  Array argsArray;
  argsArray.pushElement(stringArray.clone());
  const Object *result = call(procString, argsArray);
  const Float64Array &float64Ticks = result->typeCast<CallResult>().getObject()
    ->typeCast<Struct>().getObject("OdometryPipe")
    ->typeCast<Struct>().getObject("data")
    ->typeCast<Struct>().getObject("rows")->typeCast<Float64Array>();
  uint32_t u32ArrayLength = float64Ticks.getLength();
  RawOdometry rawOdometry;
  rawOdometry.f64Time  = float64Ticks.getElement(u32ArrayLength - 3);
  rawOdometry.f64Left  = float64Ticks.getElement(u32ArrayLength - 2);
  rawOdometry.f64Right = float64Ticks.getElement(u32ArrayLength - 1);
  delete result;
  return rawOdometry;
}

ostream& operator << (ostream &stream,
  const Platform &obj) {
  obj.write(stream);
  return stream;
}

istream& operator >> (istream &stream,
  Platform &obj) {
  obj.read(stream);
  return stream;
}

ofstream& operator << (ofstream &stream,
  const Platform &obj) {
  obj.write(stream);
  return stream;
}

ifstream& operator >> (ifstream &stream,
  Platform &obj) {
  obj.read(stream);
  return stream;
}
