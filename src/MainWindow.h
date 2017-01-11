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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include <memory>

class Geometry;
class PlotHD;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  static MainWindow& GetWindowInstance();
  virtual ~MainWindow();

  void removeAllPlots();
  void removeAllGeometries();

protected slots:
  void addPlot();
  void removePlot();
  void addGeometry();
  void removeGeometry();
  void showAboutDialog();

protected:
  MainWindow(QWidget* parent = 0);
  virtual void customEvent(QEvent*);

private slots:



private:
  static MainWindow*                  m_winInstance;

  Ui::MainWindow*                     m_ui;
  QVector<std::shared_ptr<Geometry> > m_geomList;
  QVector<PlotHD*>                    m_plotList;
};

#endif // MAINWINDOW_H
