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
// sstQt01MapSignal.cpp   20.11.18  Re.   19.11.18  Re.
//
// Class transport infos of changed shape item after map update via signal.
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

//==============================================================================
sstQt01MapSignalCls::sstQt01MapSignalCls()
{

}
//==============================================================================
dREC04RECNUMTYP sstQt01MapSignalCls::getShapeItemListRecNo() const
{
return dShapeItemListRecNo;
}
//==============================================================================
void sstQt01MapSignalCls::setShapeItemListRecNo(const dREC04RECNUMTYP &value)
{
dShapeItemListRecNo = value;
}
//==============================================================================
std::string sstQt01MapSignalCls::getExternTypeStr() const
{
return oExternTypeStr;
}
//==============================================================================
void sstQt01MapSignalCls::setExternTypeStr(const std::string &value)
{
oExternTypeStr = value;
}
//==============================================================================
dREC04RECNUMTYP sstQt01MapSignalCls::getExternTypeTabRecNo() const
{
return dExternTypeTabRecNo;
}
//==============================================================================
void sstQt01MapSignalCls::setExternTypeTabRecNo(const dREC04RECNUMTYP &value)
{
dExternTypeTabRecNo = value;
}
//==============================================================================
