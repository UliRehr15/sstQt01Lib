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
// sstQt01LibTestView.cpp    14.08.16  Re.    14.08.16  Re.
//
// Testtool open PainterPath Csv data file and call map widget.

#include <assert.h>

#include <QApplication>
#include <QtWidgets>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "sstQt01LibTestView.h"

//=============================================================================
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Dialog dialog;
    dialog.show();

    return app.exec();
}
//=============================================================================
Dialog::Dialog()
{
  int iStat = 0;
  this->poPrt = new sstMisc01PrtFilCls;
  iStat = this->poPrt->SST_PrtAuf(1,(char*)"sstQt01LibTestView.log");
  assert(iStat == 0);

  // this->poPathStorage = new sstQt01PathStorageCls(this->poPrt);
  this->poPathStorage = new sstQt01PathStoreViewCls (this->poPrt);
  iStat = this->poPathStorage->LoadAllPathFromFile(0,"Paint.csv");
  // assert(iStat == 0);

  if (poPathStorage->countItems() <= 0)
  {
    poPrt->SST_PrtWrtChar(1,(char*)"Is Empty",(char*)"File Paint.csv: ");

    poPathStorage->createDefaultItems(0);
  }

  this->poPathWidget = new sstQt01PathPaintWidgetCls(this->poPrt,this->poPathStorage);

    createMenu();

    bigEditor = new QTextEdit;
    bigEditor->setPlainText(tr("This widget takes up all the remaining space "
                               "in the top-level layout."));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(this->poPathWidget);
    mainLayout->addWidget(bigEditor);
    setLayout(mainLayout);

    setWindowTitle(tr("PainterPath Map Data Test Frame"));
}
//=============================================================================
Dialog::~Dialog()
{
  int iStat = 0;
  iStat = this->poPathStorage->StoreAllPathToFile(0,"Paint.csv");
  assert (iStat == 0);
  delete this->poPathStorage;

  this->poPrt->SST_PrtZu(1);
  delete this->poPrt;

  delete this->poPathWidget;
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
