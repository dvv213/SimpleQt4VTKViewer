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

#include "Geometry.h"

#include <vtkAlgorithmOutput.h>
#include <vtkPassThrough.h>
#include <vtkPolyData.h>
#include <vtkCubeSource.h>
//#include <vtkSphereSource.h>

Geometry::Geometry(QObject *parent) : QObject(parent)
{
  m_inputFilter = vtkSmartPointer<vtkPassThrough>::New();
  m_data = vtkSmartPointer<vtkPolyData>::New();

//  double center[3] = { -5.0, -5.0, 5.0 };
  double center[3] = { 0.0, 0.0, 0.0 };
  m_data->ShallowCopy(CreateGeometryData(center));

  m_inputFilter->SetInputData(m_data);
}

vtkSmartPointer<vtkPolyData> Geometry::CreateGeometryData(double center[3])
{
  // Create a cube
  vtkSmartPointer<vtkCubeSource> cubeSource =
    vtkSmartPointer<vtkCubeSource>::New();
  cubeSource->SetCenter(center);
  cubeSource->SetBounds(
    -0.5, 0.5,
    -0.5, 0.5,
    -0.5, 0.5);

//  // Create a sphere
//  vtkSmartPointer<vtkCubeSource> cubeSource =
//    vtkSmartPointer<vtkCubeSource>::New();
//  sphereSource->SetRadius(3.0);
//  sphereSource->SetPhiResolution(20);
//  sphereSource->SetThetaResolution(20);

  cubeSource->Update();

  vtkSmartPointer<vtkPolyData> data =
    vtkSmartPointer<vtkPolyData>::New();

  data->ShallowCopy(cubeSource->GetOutput());
  return data;
}

vtkAlgorithmOutput* Geometry::getGeometryConection()
{
  m_inputFilter->Update();
  return m_inputFilter->GetOutputPort();
}

vtkPolyData* Geometry::getGeometryData()
{
  m_inputFilter->Update();

  return vtkPolyData::SafeDownCast( m_inputFilter->GetOutput() );
}

void Geometry::setNewCenter(double center[3])
{
  m_data->ShallowCopy(CreateGeometryData(center));
}
