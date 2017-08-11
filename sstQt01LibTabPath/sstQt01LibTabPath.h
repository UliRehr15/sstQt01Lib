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
// sstQt01LibTabPath.h   17.01.17  Re.   17.01.17  Re.
//
// Datastructures and Prototypes for system "sstQt01LibTabPath"
//


#ifndef SST_QT01LIB_TAB_PATH_H
#define SST_QT01LIB_TAB_PATH_H

#include <QDialog>
#include <QtWidgets>
#include <QAbstractTableModel>
#include <QTableView>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

//==============================================================================
/**
* @brief sst path Table dialog Class
*
* Inherit from QDialog
*
* Changed: 09.07.15  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 09.07.15
*/
// ----------------------------------------------------------------------------
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

    QMenuBar  *menuBar;
    QGroupBox *horizontalGroupBox1;
    QGroupBox *horizontalGroupBox2;

    QMenu *fileMenu;
    QAction *exitAction;

    // sstQt01PathTabMdlCls   *pTstRec1Model;
    sstQt01PathTabViewCls   *pTstRec1View;
    sstMisc01PrtFilCls *poPrt;
    sstQt01PathStorageCls *poPathStorage;
};


#endif
