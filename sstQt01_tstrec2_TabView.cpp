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
// sstQt01_tstrec2_TabView.cpp    23.04.17 Re.    23.04.17  Re.
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

// #include "sst_qt_lib_test_tab.h"

//=============================================================================
sstQt01TstRec2ViewCls::sstQt01TstRec2ViewCls(sstMisc01PrtFilCls    *poTmpPrt) : sstQt01TabViewCls(poTmpPrt)
{
  pTstRec2Model = new TstRec2ModelCls(0);
  this->setModel( pTstRec2Model );
}
//=============================================================================
sstQt01TstRec2ViewCls::~sstQt01TstRec2ViewCls()
{
  delete pTstRec2Model;
}
//=============================================================================
