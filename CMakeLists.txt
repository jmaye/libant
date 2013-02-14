cmake_minimum_required(VERSION 2.6)

include(ReMake)

remake_project(
  libant
  VERSION 1.0
  RELEASE beta
  SUMMARY "A C++ based Bluebotics ANT interfacing library"
  AUTHOR "Jerome Maye"
  CONTACT "jerome.maye@mavt.ethz.ch"
  HOME "http://aslforge.ethz.ch/projects/libant"
  LICENSE "GNU Lesser General Public License (LGPL)"
  PREFIX ant-
  INSTALL /usr/
)

remake_doc(
  html
)

remake_pack_deb()

remake_pack_deb(
  COMPONENT dev
  DESCRIPTION "Development headers"
  libant
)

remake_pack_deb(
  COMPONENT test
  DESCRIPTION "Test programs"
  libant
)

remake_pack_deb(
  COMPONENT doc
  DESCRIPTION "Documentation"
  libant
)

remake_distribute_deb(
  SECTION libs
  DISTRIBUTION lucid
  DEPENDS remake doxygen
  PASS CMAKE_BUILD_TYPE LIBANT_SUBVERSION_REVISION
  UPLOAD ppa:jmaye/ethz
)
