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
// window.h   23.02.17  Re.   23.02.17  Re.

#ifndef SST_WINDOW_H
#define SST_WINDOW_H

#include <string>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include <QWidget>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QComboBox;
class QLabel;
class QSpinBox;
QT_END_NAMESPACE
class sstQt01TestPaintWidgetCls;

//! [0]
class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

private slots:
    void shapeChanged();
    void penChanged();
    void brushChanged();

private:
    sstQt01TestPaintWidgetCls *sstQt01TestPaintWidgetCls1;
    sstQt01TestPaintWidgetCls *sstQt01TestPaintWidgetCls2;

    sstQt01TabViewCls *pTstRec1View;
    sstQt01PathTabMdlCls *pTstRec1Model;

    sstQt01PathPaintWidgetCls *pTstRec2View;

    // QLabel *shapeLabel;
    // QLabel *penWidthLabel;
    // QLabel *penStyleLabel;
    // QLabel *penCapLabel;
    // QLabel *penJoinLabel;
    // QLabel *brushStyleLabel;
    // QLabel *otherOptionsLabel;
    // QComboBox *shapeComboBox;
    // QSpinBox *penWidthSpinBox;
    // QComboBox *penStyleComboBox;
    // QComboBox *penCapComboBox;
    // QComboBox *penJoinComboBox;
    // QComboBox *brushStyleComboBox;
    // QCheckBox *antialiasingCheckBox;
    // QCheckBox *transformationsCheckBox;
};
//! [0]

#endif // WINDOW_H
