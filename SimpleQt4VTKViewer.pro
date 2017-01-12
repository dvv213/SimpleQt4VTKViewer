#-------------------------------------------------
#
# Project created by QtCreator 2017-01-09T12:30:07
#
# Simple Qt4/VTK Viewer.
# A basic example of the usage of QVTKWidget2 in Qt4 and
# VTK7.1 with C++11
# Copyright (C) 2017  Edson Contreras Cardenas

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

#-------------------------------------------------

QT       += core gui opengl

TARGET = simple-qt-viewer
TEMPLATE = app

#Note: Even though the program has the c++11 flag forced,
#      it is not necessary to build Qt4 with c++11 support
QMAKE_CXXFLAGS += -std=c++11


SOURCES += \
  ./src/main.cpp\
  ./src/MainWindow.cpp \
  ./src/PlotHD.cpp \
  ./src/Geometry.cpp \
  ./src/MyVTKApplication.cpp \
  ./src/AboutDialog.cpp

HEADERS  += \
  ./src/MainWindow.h \
  ./src/PlotHD.h \
  ./src/Geometry.h \
  ./src/MyVTKApplication.h \
  ./src/AboutDialog.h

FORMS    += \
  ./src/ui/MainWindow.ui \
  ./src/ui/AboutDialog.ui

INCLUDEPATH += \
  $$(VTK_7_INCLUDE_PATH)

LIBS += \
  -L$$(VTK_7_LIBRARY_PATH) \
  -lvtkCommonColor-7.1 \
  -lvtkCommonCore-7.1 \
  -lvtkCommonComputationalGeometry-7.1 \
  -lvtkCommonDataModel-7.1 \
  -lvtkCommonExecutionModel-7.1 \
  -lvtkCommonMath-7.1 \
  -lvtkCommonMisc-7.1 \
  -lvtkCommonSystem-7.1 \
  -lvtkCommonTransforms-7.1 \
  -lvtkDICOMParser-7.1 \
  -lvtkFiltersCore-7.1 \
  -lvtkFiltersGeneral-7.1 \
  -lvtkFiltersGeometry-7.1 \
  -lvtkFiltersExtraction-7.1 \
  -lvtkFiltersSources-7.1 \
  -lvtkFiltersStatistics-7.1 \
  -lvtkGUISupportQt-7.1 \
  -lvtkGUISupportQtOpenGL-7.1 \
  -lvtkIOImage-7.1 \
  -lvtkImagingCore-7.1 \
  -lvtkImagingFourier-7.1 \
  -lvtkInteractionStyle-7.1 \
  -lvtkInteractionImage-7.1 \
  -lvtkInteractionWidgets-7.1 \
  -lvtkRenderingAnnotation-7.1 \
  -lvtkRenderingCore-7.1 \
  -lvtkRenderingFreeType-7.1 \
  -lvtkRenderingOpenGL2-7.1 \
  -lvtkalglib-7.1 \
  -lvtkglew-7.1 \
  -lvtkjpeg-7.1 \
  -lvtkmetaio-7.1 \
  -lvtkpng-7.1 \

