//-----------------------------------------------------------------------
//  Simple Qt4/VTK Viewer.
//  A basic example of the usage of QVTKWidget2 in Qt4 and
//  VTK7.1 with C++11
//  Copyright (C) 2017  Edson Contreras Cardenas

//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//-----------------------------------------------------------------------

#ifndef MYVTKAPPLICATION_H
#define MYVTKAPPLICATION_H

#include <QApplication>
#include <QObject>

class MyVTKApplication : public QApplication
{
  Q_OBJECT
public:
  MyVTKApplication(int& argc, char** argv, bool isGUI = true);
  virtual ~MyVTKApplication();

protected slots:
  void cleanPlotsOnExit();
};

#endif // MYVTKAPPLICATION_H
