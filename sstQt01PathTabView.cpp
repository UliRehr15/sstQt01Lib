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
// sstQt01PathTabView.cpp    20.06.17  Re.    20.06.17  Re.
//

#include <QtWidgets>
#include <QFont>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <sstStr01Lib.h>
#include <sstMath01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "sstQt01LibInt.h"

//=============================================================================
sstQt01PathTabViewCls::sstQt01PathTabViewCls(sstMisc01PrtFilCls    *poTmpPrt,
                                             sstQt01PathStorageCls *poTmpPathStorage)
{
  pTstRec1Model = new sstQt01PathTabMdlCls(0,poTmpPrt,poTmpPathStorage);
  this->setModel( pTstRec1Model );
  connect(this->pTstRec1Model,SIGNAL(TabChanged()),this,SLOT(ChangeTab()));

}
//=============================================================================
sstQt01PathTabViewCls::~sstQt01PathTabViewCls()
{
  delete pTstRec1Model;
}
//=============================================================================
