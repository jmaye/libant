/*******************************************************************************
 * Libant -- Interface to Bluebotics platforms, implements RPC over LOS and    *
 *           most of the ANT library calls.                                    *
 * Copyright (C) 2010, Jerome Maye (jerome.maye@mavt.ethz.ch)                  *
 *                                                                             *
 * This library is free software; you can redistribute it and/or               *
 * modify it under the terms of the GNU Lesser General Public                  *
 * License as published by the Free Software Foundation; either                *
 * version 3 of the License, or (at your option) any later version.            *
 *                                                                             *
 * This library is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU           *
 * Lesser General Public License for more details.                             *
 *                                                                             *
 * You should have received a copy of the GNU Lesser General                   *
 * Public License along with this library; if not, write to the                *
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,            *
 * Boston, MA 02110-1301 USA                                                   *
 ******************************************************************************/

/** \mainpage Bluebotics ANT Platforms Driver Documentation
  * The API of the driver is located in the class Platform, where you will find
  * all the useful documentation on how to operate Bluebotics platforms.
  */

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

/** \file Platform.h
  * \brief Interface class to Bluebotics platforms
  */

/** \brief Structure defining the software version of the platform
  */
struct Version {
  int32_t i32Major; //!< Major number
  int32_t i32Minor; //!< Minor number
};

/** \brief Structure defining the speed of the platform
  */
struct Speed {
  double f64Time;        //!< Request time as absolute UTC [s]
  double f64Translation; //!< Translation speed [m/s]
  double f64Rotation;    //!< Rotation speed [rad/s]
};

/** \brief Structure defining the status of the motion subsystem
  */
struct Status {
  double f64Time;        //!< Request time as absolute UTC [s]
  std::string strState;  //!< Motion operation current state
  std::string strResult; //!< Motion operation previous state
};

/** \brief Structure defining the pose of the platform
  */
struct Pose {
  double f64Time;        //!< Request time as absolute UTC [s]
  double f64X;           //!< X coordinate [m]
  double f64Y;           //!< Y coordinate [m]
  double f64Angle;       //!< Orientation [rad]
  double f64XVar;        //!< X coordinate variance [m^2]
  double f64YVar;        //!< Y coordinate variance [m^2]
  double f64AngleVar;    //!< Orientation variance [rad^2]
  double f64XYCoVar;     //!< X-Y covariance [m^2]
  double f64XAngleCoVar; //!< X-Orientation covariance [m*rad]
  double f64YAngleCoVar; //!< Y-Orientation covariance [m*rad]
};

/** \brief Platform interface
  */
class Platform : public Connection {
  friend std::ostream& operator << (std::ostream &stream,
    const Platform &obj);
  friend std::istream& operator >> (std::istream &stream,
    Platform &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const Platform &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    Platform &obj);

  /** \brief Copy constructor
    */
  Platform(const Platform &other);

  /** \brief Assignment operator
    */
  Platform& operator = (const Platform &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream);
  virtual void write(std::ofstream &stream) const;

public:
  /** \brief Main constructor
    * \param[in] strHost IP address of the platform
    * \param[in] u32Port Port of the platform
    */
  Platform(const std::string &strHost, uint32_t u32Port);

  /** \brief Destructor
    */
  ~Platform();

