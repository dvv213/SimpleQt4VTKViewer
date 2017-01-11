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

#include "PlotHD.h"

#include <vtkActor.h>
#include <vtkActorCollection.h>
#include <vtkAutoInit.h>
#include <vtkCaptionActor2D.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkInteractorStyle.h>
#include <vtkTDxInteractorStyleCamera.h>
#include <vtkTDxInteractorStyleSettings.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
//#include <vtkCaptionRepresentation.h>
//#include <vtkCaptionWidget.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include "vtkCubeAxesActor.h"


#include <QVTKWidget2.h>

#include <QApplication>
#include <QVBoxLayout>
#include <QString>

#include "Geometry.h"
#include "MainWindow.h"

VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkRenderingFreeType)

PlotHD::PlotHD(QWidget *parent) : QWidget(parent)
{
  QVBoxLayout* lay = new QVBoxLayout(this);
  m_renderWidget = new QVTKWidget2(this);
  m_renderWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  m_renderer = vtkSmartPointer<vtkRenderer>::New();
  m_renderer->SetBackground(1, .714, .757); // Background color green ffb6c1

  lay->addWidget(m_renderWidget);
  lay->setContentsMargins(0, 0, 0, 0);

  m_renderWidget->GetRenderWindow()->AddRenderer(m_renderer);
}

PlotHD::~PlotHD()
{
//  delete m_renderWidget;
//	if( vtkActorCollection* actors = m_renderer->GetActors() )
//	{
//		while( vtkActor* act = actors->GetNextActor() )
//		{
//			act->GetMapper()->RemoveAllInputs();
//			act->SetMapper(nullptr);
//		}
//	}

//	m_renderWidget->GetRenderWindow()->RemoveRenderer(m_renderer);

//	qApp->postEvent(
//		MainWindow::GetWindowInstance(),
//		new QEvent(QEvent::Type(1000)));
}

void PlotHD::addGeometry(int indice, std::weak_ptr<Geometry> geom)
{
  if( auto validGeom = geom.lock() )
  { m_geom = geom;
    std::string s = std::to_string(indice);
    char const *pchar = s.c_str();

    vtkSmartPointer<vtkTextActor> textActor = vtkSmartPointer<vtkTextActor>::New();
    textActor->SetInput ( pchar );
    textActor->SetPosition2 ( 10, 40 );
    textActor->GetTextProperty()->SetFontSize ( 24 );


    //textActor->GetTextProperty()->SetColor ( 1.0, 0.0, 0.0 );


    //vtkSmartPointer<vtkCaptionActor2D> captionActor =
     //   vtkSmartPointer<vtkCaptionActor2D>::New();
    //vtkSmartPointer< vtkCaptionWidget > node1 = vtkSmartPointer< vtkCaptionWidget >::New();
    //vtkCaptionActor2D *captionActor = node1->GetCaptionActor2D();
    //captionActor->SetCaption(pchar);
    //captionActor->SetDisplayPosition(0,0);
    //captionActor->SetPosition2( 20, 20 );
    //captionActor->BorderOff();
    //captionActor->LeaderOff();
    //captionActor->ThreeDimensionalLeaderOn();
    //captionActor->GetCaptionTextProperty()->SetFontSize( 24 );

    vtkSmartPointer<vtkCubeAxesActor> axes=vtkSmartPointer<vtkCubeAxesActor> ::New();
    axes->SetCamera(m_renderer->GetActiveCamera());
    //axes->SetFlyModeToClosestTriad();
    m_renderer->AddViewProp( axes.GetPointer()) ;


    vtkSmartPointer<vtkPolyDataMapper> mapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(validGeom->getGeometryConection());

    vtkSmartPointer<vtkActor> actor =
        vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    float r1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float r2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float r3 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    actor->GetProperty()->SetColor(r1, r2, r3);
    m_renderer->AddActor(actor);
    //m_renderer->AddActor2D(captionActor);
    m_renderer->AddActor2D(textActor);
    m_renderer->ResetCamera();


  }
}

bool PlotHD::checkPlotDeletion()
{
  if( m_geom.expired() )
  {
    delete this;
    //    this->deleteLater();
    return true;
  }

  return false;
}
void PlotHD::reset_camera()
{
    m_renderer->ResetCamera();
}
