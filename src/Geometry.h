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

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QObject>

#include <vtkSmartPointer.h>

class vtkAlgorithmOutput;
class vtkPolyData;
class vtkPassThrough;

class Geometry : public QObject
{
  Q_OBJECT
public:
  explicit Geometry(int a = 0, QObject *parent = 0);
  Geometry(Geometry&&);
  int ver=0;
  double center[3];
  vtkAlgorithmOutput* getGeometryConection();
  vtkPolyData* getGeometryData();

  void setNewCenter(double center[3], int ver);

signals:

public slots:

protected:
  static vtkSmartPointer<vtkPolyData> CreateGeometryData(double center[3], int ver);

  vtkSmartPointer<vtkPolyData>    m_data;
  vtkSmartPointer<vtkPassThrough> m_inputFilter;
};

#endif // GEOMETRY_H
