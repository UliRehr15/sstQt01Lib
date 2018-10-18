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
// TabTest2_Dialog.cpp    15.08.17  Re.   15.08.17  Re.
//

#include <assert.h>

#include <QtWidgets>
#include <QTreeView>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QTextBrowser>

#include <string>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "sstQt01LibTestTab2.h"

Dialog::Dialog()
{

  this->poPrt = new sstMisc01PrtFilCls;
  this->poPrt->SST_PrtAuf(1,(char*)"sstQt01TabTest2.log");

  oSstGroupBox = new sstQt01TestGroupBoxCls(this->poPrt);
  createMenu();

  bigEditor = new QTextEdit;
  bigEditor->setPlainText(tr("This widget takes up all the remaining space "
                             "in the top-level layout."));

  buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                   | QDialogButtonBox::Cancel);

  connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

  mainLayout = new QVBoxLayout;
  mainLayout->setMenuBar(menuBar);
  mainLayout->addWidget(oSstGroupBox);
  mainLayout->addWidget(bigEditor);
  mainLayout->addWidget(buttonBox);
  setLayout(mainLayout);

  setWindowTitle(tr("Basic Layouts"));
}

Dialog::~Dialog()
{
  delete mainLayout;
  delete buttonBox;
  delete bigEditor;
  delete oSstGroupBox;
  this->poPrt->SST_PrtZu(1);
  delete this->poPrt;
}

void Dialog::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}

