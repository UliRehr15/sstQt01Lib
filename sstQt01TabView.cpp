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
// sstQt01TabView.cpp   25.01.17  Re.    25.01.17  Re.
//
// qt View for sst Table

#include <QtWidgets>
#include <QFont>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "sstQt01LibInt.h"

//=============================================================================
//sstQt01TabViewCls::sstQt01TabViewCls(sstMisc01PrtFilCls    *poTmpPrt,
//                                     sstQt01PathStorageCls *poTmpPathStorage)
sstQt01TabViewCls::sstQt01TabViewCls()
{
  // this->poTabMdl = new sstQt01PathTabMdlCls(0,poTmpPrt,poTmpPathStorage);
  // this->setModel( this->poTabMdl);
    createActions();
    setupContextMenu();
    // connect(this->poTabMdl,SIGNAL(TabChanged()),this,SLOT(ChangeTab()));
}
//=============================================================================
sstQt01TabViewCls::~sstQt01TabViewCls()
{
  // delete this->poTabMdl;
}
//=============================================================================
void sstQt01TabViewCls::setupContextMenu()
{
    addAction(cell_InsAction);
    addAction(cell_DelAction);
    setContextMenuPolicy(Qt::ActionsContextMenu);
}
//=============================================================================
void sstQt01TabViewCls::createActions()
{
  // QString tt = QString::fromLatin1("&Zeilen lцschen");
  QString tt = QString::fromLatin1("&Remove Row");

  cell_DelAction = new QAction(tt, this);
  cell_DelAction->setShortcut(Qt::CTRL | Qt::Key_Minus);
  connect(cell_DelAction, SIGNAL(triggered()), this, SLOT(actionRowsDelete()));

  // tt = QString::fromLatin1("&Zeile einfьgen am Ende");
  tt = QString::fromLatin1("&Insert Row at Table End");
  cell_InsAction = new QAction( tt, this);
  cell_InsAction->setShortcut(Qt::CTRL | Qt::Key_Plus);
  connect(cell_InsAction, SIGNAL(triggered()), this, SLOT(actionRowsInsert()));

}
//=============================================================================
void sstQt01TabViewCls::actionRowsDelete()
{
  const QModelIndex index = this->selectionModel()->currentIndex();
  int row = index.row();  // Get Positon of selected Row
  int count = 1;  // Delete always one row
  this->model()->removeRows(row,count,index);
}
//=============================================================================
void sstQt01TabViewCls::actionRowsInsert()
{
  const QModelIndex index = this->selectionModel()->currentIndex();
  int row = this->model()->rowCount();  // Get Number of all defined rows
  int count = 1;  // Append always one new row
  this->model()->insertRows(row,count,index);
}
//=============================================================================
void sstQt01TabViewCls::ChangeTab()
{
  emit this->TabChanged();
}
//=============================================================================

