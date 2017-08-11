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
// dialog.cpp    12.11.14  Re.    26.02.15  Re.
//
// widget opens two tables for editing with test record 1 and 2 from sstRec04

#include <QtWidgets>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "dialog.h"

//=============================================================================
Dialog::Dialog()
{
  this->poPrt = new sstMisc01PrtFilCls;
  int iStat = poPrt->SST_PrtAuf(1,(char*)"sstQt01LibTestTab.log");
  assert(iStat >= 0);

  createMenu();
  createHorizontalGroupBox1();
  createHorizontalGroupBox2();
  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->setMenuBar(menuBar);
  mainLayout->addWidget(horizontalGroupBox2);
  mainLayout->addWidget(horizontalGroupBox1);
  setLayout(mainLayout);
  setWindowTitle(tr("Edit Test Record Tables Example"));
}
//=============================================================================
Dialog::~Dialog()
{
  this->poPrt->SST_PrtZu(1);
  delete this->poPrt;
  // delete(pTstRec1Model);
  // delete(pTstRec2Model);
}
//=============================================================================
void Dialog::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}
//=============================================================================
void Dialog::createHorizontalGroupBox1()
{
    horizontalGroupBox1 = new QGroupBox(tr("TestRec1.csv"));
    QVBoxLayout *layout1 = new QVBoxLayout;

    pTstRec1View = new sstQt01TstRec1ViewCls(this->poPrt);
    layout1->addWidget(pTstRec1View);

    horizontalGroupBox1->setLayout(layout1);
}
//=============================================================================
void Dialog::createHorizontalGroupBox2()
{
    horizontalGroupBox2 = new QGroupBox(tr("TestRec2.csv"));
    QVBoxLayout *layout2 = new QVBoxLayout;

    pTstRec2View = new sstQt01TstRec2ViewCls(this->poPrt);
    layout2->addWidget(pTstRec2View);

    horizontalGroupBox2->setLayout(layout2);
}
//=============================================================================
