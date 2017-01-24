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
// widget opens some gdb tables for editing

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
  createMenu();
  createHorizontalGroupBox1();
  // createHorizontalGroupBox2();
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMenuBar(this->menuBar);
    // mainLayout->addWidget(this->horizontalGroupBox2);
    mainLayout->addWidget(this->horizontalGroupBox1);
    setLayout(mainLayout);

    setWindowTitle(tr("Edit Test Record Tables Example"));
}
//=============================================================================
Dialog::~Dialog()
{
  delete(pTstRec1Model);
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
    horizontalGroupBox1 = new QGroupBox(tr("Paint.csv"));
    QVBoxLayout *layout1 = new QVBoxLayout;

    pTstRec1View = new(TstRec1ViewCls);
    pTstRec1Model = new TstRec1ModelCls(0);
    pTstRec1View->setModel( pTstRec1Model );
    layout1->addWidget(pTstRec1View);

    horizontalGroupBox1->setLayout(layout1);
}
//=============================================================================
//void Dialog::createHorizontalGroupBox2()
//{
//    horizontalGroupBox2 = new QGroupBox(tr("TestRec2.csv"));
//    QVBoxLayout *layout2 = new QVBoxLayout;

//    pTstRec2View = new(TstRec2ViewCls);
//    pTstRec2Model = new TstRec2ModelCls(0);
//    pTstRec2View->setModel( pTstRec2Model );
//    layout2->addWidget(pTstRec2View);

//    horizontalGroupBox2->setLayout(layout2);
//}
//=============================================================================
