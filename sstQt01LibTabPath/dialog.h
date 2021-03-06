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
// dialog.h   12.11.14  Re.   12.11.14  Re.
//
// Datastructures and Prototypes for system "dialog"
//

#ifndef SST_DIALOG_H
#define SST_DIALOG_H

#include <QDialog>
#include <QtWidgets>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "sstQt01LibTabPath.h"

QT_BEGIN_NAMESPACE
class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE

class sstQt01PathTabDialogCls : public QDialog
{
    Q_OBJECT

public:
    sstQt01PathTabDialogCls();
    ~sstQt01PathTabDialogCls();

private:
    void createMenu();
    void createHorizontalGroupBox1();
    void createHorizontalGroupBox2();

    enum { NumGridRows = 3, NumButtons = 4 };

    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox1;
    QGroupBox *horizontalGroupBox2;

    QMenu *fileMenu;
    QAction *exitAction;

    sstQt01PathMdlCls  *pTstRec1Model;
    sstQt01TabViewCls   *pTstRec1View;

    // TstRec2ModelCls  *pTstRec2Model;
    // TstRec2ViewCls   *pTstRec2View;

};

#endif // DIALOG_H
