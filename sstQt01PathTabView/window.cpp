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


#include <string>

// #include "sstQt01TestPaintWidget.h"
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
  sstQt01TestPaintWidgetCls1 = new sstQt01TestPaintWidgetCls;
  sstQt01TestPaintWidgetCls2 = new sstQt01TestPaintWidgetCls;

  pTstRec1View = new sstQt01TabViewCls;
  pTstRec1Model = new sstQt01PathTabMdlCls(0);
  pTstRec1View->setModel( pTstRec1Model );

  pTstRec2View = new(sstQt01PathPaintWidgetCls);

    QGridLayout *mainLayout = new QGridLayout;
//! [9] //! [10]
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(sstQt01TestPaintWidgetCls1, 0, 0, 1, 4);
    mainLayout->addWidget(pTstRec2View, 1, 0, 1, 4);
    mainLayout->addWidget(sstQt01TestPaintWidgetCls2, 2, 0, 1, 4);
    mainLayout->addWidget(pTstRec1View, 3, 0, 1, 4);

    setLayout(mainLayout);

    shapeChanged();
    penChanged();
    brushChanged();

    setWindowTitle(tr("Basic Drawing"));
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
