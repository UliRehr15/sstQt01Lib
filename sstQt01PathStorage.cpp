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
// sstQt01PathStorage.cpp    02.09.16  Re.    02.09.16  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include <QColor>
#include <QPainterPath>
#include <QPoint>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include "sstQt01Lib.h"

//=============================================================================
sstQt01PathStorageCls::sstQt01PathStorageCls()
{
  this->poShapeItemRecTable = new sstRec04Cls(sizeof(sstQt01PathElementCsvCls));
  dActualReadPos = 1;  // table reading starts at begin of table
}
//=============================================================================
sstQt01PathStorageCls::~sstQt01PathStorageCls()
{
  delete this->poShapeItemRecTable;
}
//=============================================================================
int sstQt01PathStorageCls::LoadAllPathFromFile (int iKey, std::string oFilNam)
{
  sstMisc01AscFilCls oPainterCsvFile;
  std::string oCsvStr;
  std::string oErrStr;
  sstStr01Cls oCsvCnvt;
  sstQt01PathElementCsvCls oShapeItemCsv;
  dREC04RECNUMTYP dRecNo = 0;


  int iStat1  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oPainterCsvFile.fopenRd(0,oFilNam.c_str());

  // load csv file into sst record table
  iStat1 = oPainterCsvFile.Rd_StrDS1( 0, &oCsvStr);
  while (iStat1 >= 0)
  {
    iStat = oShapeItemCsv.ReadFromCsv( 0, oCsvStr, &oErrStr);
    assert (iStat == 0);

    iStat = this->poShapeItemRecTable->WritNew(0,&oShapeItemCsv,&dRecNo);

    iStat1 = oPainterCsvFile.Rd_StrDS1(0,&oCsvStr);
  }

  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::StoreAllPathToFile (int iKey, std::string oFilNam)
{
  std::string oCsvStr;
  std::string oErrStr;
  sstMisc01AscFilCls oPainterCsvFile;
  sstQt01PathElementCsvCls oShapeItemCsv;

  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oPainterCsvFile.fopenWr(0, oFilNam.c_str());
  assert(iStat == 0);

  for (dREC04RECNUMTYP ll=1; ll <= this->poShapeItemRecTable->count(); ll++)
  {
    oCsvStr.clear();
    this->poShapeItemRecTable->Read( 0, ll, &oShapeItemCsv);
    oShapeItemCsv.WriteToCsv(0, &oCsvStr, &oErrStr);
    oPainterCsvFile.Wr_StrDS1(0,&oCsvStr);
  }

  oPainterCsvFile.fcloseFil(0);

  return 0;
}
//=============================================================================
int sstQt01PathStorageCls::AppendPath(int iKey, QPainterPath oTmpPath, QColor oTmpColor)
{

  sstQt01PathElementCsvCls oShapeItemCsv;
  dREC04RECNUMTYP dRecNo = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  int iEleNum = oTmpPath.elementCount();
  for (int ii =1; ii <= iEleNum; ii++)
  {
    QPainterPath::Element oElement;
    oElement = oTmpPath.elementAt(ii-1);
    oShapeItemCsv.setAll(oElement.type,oElement.x,oElement.y, oTmpColor);
    this->poShapeItemRecTable->WritNew(0, &oShapeItemCsv, &dRecNo);
  }

  return 0;
}
//=============================================================================
int sstQt01PathStorageCls::ReadNextPath(int iKey, QPainterPath *oTmpPath, QColor *oTmpColor)
{
  sstQt01PathElementCsvCls oShapeItemCsv1;
  sstQt01PathElementCsvCls oShapeItemCsv2;
  sstQt01PathElementCsvCls oShapeItemCsv3;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // PainterPath object should be empty
  if (oTmpPath->elementCount() != 0) return -2;

  // stop reading at end of table
  if (this->dActualReadPos >= this->poShapeItemRecTable->count()) return -3;

  // first element had to be type 0 start path element
  this->poShapeItemRecTable->Read( 0, this->dActualReadPos, &oShapeItemCsv1);
  if (oShapeItemCsv1.getIType() != 0) return -4;

  oTmpColor->setBlue(oShapeItemCsv1.getIColB());
  oTmpColor->setGreen(oShapeItemCsv1.getIColG());
  oTmpColor->setRed(oShapeItemCsv1.getIColR());

  oTmpPath->moveTo(oShapeItemCsv1.getIXX(),oShapeItemCsv1.getIYY());

  // loop over all record in sst table
  for (dREC04RECNUMTYP ll=this->dActualReadPos+1; ll <= this->poShapeItemRecTable->count();ll++)
  {
    // Read record from table
    this->poShapeItemRecTable->Read( 0, ll, &oShapeItemCsv1);
    switch (oShapeItemCsv1.getIType())
    {
    case 0:
    {
      // next path object found, stop here
      this->dActualReadPos = ll;
      return 0;
    }
      break;
    case 1:
      // polygon element
      oTmpPath->lineTo(oShapeItemCsv1.getIXX(),oShapeItemCsv1.getIYY());
      break;
    case 2:
      // Read additional two Type 3 records and create 1/4 circle
      this->poShapeItemRecTable->Read( 0, ll+1, &oShapeItemCsv2);
      this->poShapeItemRecTable->Read( 0, ll+2, &oShapeItemCsv3);
      oTmpPath->cubicTo(oShapeItemCsv1.getIXX(),oShapeItemCsv1.getIYY(),
                        oShapeItemCsv2.getIXX(),oShapeItemCsv2.getIYY(),
                        oShapeItemCsv3.getIXX(),oShapeItemCsv3.getIYY());
      ll = ll + 2;
      break;
    case 3:
      assert (0);
      break;
    default:
      assert (0);
      break;
    }

  }

  // last path object in file ended here
  this->dActualReadPos = this->poShapeItemRecTable->count() + 1;

  return 0;
}
//=============================================================================

