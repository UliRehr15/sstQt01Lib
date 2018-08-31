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
// sstQt01PathStoreTab.cpp    27.07.18  Re.    02.09.16  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include <QPen>
#include <QColor>
#include <QPainterPath>
#include <QPoint>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "sstQt01LibInt.h"

//=============================================================================
sstQt01PathStorageCls::sstQt01PathStorageCls(sstMisc01PrtFilCls *poTmpPrt)
{
  this->poShapeItemRecTable = new sstRec04Cls(sizeof(sstQt01PathElementCsv3Cls));
  this->poShapeItemMainTable = new sstRec04Cls(sizeof(sstQt01PathMainRecCls));
  dActualReadPos = 1;  // table reading starts at begin of table
  this->poShapeItemRecSymTable = new sstRec04Cls(sizeof(sstQt01PathElementCsv3Cls));
  this->poShapeItemMainSymTable = new sstRec04Cls(sizeof(sstQt01PathMainRecCls));
  dActualReadPosSym = 1;  // table reading starts at begin of table
  this->poPrt = poTmpPrt;
  this->uiVersion = 0;  // default not known format version in csv file
}
//=============================================================================
sstQt01PathStorageCls::~sstQt01PathStorageCls()
{
  delete this->poShapeItemMainSymTable;
  delete this->poShapeItemRecSymTable;
  delete this->poShapeItemMainTable;
  delete this->poShapeItemRecTable;
}
//=============================================================================
int sstQt01PathStorageCls::LoadAllPathFromFile (int iKey, std::string oFilNam)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  int iVers = this->FindCsvFileVersion(0,oFilNam);
  if (iVers <= 0)return -2;

  switch (iVers)
  {
  case 1:
    iStat = this->LoadAllPathFromFile1(0,oFilNam);
    break;
  case 2:
    iStat = this->LoadAllPathFromFile2(0,oFilNam);
    break;
  case 3:
    iStat = this->LoadAllPathFromFile3(0,oFilNam);
    break;
  default:
    assert(0);
    break;
  }

  // Update all Tooltips
  iStat = this->updateTooltips(0);

  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::LoadAllPathFromFile3 (int iKey, std::string oFilNam)
{
  sstMisc01AscFilCls oPainterCsvFile;
  std::string oCsvStr;
  std::string oErrStr;
  sstQt01PathElementCsv3Cls oShapeItemCsv3;

  int iStat1  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oPainterCsvFile.fopenRd(0,oFilNam.c_str());
  if (iStat < 0) return -2;

  // Read and test title row
  iStat = oPainterCsvFile.Rd_StrDS1( 0, &oCsvStr);

  this->poPrt->SST_PrtWrt(1,(char*)"Version 3 found");

  // load csv file into sst record table
  iStat1 = oPainterCsvFile.Rd_StrDS1( 0, &oCsvStr);
  while (iStat1 >= 0)
  {
    // interpret file row as path element
    iStat = oShapeItemCsv3.ReadFromCsv( 0, oCsvStr, &oErrStr);
    assert (iStat == 0);

    // store path element in table
    iStat = this->poShapeItemRecTable->WritNew(0,&oShapeItemCsv3,&this->dActualReadPos);

    // Write new Main Record in table if Element is next path <BR>
    iStat = this->NewMainWithElement(0,&oShapeItemCsv3);

    // Read next row from csv file
    iStat1 = oPainterCsvFile.Rd_StrDS1(0,&oCsvStr);
  }

  // close csv file
  oPainterCsvFile.fcloseFil(0);

  // Update Maintable from Elementtable
  iStat = this->UpdateMainPathSizeFromEleTab(0);

  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::LoadAllPathFromFile2 (int iKey, std::string oFilNam)
{
  sstMisc01AscFilCls oPainterCsvFile;
  std::string oCsvStr;
  std::string oErrStr;
  sstQt01PathElementCsv2Cls oShapeItemCsv2;
  sstQt01PathElementCsv3Cls oShapeItemCsv3;

  int iStat1  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oPainterCsvFile.fopenRd(0,oFilNam.c_str());
  if (iStat < 0) return -2;

  // Read and test title row
  iStat = oPainterCsvFile.Rd_StrDS1( 0, &oCsvStr);

  this->poPrt->SST_PrtWrt(1,(char*)"Version 2 found");

  // load csv file into sst record table
  iStat1 = oPainterCsvFile.Rd_StrDS1( 0, &oCsvStr);
  while (iStat1 >= 0)
  {
    // interpret file row as path element
    iStat = oShapeItemCsv2.ReadFromCsv( 0, oCsvStr, &oErrStr);
    assert (iStat == 0);

    oShapeItemCsv3.setFromVers2(oShapeItemCsv2);

    // store path element in table
    iStat = this->poShapeItemRecTable->WritNew(0,&oShapeItemCsv3,&this->dActualReadPos);

    // Write new Main Record in table if Element is next path <BR>
    iStat = this->NewMainWithElement(0,&oShapeItemCsv3);

    // Read next row from csv file
    iStat1 = oPainterCsvFile.Rd_StrDS1(0,&oCsvStr);
  }

  // close csv file
  oPainterCsvFile.fcloseFil(0);

  // Update Maintable from Elementtable
  iStat = this->UpdateMainPathSizeFromEleTab(0);

  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::LoadAllPathFromFile1 (int iKey, std::string oFilNam)
{
  sstMisc01AscFilCls oPainterCsvFile;
  std::string oCsvStr;
  std::string oErrStr;
  sstQt01PathElementCsv1Cls oShapeItemCsv1;
  sstQt01PathElementCsv2Cls oShapeItemCsv2;
  sstQt01PathElementCsv3Cls oShapeItemCsv3;

  int iStat1  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oPainterCsvFile.fopenRd(0,oFilNam.c_str());
  if (iStat < 0) return -2;

  // Read and test title row
  iStat = oPainterCsvFile.Rd_StrDS1( 0, &oCsvStr);

  this->poPrt->SST_PrtWrt(1,(char*)"Version 1 found");

  // load csv file into sst record table
  iStat1 = oPainterCsvFile.Rd_StrDS1( 0, &oCsvStr);
  while (iStat1 >= 0)
  {
    // interpret file row as path element
    iStat = oShapeItemCsv1.ReadFromCsv( 0, oCsvStr, &oErrStr);
    assert (iStat == 0);

    oShapeItemCsv2.setFromVers1(oShapeItemCsv1);
    oShapeItemCsv3.setFromVers2(oShapeItemCsv2);

    // store path element in table
    iStat = this->poShapeItemRecTable->WritNew(0,&oShapeItemCsv3,&this->dActualReadPos);

    // Write new Main Record in table if Element is next path <BR>
    iStat = this->NewMainWithElement(0,&oShapeItemCsv3);

    // Read next row from csv file
    iStat1 = oPainterCsvFile.Rd_StrDS1(0,&oCsvStr);
  }

  // close csv file
  oPainterCsvFile.fcloseFil(0);

  // Update Maintable from Elementtable
  iStat = this->UpdateMainPathSizeFromEleTab(0);

  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::StoreAllPathToFile (int iKey, std::string oFilNam)
{
  std::string oCsvStr;
  std::string oErrStr;
  sstMisc01AscFilCls oPainterCsvFile;
  sstQt01PathElementCsv3Cls oShapeItemCsv;

  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Update path element table with infos from main table
  iStat = this->UpdateTabElement( 0);

  iStat = oPainterCsvFile.fopenWr(0, oFilNam.c_str());
  assert(iStat == 0);

  // Write Title row to file
  oCsvStr = oShapeItemCsv.GetCsvFileTitle();
  oPainterCsvFile.Wr_StrDS1(0,&oCsvStr);

  for (dREC04RECNUMTYP ll=1; ll <= this->poShapeItemRecTable->count(); ll++)
  {
    oCsvStr.clear();
    iStat = this->poShapeItemRecTable->Read( 0, ll, &oShapeItemCsv);
    if (iStat >= 0)
    { // write only if not as marked deleted
      oShapeItemCsv.WriteToCsv(0, &oCsvStr, &oErrStr);
      oPainterCsvFile.Wr_StrDS1(0,&oCsvStr);
    }
  }

  oPainterCsvFile.fcloseFil(0);

  return 0;
}
//=============================================================================
int sstQt01PathStorageCls::AppendPath(int          iKey,
                                      QPainterPath oTmpPath,
                                      sstQt01ShapeType_enum eTmpPathType,
                                      QColor       oTmpColor,
                                      QPen         oTmpPen)
{

  dREC04RECNUMTYP dRecNo = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  int iEleNum = oTmpPath.elementCount();
  for (int ii =1; ii <= iEleNum; ii++)
  {
    sstQt01PathElementCsv3Cls oShapeItemCsv;
    QPainterPath::Element oElement;
    oElement = oTmpPath.elementAt(ii-1);
    oShapeItemCsv.setAll(oElement.type,oElement.x,oElement.y, oTmpColor);
//    if (oElement.type == 0)
    if (ii == 1 && oElement.type == 0)
    {
      oShapeItemCsv.setIPenStyle(oTmpPen.style());
      oShapeItemCsv.setIPenWidth(oTmpPen.width());
      oShapeItemCsv.setShapeType(eTmpPathType);
    }
    this->poShapeItemRecTable->WritNew(0, &oShapeItemCsv, &dRecNo);
  }

  return 0;
}
//=============================================================================
int sstQt01PathStorageCls::AppendPathSymbol(int          iKey,
                                      QPainterPath oTmpPath,
                                      sstQt01ShapeType_enum eTmpPathType,
                                      QColor       oTmpColor,
                                      QPen         oTmpPen)
{

  dREC04RECNUMTYP dRecNo = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  int iEleNum = oTmpPath.elementCount();
  for (int ii =1; ii <= iEleNum; ii++)
  {
    sstQt01PathElementCsv3Cls oShapeItemCsv;
    QPainterPath::Element oElement;
    oElement = oTmpPath.elementAt(ii-1);
    oShapeItemCsv.setAll(oElement.type,oElement.x,oElement.y, oTmpColor);
    if (oElement.type == 0)
    {
      oShapeItemCsv.setIPenStyle(oTmpPen.style());
      oShapeItemCsv.setIPenWidth(oTmpPen.width());
      oShapeItemCsv.setShapeType(eTmpPathType);
    }
    this->poShapeItemRecSymTable->WritNew(0, &oShapeItemCsv, &dRecNo);
  }

  return 0;
}
//=============================================================================
int sstQt01PathStorageCls::ReadNextPath(int iKey, QPainterPath *oTmpPath, QColor *oTmpColor)
{
  sstQt01PathElementCsv3Cls oShapeItemCsv1;
  sstQt01PathElementCsv3Cls oShapeItemCsv2;
  sstQt01PathElementCsv3Cls oShapeItemCsv3;
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
int sstQt01PathStorageCls::ReadPath(int iKey, dREC04RECNUMTYP dStartElementRecNo, QPainterPath *oTmpPath)
{
  sstQt01PathElementCsv3Cls oShapeItemCsv1;
  sstQt01PathElementCsv3Cls oShapeItemCsv2;
  sstQt01PathElementCsv3Cls oShapeItemCsv3;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // PainterPath object should be empty
  if (oTmpPath->elementCount() != 0) return -2;

  this->dActualReadPos = dStartElementRecNo;

  // stop reading at end of table
  if (this->dActualReadPos >= this->poShapeItemRecTable->count()) return -3;

  // first element had to be type 0 start path element
  this->poShapeItemRecTable->Read( 0, this->dActualReadPos, &oShapeItemCsv1);
  if (oShapeItemCsv1.getIType() != 0) return -4;

  oTmpPath->moveTo(oShapeItemCsv1.getIXX(),oShapeItemCsv1.getIYY());

  // loop over all record in sst table
  // for (dREC04RECNUMTYP ll=this->dActualReadPos+1; ll <= this->poShapeItemRecTable->count();ll++)
  for (dREC04RECNUMTYP ll=this->dActualReadPos+1; ll <= this->poShapeItemRecTable->count();ll++)
  {
    // Read record from table
    iStat = this->poShapeItemRecTable->Read( 0, ll, &oShapeItemCsv1);
    if (iStat < 0) continue;  // next for loop, if element is deleted

    switch (oShapeItemCsv1.getIType())
    {
    case 0:
    {
      // next path object found, stop here
      if (oShapeItemCsv1.isShapeType()) return 0;
      oTmpPath->moveTo(oShapeItemCsv1.getIXX(),oShapeItemCsv1.getIYY());
      // this->dActualReadPos = ll;
      // return 0;
    }
      break;
    case 1:
      // polygon element
      oTmpPath->lineTo(oShapeItemCsv1.getIXX(),oShapeItemCsv1.getIYY());
      break;
    case 2:
      // Read additional two Type 3 records and create 1/4 circle
      iStat = this->poShapeItemRecTable->Read( 0, ll+1, &oShapeItemCsv2);
      iStat = this->poShapeItemRecTable->Read( 0, ll+2, &oShapeItemCsv3);
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
dREC04RECNUMTYP sstQt01PathStorageCls::RecordCount() const
{
  return this->poShapeItemRecTable->count();
}
//=============================================================================
unsigned int sstQt01PathStorageCls::ColumnCount() const
{
  sstQt01PathElementCsv3Cls oElementCsvRecord;
  return oElementCsvRecord.ColumnCount();
}
//=============================================================================
int sstQt01PathStorageCls::ReadRecPos (int iKey, dREC04RECNUMTYP dRecNo, void* vRecAdr) const
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = this->poShapeItemRecTable->Read( iKey, dRecNo, vRecAdr);
  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::WriteRecPos (int iKey, dREC04RECNUMTYP dRecNo, void* vRecAdr)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = this->poShapeItemRecTable->Writ( iKey, vRecAdr, dRecNo);
  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::DeleteRecPos (int iKey, dREC04RECNUMTYP dRecNo)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = this->poShapeItemRecTable->RecSetDeleted(iKey,dRecNo);
  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::WriteNew (int iKey, dREC04RECNUMTYP *dRecNo, void* vRecAdr)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = this->poShapeItemRecTable->WritNew( iKey, vRecAdr, dRecNo);
  return iStat;
}
//=============================================================================
QString sstQt01PathStorageCls::getToolTip(dREC04RECNUMTYP index)
{
  sstQt01PathMainRecCls oMainRec;
  int iStat = this->poShapeItemMainTable->Read(0,index,&oMainRec);
  assert(iStat == 0);
  QString qStr;
  return qStr.fromStdString(oMainRec.getTooltip());
}
//=============================================================================
int sstQt01PathStorageCls::setToolTip(dREC04RECNUMTYP index, QString oTooltip)
{
  int iStat = 0;
  sstQt01PathMainRecCls oMainRec;
  iStat = this->poShapeItemMainTable->Read(0,index,&oMainRec);
  oMainRec.setTooltip( oTooltip.toStdString());
  iStat = this->poShapeItemMainTable->Writ(0,&oMainRec,index);
  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::setToolTip(dREC04RECNUMTYP index, std::string oTooltip)
{
  int iStat = 0;
  sstQt01PathMainRecCls oMainRec;
  iStat = this->poShapeItemMainTable->Read(0,index,&oMainRec);
  oMainRec.setTooltip( oTooltip);
  iStat = this->poShapeItemMainTable->Writ(0,&oMainRec,index);
  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::setPosition(dREC04RECNUMTYP index, QPoint oPosition)
{
  // assert(0);
  int iStat = 0;
  sstQt01PathMainRecCls oMainRec;
  iStat = this->poShapeItemMainTable->Read(0,index,&oMainRec);
  oMainRec.setPosition(oPosition);
  iStat = this->poShapeItemMainTable->Writ(0,&oMainRec,index);
  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::setExternID(dREC04RECNUMTYP index, dREC04RECNUMTYP dID)
{
  // assert(0);
  int iStat = 0;
  sstQt01PathMainRecCls oMainRec;
  iStat = this->poShapeItemMainTable->Read(0,index,&oMainRec);
  oMainRec.setExternId(dID);
  iStat = this->poShapeItemMainTable->Writ(0,&oMainRec,index);
  return iStat;
}
//=============================================================================
QPoint sstQt01PathStorageCls::getPosition(dREC04RECNUMTYP index)
{
  // assert(0);
  int iStat = 0;
  sstQt01PathMainRecCls oMainRec;
  iStat = this->poShapeItemMainTable->Read(0,index,&oMainRec);
  assert(iStat >= 0);
  return oMainRec.getPosition();
}
//=============================================================================
int sstQt01PathStorageCls::addPosition(dREC04RECNUMTYP index)
{
  int iStat = 0;
  sstQt01PathMainRecCls oMainRec;
  iStat = this->poShapeItemMainTable->Read(0,index,&oMainRec);
  assert(iStat >= 0);
  QPoint oPnt = oMainRec.getPosition();
  for (dREC04RECNUMTYP ii=oMainRec.getStartElementRecNo();ii <= oMainRec.getEndElementRecNo(); ii++)
  {
     sstQt01PathElementCsv3Cls oElementRec;
     iStat = this->poShapeItemRecTable->Read(0,ii,&oElementRec);
     // assert(iStat >= 0);
     assert(iStat >= 0 || iStat == -3);
     oElementRec.addIXX(oPnt.rx());
     oElementRec.addIYY(oPnt.ry());
     this->poShapeItemRecTable->Writ(0,&oElementRec,ii);
  }
  oPnt.setX(0); oPnt.setY(0);
  oMainRec.setPosition(oPnt);
  this->poShapeItemMainTable->Writ( 0, &oMainRec, index);

  return 0;
}
//=============================================================================
int sstQt01PathStorageCls::addPositionSym(dREC04RECNUMTYP index)
{
  int iStat = 0;
  sstQt01PathMainRecCls oMainRec;
  iStat = this->poShapeItemMainSymTable->Read(0,index,&oMainRec);
  assert(iStat >= 0);
  QPoint oPnt = oMainRec.getPosition();
  for (dREC04RECNUMTYP ii=oMainRec.getStartElementRecNo();ii <= oMainRec.getEndElementRecNo(); ii++)
  {
     sstQt01PathElementCsv3Cls oElementRec;
     iStat = this->poShapeItemRecSymTable->Read(0,ii,&oElementRec);
     // assert(iStat >= 0);
     assert(iStat >= 0 || iStat == -3);
     oElementRec.addIXX(oPnt.rx());
     oElementRec.addIYY(oPnt.ry());
     this->poShapeItemRecSymTable->Writ(0,&oElementRec,ii);
  }
  oPnt.setX(0); oPnt.setY(0);
  oMainRec.setPosition(oPnt);
  this->poShapeItemMainSymTable->Writ( 0, &oMainRec, index);

  return 0;
}
//=============================================================================
QColor sstQt01PathStorageCls::getColor(dREC04RECNUMTYP index)
{
  // assert(0);
  sstQt01PathMainRecCls oMainRec;
  int iStat = this->poShapeItemMainTable->Read(0,index,&oMainRec);
  assert(iStat >= 0);
  return oMainRec.getQCol();
}
//=============================================================================
QPen sstQt01PathStorageCls::getPen(dREC04RECNUMTYP index)
{
  // assert(0);
  sstQt01PathMainRecCls oMainRec;
  int iStat = this->poShapeItemMainTable->Read(0,index,&oMainRec);
  assert(iStat >= 0);
  return oMainRec.getQPen();
}
//=============================================================================
QPainterPath sstQt01PathStorageCls::getPath(dREC04RECNUMTYP index)
{
  // assert(0);
  sstQt01PathMainRecCls oMainRec;
  int iStat = this->poShapeItemMainTable->Read(0,index,&oMainRec);
  assert(iStat >= 0);
  dREC04RECNUMTYP dStartElementRecNo = oMainRec.getStartElementRecNo();
  QPainterPath oPath;
  iStat = this->ReadPath(0,dStartElementRecNo,&oPath);
  assert(iStat >= 0);
  return oPath;
}
//=============================================================================
sstQt01ShapeItem sstQt01PathStorageCls::getShapeItem(dREC04RECNUMTYP index)
{
  sstQt01ShapeItem oItem;
  sstQt01ShapeType_enum eShapeType;
  QPainterPath oPath = this->getPath(index);
  int iPathEleNum = oPath.elementCount();
  assert(iPathEleNum >= 2);
  QColor oCol = this->getColor(index);
  dREC04RECNUMTYP dID = this->getExternId(index);
  eShapeType = this->getShapeType(index);

  oItem.setExternId(dID);
  oItem.setColor(oCol);
  oItem.setPath(oPath);
  oItem.setShapeType(eShapeType);

  return oItem;
}
//=============================================================================
int sstQt01PathStorageCls::getShapeItem2(int iKey, dREC04RECNUMTYP index,sstQt01ShapeItem *poShapeItem)
{
  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if ( this->poShapeItemMainTable->RecGetDeleteStatus(0,index) == false)
  {

    // sstQt01ShapeItem oItem;
    QPainterPath oPath = this->getPath(index);
    QColor oCol = this->getColor(index);
    QPen oPen = this->getPen(index);

    poShapeItem->setShapeType(this->getShapeType(index));
    poShapeItem->setColor(oCol);
    poShapeItem->setPath(oPath);
    poShapeItem->setPen(oPen);
  }
  else
  {
    return -1;
  }
  // Fatal Errors goes to an assert

  // Pipe |
  // Smaller <
  // Greater >

  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;


  return iRet;
}
//=============================================================================
int sstQt01PathStorageCls::appendShapeItem(sstQt01ShapeItem oItem)
{
  // Append to element table
  QPainterPath oPath = oItem.getPath();
  int iStat = this->AppendPath(0,oPath,oItem.getShapeType(), oItem.getColor(),oItem.getPen());
  assert(iStat >= 0);

  // Append to main table
  sstQt01PathMainRecCls oMainRec;
  oMainRec.setQCol(oItem.getColor());
  oMainRec.setPosition(oItem.getPosition());
  int iNumElements = oPath.elementCount();
  dREC04RECNUMTYP dLastRecNo = this->poShapeItemRecTable->count();
  oMainRec.setStartElementRecNo(dLastRecNo-iNumElements+1);
  oMainRec.setNumElements(iNumElements);
  oMainRec.setShapeType(oItem.getShapeType());
  QString oToolTipStr = oItem.getToolTip();
  oMainRec.setTooltip(oToolTipStr.toStdString());

  // Store Extern Id for example dxf in sstPathStorage
  dREC04RECNUMTYP dExternId = oItem.getExternId();
  oMainRec.setExternId(dExternId);

  dREC04RECNUMTYP dRecNo = 0;
  iStat = this->poShapeItemMainTable->WritNew(0,&oMainRec,&dRecNo);
  assert(iStat >= 0);

  // move position from main table to element table
  this->addPosition(dRecNo);

  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::appendItemSymbol(sstQt01ShapeItem oItem)
{
  // Append to element table
  QPainterPath oPath = oItem.getPath();
  int iStat = this->AppendPathSymbol(0,oPath,oItem.getShapeType(), oItem.getColor(),oItem.getPen());
  assert(iStat >= 0);

  // Append to main table
  sstQt01PathMainRecCls oMainRec;
  oMainRec.setQCol(oItem.getColor());
  oMainRec.setPosition(oItem.getPosition());
  int iNumElements = oPath.elementCount();
  dREC04RECNUMTYP dLastRecNo = this->poShapeItemRecSymTable->count();
  oMainRec.setStartElementRecNo(dLastRecNo-iNumElements+1);
  oMainRec.setNumElements(iNumElements);
  oMainRec.setShapeType(oItem.getShapeType());
  QString oToolTipStr = oItem.getToolTip();
  oMainRec.setTooltip(oToolTipStr.toStdString());

  // Store Extern Id for example dxf in sstPathStorage
  dREC04RECNUMTYP dExternId = oItem.getExternId();
  oMainRec.setExternId(dExternId);

  dREC04RECNUMTYP dRecNo = 0;
  iStat = this->poShapeItemMainSymTable->WritNew(0,&oMainRec,&dRecNo);
  assert(iStat >= 0);

  // move position from main table to element table
  this->addPositionSym(dRecNo);

  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::countItems()
{
  dREC04RECNUMTYP dRecs = this->poShapeItemMainTable->count();
  return (int) dRecs;
}
//=============================================================================
int sstQt01PathStorageCls::createDefaultItems(int iKey)
{
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  QPainterPath circlePath;
  QPainterPath squarePath;
  QPainterPath trianglePath;

  circlePath.addEllipse(QRect(0, 0, 100, 100));
  squarePath.addRect(QRect(0, 0, 100, 100));

  qreal x = trianglePath.currentPosition().x();
  qreal y = trianglePath.currentPosition().y();
  trianglePath.moveTo(x + 120 / 2, y);
  trianglePath.lineTo(0, 100);
  trianglePath.lineTo(120, 100);
  trianglePath.lineTo(x + 120 / 2, y);

  sstQt01ShapeItem oItem;

  oItem.createShapeItem(circlePath, "Circle", initialItemPosition(circlePath),
                  initialItemColor(),eSstQt01PathCircle);
  this->appendShapeItem(oItem);

  oItem.createShapeItem(squarePath, "Square", initialItemPosition(squarePath),
                  initialItemColor(),eSstQt01PathArea);
  this->appendShapeItem(oItem);

  oItem.createShapeItem(trianglePath, "Triangle",
                  initialItemPosition(trianglePath), initialItemColor(),eSstQt01PathArea);
  this->appendShapeItem(oItem);

  return 0;
}
//=============================================================================
QPoint sstQt01PathStorageCls::initialItemPosition(const QPainterPath &path)
{
    int x;
    int y = (height - (int)path.controlPointRect().height()) / 2;
    // if (shapeItems.size() == 0)
    if ( this->countItems() == 0)
        x = ((3 * width) / 2 - (int)path.controlPointRect().width()) / 2;
    else
      // x = (width / shapeItems.size()
      x = (width / this->countItems()
             - (int)path.controlPointRect().width()) / 2;

    return QPoint(x, y);
}
//=============================================================================
QColor sstQt01PathStorageCls::initialItemColor()
{
  // return QColor::fromHsv(((shapeItems.size() + 1) * 85) % 256, 255, 190);
  return QColor::fromHsv(((this->countItems() + 1) * 85) % 256, 255, 190);
}
//=============================================================================
int sstQt01PathStorageCls::SearchPathItem(int iKey, dREC04RECNUMTYP dRowNum, dREC04RECNUMTYP *dItemNum)
{
  sstQt01PathMainRecCls oMainRec;
  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  dREC04RECNUMTYP dMaxRow =  this->poShapeItemMainTable->count();

  for (dREC04RECNUMTYP ll=1; ll <= dMaxRow; ll++)
  {
    iStat = this->poShapeItemMainTable->Read(0,ll,&oMainRec);
    if (dRowNum >= oMainRec.getStartElementRecNo() && dRowNum <= oMainRec.getEndElementRecNo())
    {
      *dItemNum = ll;
      return 0;
    }
  }

  *dItemNum = 0;
  iStat = -2;

  // Fatal Errors goes to an assert

  // Pipe |
  // Smaller <
  // Greater >

  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstQt01PathStorageCls::DeletePathItem(int iKey, dREC04RECNUMTYP dItemNum)
{
  sstQt01PathMainRecCls oMainRec;
  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = this->poShapeItemMainTable->Read(0,dItemNum,&oMainRec);
  assert(iStat >= 0);

  for (dREC04RECNUMTYP ll = oMainRec.getStartElementRecNo();ll <= oMainRec.getEndElementRecNo();ll++)
  {
    this->poShapeItemRecTable->RecSetDeleted(0,ll);
  }

  this->poShapeItemMainTable->RecSetDeleted(0,dItemNum);

  // Fatal Errors goes to an assert

  // Pipe |
  // Smaller <
  // Greater >

  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstQt01PathStorageCls::UpdatePathItem(int iKey, dREC04RECNUMTYP dItemNo)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstQt01PathMainRecCls oMainRec;
  iStat = this->poShapeItemMainTable->Read(0,dItemNo,&oMainRec);
  dREC04RECNUMTYP dNumElements =  oMainRec.getNumElements();
  dNumElements++;
  oMainRec.setNumElements(dNumElements);
  iStat = this->poShapeItemMainTable->Writ( 0, &oMainRec, dItemNo);

  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::UpdateTabElement(int iKey)
{
  sstQt01PathMainRecCls oMainRec;
  sstQt01PathElementCsv3Cls oElementRec;
  dREC04RECNUMTYP dElementNo = 0;  // record number of path element
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  dREC04RECNUMTYP dMainRecs = 0;  // number of recs in main table
  dMainRecs = this->poShapeItemMainTable->count();

  for (dREC04RECNUMTYP ll=1; ll <= dMainRecs; ll++)
  {
    iStat = this->poShapeItemMainTable->Read( 0, ll, &oMainRec);
    dElementNo = oMainRec.getStartElementRecNo();
    iStat = this->poShapeItemRecTable->Read( 0, dElementNo, &oElementRec);
    oElementRec.setShapeType(oMainRec.getShapeType());
    iStat = this->poShapeItemRecTable->Writ( 0, &oElementRec, dElementNo);
  }

  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::UpdateMainAttribFromElemTab(int iKey)
{
  sstQt01PathMainRecCls oMainRec;
  sstQt01PathElementCsv3Cls oElementRec;
  dREC04RECNUMTYP dElementNo = 0;  // record number of path element
  // dREC04RECNUMTYP dMainNo = 0;     // record number of path
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  dREC04RECNUMTYP dMainRecs = 0;  // number of recs in main table
  dMainRecs = this->poShapeItemMainTable->count();

  for (dREC04RECNUMTYP ll=1; ll <= dMainRecs; ll++)
  {
    iStat = this->poShapeItemMainTable->Read( 0, ll, &oMainRec);
    dElementNo = oMainRec.getStartElementRecNo();
    iStat = this->poShapeItemRecTable->Read( 0, dElementNo, &oElementRec);
    // oElementRec.setShapeType(oMainRec.getShapeType());
    oMainRec.setIColB(oElementRec.getIColB());
    oMainRec.setIColG(oElementRec.getIColG());
    oMainRec.setIColR(oElementRec.getIColR());
    oMainRec.setIPenWidth(oElementRec.getIPenWidth());
    oMainRec.setIPenStyle(oElementRec.getIPenStyle());
    // iStat = this->poShapeItemRecTable->Writ( 0, &oElementRec, dElementNo);
    iStat = this->poShapeItemMainTable->Writ( 0, &oMainRec, ll);
  }

  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::FindCsvFileVersion(int iKey, const std::string sFilNam)
{
  sstQt01PathElementCsv1Cls oCsvVers1;
  sstQt01PathElementCsv2Cls oCsvVers2;
  sstQt01PathElementCsv3Cls oCsvVers3;
  sstMisc01AscFilCls oPathCsvFil;
  int iVers = 0;
  // int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Open Asc File for reading
  iStat = oPathCsvFil.fopenRd ( 0, sFilNam.c_str());
  if (iStat < 0) return -2;

  // Read Header row from Path csv file
  std::string sHeaderRow;
  iStat = oPathCsvFil.Rd_StrDS1( 0, &sHeaderRow);

  iStat =sHeaderRow.compare(oCsvVers3.GetCsvFileTitle());
  if (iStat == 0)
  {
    iVers = 3;
  }
  iStat =sHeaderRow.compare(oCsvVers2.GetCsvFileTitle());
  if (iStat == 0)
  {
    iVers = 2;
  }
  iStat =sHeaderRow.compare(oCsvVers1.GetCsvFileTitle());
  if (iStat == 0)
  {
    iVers = 1;
  }

  iStat = oPathCsvFil.fcloseFil(0);
  assert(iStat == 0);

  return iVers;
}
//=============================================================================
int sstQt01PathStorageCls::UpdateMainPathSizeFromEleTab (int iKey)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // if main table is empty, do nothing and return.
  if (this->poShapeItemMainTable->count() <= 0)
  {
    return 0;
  }

  // update number records per path in main table
  sstQt01PathMainRecCls oPathRec1;
  sstQt01PathMainRecCls oPathRec2;
  dREC04RECNUMTYP dNumRecs = 0;
  for (dREC04RECNUMTYP ii=1; ii <= this->poShapeItemMainTable->count(); ii++)
  {
    iStat = this->poShapeItemMainTable->Read( 0, ii, &oPathRec1);
    if (ii > 1)
    {
      dNumRecs = oPathRec1.getStartElementRecNo()-oPathRec2.getStartElementRecNo();
      oPathRec2.setNumElements(dNumRecs);
      iStat = this->poShapeItemMainTable->Writ(0,&oPathRec2,ii-1);
      assert (iStat >= 0);
    }
    oPathRec2 = oPathRec1;
  }

  // Update last record in main table
  dNumRecs = this->poShapeItemRecTable->count() - oPathRec2.getStartElementRecNo()+1;
  oPathRec2.setNumElements(dNumRecs);
  iStat = this->poShapeItemMainTable->Writ(0,&oPathRec2,this->poShapeItemMainTable->count());
  assert (iStat >= 0);

  // Fatal Errors goes to an assert

  // Pipe |
  // Smaller <
  // Greater >

  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstQt01PathStorageCls::NewMainWithElement (int iKey, sstQt01PathElementCsv3Cls *oShapeItemCsv3)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (oShapeItemCsv3->getIType() == 0 && oShapeItemCsv3->isShapeType())
  {  // new path, create path item record and store in path main table
    QColor oQCol = oShapeItemCsv3->getQCol();
    QPen oPen;
    oPen.setWidth(oShapeItemCsv3->getIPenWidth());
    Qt::PenStyle oStyle;
    oStyle = (Qt::PenStyle) oShapeItemCsv3->getIPenStyle();
    oPen.setStyle(oStyle);
    sstQt01PathMainRecCls oPathMainRec;
    oPathMainRec.setQCol(oQCol);
    oPathMainRec.setQPen(oPen);
    oPathMainRec.setStartElementRecNo(this->dActualReadPos);
    oPathMainRec.setShapeType(oShapeItemCsv3->getShapeType());

    // Generate tooltip (Type and row number) from csv file information
    std::string oTooltipStr;
    oTooltipStr += oShapeItemCsv3->getSType().toStdString();
    sstStr01Cls oStrCnvt;
    oStrCnvt.Csv_UInt4_2String(0,this->dActualReadPos,&oTooltipStr);
    oPathMainRec.setTooltip(oTooltipStr);

    // Write next main record to main table of pathstorage
    iStat = this->poShapeItemMainTable->WritNew(0,&oPathMainRec, &this->dActualReadPos);
  }

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
sstQt01ShapeType_enum sstQt01PathStorageCls::getShapeType(int index)
{
  sstQt01PathMainRecCls oMainRec;
  this->poShapeItemMainTable->Read(0,index,&oMainRec);
  return oMainRec.getShapeType();
}
//=============================================================================
dREC04RECNUMTYP sstQt01PathStorageCls::getExternId(dREC04RECNUMTYP index)
{
  sstQt01PathMainRecCls oMainRec;
  int iStat = this->poShapeItemMainTable->Read(0,index,&oMainRec);
  assert(iStat >= 0);
  return oMainRec.getExternId();
}
//=============================================================================
int sstQt01PathStorageCls::getViewStoreData( int                      iKey,
                                             sstQt01PathStoreViewCls *poPathViewStore)
{
  if ( iKey != 0) return -1;

  int iStat = 0;

  for (int ll = 1; ll <= this->countItems(); ll++)
  {
    sstQt01ShapeItem oShapeItem = this->getShapeItem(ll);
    poPathViewStore->appendShapeItem(oShapeItem);
  }
  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::updateTooltips (int iKey)
//-----------------------------------------------------------------------------
{
  // QPoint oPnt(0,0);
  QPainterPath *poPath;
  QColor oColor;
  int iPathNo = 0;
  // sstQt01ShapeItem oShapeItem;

  int iRet  = 0;
  int iStat = 0;
  int iStat1 = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

//  for (int ii=1; ii <= this->countItems(); ii++)
//  {
//    oShapeItem = this->getShapeItem(ii);

//  }

  // Reset actual read positon
  this->dActualReadPos = 1;

  // read next path from shape item table
  poPath = new (QPainterPath);
  iStat1 = this->ReadNextPath( 0, poPath, &oColor);

  while (iStat1 >= 0)
  {
    iPathNo++;
    int iElements = poPath->elementCount();
    assert(iElements > 0);

    switch (iElements)
    {
    case 2:
      this->setToolTip( iPathNo, (std::string) "Line");
      break;
    case 4:
      this->setToolTip( iPathNo, (std::string) "Triangle");
      break;
    case 5:
      this->setToolTip( iPathNo, (std::string) "Square");
      break;
    case 13:
      this->setToolTip( iPathNo, (std::string) "Circle");
      break;
    default:
      this->setToolTip( iPathNo, (std::string) "Object");
      // assert(0);
      break;
    }

    // Set Extern ID to ShapeItems in Storage
    this->setExternID(iPathNo,iPathNo);


    delete poPath;
    poPath = new (QPainterPath);
    iStat1 = this->ReadNextPath( 0, poPath, &oColor);
  }

  delete poPath;

  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstQt01PathStorageCls::WriteShape(int iKey, dREC04RECNUMTYP dIndex, sstQt01ShapeItem oShapeItem)
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  QPainterPath oPath = oShapeItem.getPath();

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
