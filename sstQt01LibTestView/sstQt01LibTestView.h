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
// Tool for drawing PainterPath data
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

//! [0]
class Dialog : public QDialog
{
    Q_OBJECT

public:
  Dialog();
  ~Dialog();

private:
    void createMenu();
    void createHorizontalGroupBox();
    void createGridGroupBox();
    void createFormGroupBox();

    enum { NumGridRows = 3, NumButtons = 4 };

    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox;
    QGroupBox *gridGroupBox;
    QGroupBox *formGroupBox;
    QTextEdit *smallEditor;
    QTextEdit *bigEditor;
    QLabel *labels[NumGridRows];
    QLineEdit *lineEdits[NumGridRows];
    QPushButton *buttons[NumButtons];
    QDialogButtonBox *buttonBox;

    QMenu *fileMenu;
    QAction *exitAction;
    sstMisc01PrtFilCls *poPrt;  // sst Protocoll
    sstQt01PathStorageCls *poPathStorage;  // sst Painter Path storage
    sstQt01PathPaintWidgetCls *poPathWidget;  // sst Painter path widget
};
//! [0]


#endif

// --------------------------------------------------------------- File End ----

//#ifndef DIALOG_H
//#define DIALOG_H

//#include <QDialog>

//QT_BEGIN_NAMESPACE
//class QAction;
//class QDialogButtonBox;
//class QGroupBox;
//class QLabel;
//class QLineEdit;
//class QMenu;
//class QMenuBar;
//class QPushButton;
//class QTextEdit;
//QT_END_NAMESPACE

////! [0]
//class Dialog : public QDialog
//{
//    Q_OBJECT

//public:
//    Dialog();

//private:
//    void createMenu();
//    void createHorizontalGroupBox();
//    void createGridGroupBox();
//    void createFormGroupBox();

//    enum { NumGridRows = 3, NumButtons = 4 };

//    QMenuBar *menuBar;
//    QGroupBox *horizontalGroupBox;
//    QGroupBox *gridGroupBox;
//    QGroupBox *formGroupBox;
//    QTextEdit *smallEditor;
//    QTextEdit *bigEditor;
//    QLabel *labels[NumGridRows];
//    QLineEdit *lineEdits[NumGridRows];
//    QPushButton *buttons[NumButtons];
//    QDialogButtonBox *buttonBox;

//    QMenu *fileMenu;
//    QAction *exitAction;
//};
////! [0]

//#endif // DIALOG_H
