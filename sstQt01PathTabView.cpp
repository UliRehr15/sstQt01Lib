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
// sstQt01PathTabView.cpp   25.01.17  Re.    25.01.17  Re.
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
sstQt01PathTabViewCls::sstQt01PathTabViewCls(sstMisc01PrtFilCls    *poTmpPrt,
                                     sstQt01PathStorageCls *poTmpPathStorage) : sstQt01TabViewCls(poTmpPrt)
{
  this->poTabMdl = new sstQt01PathTabMdlCls(0,poTmpPrt,poTmpPathStorage);
  this->setModel( this->poTabMdl);

  connect(this->poTabMdl,SIGNAL(sstSgnlTabChanged(sstQt01ShapeItem)),this,SLOT(sstSlotChangeTab(sstQt01ShapeItem)));

  connect(this,SIGNAL(sstSgnlBeginInsertRows(int,int)),this->poTabMdl,SLOT(sstSlotBeginInsertRows(int,int)));
  connect(this,SIGNAL(sstSgnlEndInsertRows()),this->poTabMdl,SLOT(sstSlotEndInsertRows()));

  connect(this,SIGNAL(sstSgnlBeginRemoveRows(int,int)),this->poTabMdl,SLOT(sstSlotBeginRemoveRows(int,int)));
  connect(this,SIGNAL(sstSgnlEndRemoveRows()),this->poTabMdl,SLOT(sstSlotEndRemoveRows()));
}
//=============================================================================
sstQt01PathTabViewCls::~sstQt01PathTabViewCls()
{
  delete this->poTabMdl;
}
//=============================================================================
void sstQt01PathTabViewCls::sstSlotUpdateTab(sstQt01ShapeItem oShapeItem)
{
  emit this->poTabMdl->sstSgnlTabUpdated(oShapeItem);
  this->resizeRowsToContents();
}
//=============================================================================
