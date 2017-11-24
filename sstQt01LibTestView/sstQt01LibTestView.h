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
// sstQt01LibTestView.h   02.09.16  Re.   02.09.16  Re.
//
// Testtool open PainterPath data file and call map widget.
//

#ifndef   _SST_QT01_LIB_TEST_VIEW_HEADER
#define   _SST_QT01_LIB_TEST_VIEW_HEADER

#include <QDialog>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

// Defines ---------------------------------------------------------------------

// forward declaration ---------------------------------------------------------

// Structures and Classes ------------------------------------------------------


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

class Dialog : public QDialog
{
    Q_OBJECT

public:
  Dialog();
  ~Dialog();

private:
    void createMenu();

    QMenuBar *menuBar;
    QTextEdit *bigEditor;

    QMenu *fileMenu;
    QAction *exitAction;
    sstMisc01PrtFilCls *poPrt;  // sst Protocoll
    sstQt01PathStorageCls *poPathStorage;  // sst Painter Path storage
    sstQt01PathPaintWidgetCls *poPathWidget;  // sst Painter path widget
};

#endif

// --------------------------------------------------------------- File End ----

