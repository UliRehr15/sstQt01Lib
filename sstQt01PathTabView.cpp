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

  connect(this->poTabMdl,SIGNAL(TabChanged()),this,SLOT(ChangeTab()));

}
//=============================================================================
sstQt01PathTabViewCls::~sstQt01PathTabViewCls()
{
  delete this->poTabMdl;
}
//=============================================================================
void sstQt01PathTabViewCls::UpdateTab()
{
  emit this->poTabMdl->TabUpdated();
}
//=============================================================================
