/******************************************************************************
 * Copyright (C) 2011 by Jerome Maye                                          *
 * jerome.maye@gmail.com                                                      *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

#include "Platform.h"

#include <iostream>

#include <stdlib.h>

using namespace std;

int main(int argc, char **argv) {
  if (argc != 3) {
    cerr << "Usage: " << argv[0] << " <IP> <Port>" << endl;
    return -1;
  }
  Platform proxy(argv[1], atoi(argv[2]));
  proxy.open();
  Version ver = proxy.version();
  cout << "LOS version is: " << ver.i32Major << "." << ver.i32Minor << endl;
  return 0;
}