  /** \brief Login on the platform
    * \param[in] strUser User name for login on the platform
    * \param[in] strPwd Password for login on the platform
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    */
  void login(const std::string &strUser, const std::string &strPwd)
    throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException);

  /** \brief Reset the watchdog counter
    * \param[in] f64Interval Value of the reset [s]
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    */
  void watchdogReset(double f64Interval) throw(IOException, RemoteException,
    TypeCastException, ObjectCreationException);

  /** \brief Get software version
    * \return Version structure
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    * \throw OutOfBoundException Try to access an array with wrong index
    */
  Version version() throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException, OutOfBoundException);

  /** \brief Set the speed of the platform
    * \param[in] f64Sd Translational velocity [m/s]
    * \param[in] f64Thetad Rotational velocity [rad/s]
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    */
  void motionSetSpeed(double f64Sd, double f64Thetad) throw(IOException,
    RemoteException, TypeCastException, ObjectCreationException);

  /** \brief Get the speed of the platform
    * \return Speed structure
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    * \throw OutOfBoundException Try to access an array with wrong index
    */
  Speed motionGetSpeed() throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException, OutOfBoundException);

  /** \brief Get motion subsystem status
    * \return Status structure
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    * \throw OutOfBoundException Try to access an array with wrong index
    */
  Status motionGetStatus() throw(IOException, RemoteException,
    TypeCastException, ObjectCreationException, OutOfBoundException);

  /** \brief Stop the platform
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    */
  void motionStop() throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException);

  /** \brief Stop the platform
    * \param[in] bForce Flag to stop the platform abruptely
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    */
  void motionStop(bool bForce) throw(IOException, RemoteException,
    TypeCastException, ObjectCreationException);

  /** \brief Turn the platform
    * \param[in] f64Angle Angle to turn [rad]
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    */
  void motionTurn(double f64Angle) throw(IOException, RemoteException,
    TypeCastException, ObjectCreationException);

  /** \brief Turn the platform
    * \param[in] f64Angle Angle to turn [rad]
    * \param[in] bAbsolute Flag for telling if the angle is absolute
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    */
  void motionTurn(double f64Angle, bool bAbsolute) throw(IOException,
    RemoteException, TypeCastException, ObjectCreationException);

  /** \brief Move platform to a given pose
    * \param[in] f64X X coordinate [m]
    * \param[in] f64Y Y coordinate [m]
    * \param[in] f64Theta Orientation [rad]
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    */
  void motionMoveToPose(double f64X, double f64Y, double f64Theta)
    throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException);

  /** \brief Move platform to a given pose
    * \param[in] f64X X coordinate [m]
    * \param[in] f64Y Y coordinate [m]
    * \param[in] f64Theta Orientation [rad]
    * \param[in] bBackward Flag for telling to go backward
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    */
  void motionMoveToPose(double f64X, double f64Y, double f64Theta,
    bool bBackward) throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException);

  /** \brief Get platform pose
    * \return Pose structure
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    * \throw OutOfBoundException Try to access an array with wrong index
    */
  Pose odometryGetPose() throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException, OutOfBoundException);

  /** \brief Get platform pose
    * \param[in] f64Time Specify pose time [s]
    * \return Pose structure
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    * \throw OutOfBoundException Try to access an array with wrong index
    */
  Pose odometryGetPose(double f64Time) throw(IOException, RemoteException,
    TypeCastException, ObjectCreationException, OutOfBoundException);

  /** \brief Update pose
    * \param[in] pose Pose structure
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    */
  void odometryUpdate(Pose pose) throw(IOException, RemoteException,
    TypeCastException, ObjectCreationException);

  /** \brief Test crash of the platform task
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    */
  void testCrash() throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException);

  /** \brief Test no operation
    * \return PI
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    */
  double testNop() throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException);

  /** \brief Test throw
    * \param[in] strName Name of remote exception
    * \param[in] strMessage Message in remote exception
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    */
  void testThrow(const std::string &strName, const std::string &strMessage)
    throw(IOException, RemoteException, TypeCastException,
    ObjectCreationException);

  /** \brief Get available RPC calls on the platform
    * \return Vector of strings
    * \throw IOException Communication failure
    * \throw RemoteException Exception occurred on the platform
    * \throw TypeCastException Platform returned unexpected type
    * \throw ObjectCreationException Failed to create returned object
    * \throw OutOfBoundException Try to access an array with wrong index
    */
  std::vector<std::string> getCalls() throw(IOException, RemoteException,
    TypeCastException, ObjectCreationException, OutOfBoundException);

protected:

};

#endif // PLATFORM_H
