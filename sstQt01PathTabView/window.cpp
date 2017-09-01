/**********************************************************************
 *
 * sstQt01Lib - sst Qt library
 * Hosted on github
 *
 * Copyright (C) 2016 Uli Rehr
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation.
 * See the COPYING file for more information.
 *
 **********************************************************************/
// window.cpp   23.02.17  Re.   23.02.17  Re.


#include <assert.h>
#include <string>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "window.h"

#include <QtWidgets>

//! [0]
const int IdRole = Qt::UserRole;
//! [0]

//! [1]
Window::Window()
{
  int iStat = 0;
  this->oPrt = new sstMisc01PrtFilCls;

  oPrt->SST_PrtAuf(1,(char*)"sstQt01PathTabView.log");

  this->poPathStorage = new sstQt01PathStorageCls;
  iStat = this->poPathStorage->LoadAllPathFromFile(0,"Paint.csv");
  // assert(iStat == 0);

  if (poPathStorage->countItems() <= 0)
  {
    oPrt->SST_PrtWrtChar(1,(char*)"Is Empty",(char*)"File Paint.csv: ");

    poPathStorage->createDefaultItems(0);
  }


  sstQt01TestPaintWidgetCls1 = new sstQt01TestPaintWidgetCls;
  sstQt01TestPaintWidgetCls2 = new sstQt01TestPaintWidgetCls;

  poPathTabWidget = new sstQt01PathTabViewCls( oPrt, this->poPathStorage);

  poPathMapWidget = new sstQt01PathPaintWidgetCls(oPrt,this->poPathStorage);

    QGridLayout *mainLayout = new QGridLayout;
//! [9] //! [10]
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    // mainLayout->addWidget(sstQt01TestPaintWidgetCls1, 0, 0, 1, 4);
    mainLayout->addWidget(poPathMapWidget, 0, 0, 1, 4);
    // mainLayout->addWidget(sstQt01TestPaintWidgetCls2, 2, 0, 1, 4);
    mainLayout->addWidget(poPathTabWidget, 1, 0, 1, 4);

    setLayout(mainLayout);

    shapeChanged();
    penChanged();
    brushChanged();

    setWindowTitle(tr("Basic Drawing"));

    // For refreshing map from table
    connect(poPathTabWidget, SIGNAL(TabChanged()), poPathMapWidget, SLOT(update()));
    // for refreshing table from map
    connect(poPathMapWidget, SIGNAL(PathMoveEvent()), poPathTabWidget, SLOT(UpdateTab()));
    connect(poPathMapWidget,SIGNAL(sstSgnlBeginInsertRows(int,int)),poPathTabWidget,SLOT(sstSlotBeginInsertRows(int,int)));
    connect(poPathMapWidget,SIGNAL(sstSgnlEndInsertRows()),poPathTabWidget,SLOT(sstSlotEndInsertRows()));
}
Window::~Window()
{
  int iStat = 0;
  iStat = this->poPathStorage->StoreAllPathToFile(0,"Paint.csv");
  assert (iStat == 0);
  delete this->poPathStorage;
  this->oPrt->SST_PrtZu(1);
}

//! [10]

//! [11]
void Window::shapeChanged()
{
    sstQt01TestPaintWidgetCls::Shape shape = sstQt01TestPaintWidgetCls::Polygon;
    sstQt01TestPaintWidgetCls1->setShape(shape);
    sstQt01TestPaintWidgetCls2->setShape(shape);
}
//! [11]

//! [12]
void Window::penChanged()
{

    int width = 0;
    Qt::PenStyle style = Qt::SolidLine;
    Qt::PenCapStyle cap = Qt::FlatCap;
    Qt::PenJoinStyle join = Qt::MiterJoin;
    sstQt01TestPaintWidgetCls1->setPen(QPen(Qt::blue, width, style, cap, join));
    sstQt01TestPaintWidgetCls2->setPen(QPen(Qt::blue, width, style, cap, join));
}
//! [12]

//! [13]
void Window::brushChanged()
{
    // Qt::BrushStyle style = Qt::LinearGradientPattern;

        QLinearGradient linearGradient(0, 0, 100, 100);
        linearGradient.setColorAt(0.0, Qt::white);
        linearGradient.setColorAt(0.2, Qt::green);
        linearGradient.setColorAt(1.0, Qt::black);
        sstQt01TestPaintWidgetCls1->setBrush(linearGradient);
        sstQt01TestPaintWidgetCls2->setBrush(linearGradient);
}
//! [17]
