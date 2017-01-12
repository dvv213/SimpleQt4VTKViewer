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

#ifndef PLOTHD_H
#define PLOTHD_H

#include <QWidget>

#include <vtkSmartPointer.h>

#include <memory>
#include <stdlib.h>

class Geometry;

class QVTKWidget2;
class vtkRenderer;

class PlotHD : public QWidget
{
    Q_OBJECT
public:
    explicit PlotHD(QWidget *parent = 0);

    void addGeometry(int indice , std::weak_ptr<Geometry> geom);

    void resetCamera();

    bool checkPlotDeletion();

signals:

public slots:

protected:
    std::weak_ptr<Geometry> m_geom;

    QVTKWidget2* m_renderWidget;
    vtkSmartPointer<vtkRenderer> m_renderer;
};

#endif // PLOTHD_H
