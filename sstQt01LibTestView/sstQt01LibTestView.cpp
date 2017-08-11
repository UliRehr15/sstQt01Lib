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

#include <assert.h>

#include <QApplication>
#include <QtWidgets>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "sstQt01LibTestView.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Dialog dialog;
    dialog.show();

    return app.exec();
}


//int main(int argc, char *argv[])
//{
//  sstMisc01PrtFilCls oPrt;
//  oPrt.SST_PrtAuf(0,(char*)"sstQt01LibTestView.log");

//  // Q_INIT_RESOURCE(tooltips);

//    QApplication app(argc, argv);
//    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
//    sstQt01PathPaintWidgetCls oPathPaintWidget(&oPrt);
//    oPathPaintWidget.show();
//    return app.exec();
//}


//! [0]
Dialog::Dialog()
{
  int iStat = 0;
  this->poPrt = new sstMisc01PrtFilCls;
  iStat = this->poPrt->SST_PrtAuf(1,(char*)"sstQt01LibTestView.log");
  assert(iStat == 0);

  this->poPathStorage = new sstQt01PathStorageCls;
  iStat = this->poPathStorage->LoadAllPathFromFile(0,"Paint.csv");
  // assert(iStat == 0);

  if (poPathStorage->countItems() <= 0)
  {
    poPrt->SST_PrtWrtChar(1,(char*)"Is Empty",(char*)"File Paint.csv: ");

    poPathStorage->createDefaultItems(0);
  }


  this->poPathWidget = new sstQt01PathPaintWidgetCls(this->poPrt,this->poPathStorage);

    createMenu();
    createHorizontalGroupBox();
    createGridGroupBox();
    createFormGroupBox();
//! [0]

//! [1]
    bigEditor = new QTextEdit;
    bigEditor->setPlainText(tr("This widget takes up all the remaining space "
                               "in the top-level layout."));

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
//! [1]

//! [2]
    QVBoxLayout *mainLayout = new QVBoxLayout;
//! [2] //! [3]
    mainLayout->setMenuBar(menuBar);
//! [3] //! [4]
    // mainLayout->addWidget(horizontalGroupBox);
    // mainLayout->addWidget(gridGroupBox);
    // mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(this->poPathWidget);
    mainLayout->addWidget(bigEditor);
    mainLayout->addWidget(buttonBox);
//! [4] //! [5]
    setLayout(mainLayout);

    setWindowTitle(tr("Basic Layouts"));
}
//! [5]

//! [6]
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

void Dialog::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}
//! [6]

//! [7]
void Dialog::createHorizontalGroupBox()
{
    horizontalGroupBox = new QGroupBox(tr("Horizontal layout"));
    QHBoxLayout *layout = new QHBoxLayout;

    for (int i = 0; i < NumButtons; ++i) {
        buttons[i] = new QPushButton(tr("Button %1").arg(i + 1));
        layout->addWidget(buttons[i]);
    }
    horizontalGroupBox->setLayout(layout);
}
//! [7]

//! [8]
void Dialog::createGridGroupBox()
{
    gridGroupBox = new QGroupBox(tr("Grid layout"));
//! [8]
    QGridLayout *layout = new QGridLayout;

//! [9]
    for (int i = 0; i < NumGridRows; ++i) {
        labels[i] = new QLabel(tr("Line %1:").arg(i + 1));
        lineEdits[i] = new QLineEdit;
        layout->addWidget(labels[i], i + 1, 0);
        layout->addWidget(lineEdits[i], i + 1, 1);
    }

//! [9] //! [10]
    smallEditor = new QTextEdit;
    smallEditor->setPlainText(tr("This widget takes up about two thirds of the "
                                 "grid layout."));
    layout->addWidget(smallEditor, 0, 2, 4, 1);
//! [10]

//! [11]
    layout->setColumnStretch(1, 10);
    layout->setColumnStretch(2, 20);
    gridGroupBox->setLayout(layout);
}
//! [11]

//! [12]
void Dialog::createFormGroupBox()
{
    formGroupBox = new QGroupBox(tr("Form layout"));
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("Line 1:")), new QLineEdit);
    layout->addRow(new QLabel(tr("Line 2, long text:")), new QComboBox);
    layout->addRow(new QLabel(tr("Line 3:")), new QSpinBox);
    formGroupBox->setLayout(layout);
}
//! [12]
