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
// sstQt01_tstrec1_TabView.cpp    23.04.17  Re.    23.04.17  Re.
//

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
sstQt01TstRec1ViewCls::sstQt01TstRec1ViewCls(sstMisc01PrtFilCls    *poTmpPrt) : sstQt01TabViewCls(poTmpPrt)
{
  pTstRec1Model = new TstRec1ModelCls(0);
  this->setModel( pTstRec1Model );
}
//=============================================================================
sstQt01TstRec1ViewCls::~sstQt01TstRec1ViewCls()
{
  delete pTstRec1Model;
}
//=============================================================================
