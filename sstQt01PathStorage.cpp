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
sstQt01PathStorageCls::sstQt01PathStorageCls()
{
  this->poShapeItemRecTable = new sstRec04Cls(sizeof(sstQt01PathElementCsv2Cls));
  this->poShapeItemMainTable = new sstRec04Cls(sizeof(sstQt01PathMainRecCls));
  dActualReadPos = 1;  // table reading starts at begin of table
  iHeight = 300;
  iWidth = 500;

}
//=============================================================================
sstQt01PathStorageCls::~sstQt01PathStorageCls()
{
  delete this->poShapeItemMainTable;
  delete this->poShapeItemRecTable;
}
//=============================================================================
int sstQt01PathStorageCls::LoadAllPathFromFile (int iKey, std::string oFilNam)
{
  // sstMisc01AscFilCls oPainterCsvFile;
  // std::string oCsvStr;
  // std::string oErrStr;
  // sstStr01Cls oCsvCnvt;
  sstQt01PathElementCsv2Cls oShapeItemCsv;
  dREC04RECNUMTYP dRecNo = 0;

  // int iStat1  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Load Format Version 2 data from file
  iStat = this->LoadVersion2File(0, oFilNam);

  // If Format version error, try to load Version 1 data from file
  if (iStat == -3)
    iStat = this->LoadVersion1File(0, oFilNam);

  if (iStat < 0)
  {
    return -3;
  }

  // if main table is empty, do nothing and return.
  if (this->poShapeItemRecTable->count() <= 0)
  {
    return 0;
  }

  // Build main table
  for (dREC04RECNUMTYP ii=1;ii <= this->poShapeItemRecTable->count();ii++)
  {
    this->poShapeItemRecTable->Read(0,ii, &oShapeItemCsv);
    if (oShapeItemCsv.getIType() == 0)
    {  // new path, create path item record and store in path main table
      QColor oQCol = oShapeItemCsv.getQCol();
      sstQt01PathMainRecCls oPathRec;
      oPathRec.setQCol(oQCol);
      // oPathRec.setStartElementRecNo(dRecNo);
      oPathRec.setStartElementRecNo(ii);
      // oPathRec.setTooltip("aaa");;
      iStat = this->poShapeItemMainTable->WritNew(0,&oPathRec,&dRecNo);
    }
  }

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

  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::StoreAllPathToFile (int iKey, std::string oFilNam)
{
  std::string oCsvStr;
  std::string oErrStr;
  sstMisc01AscFilCls oPainterCsvFile;
  sstQt01PathElementCsv2Cls oShapeItemCsv;

  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oPainterCsvFile.fopenWr(0, oFilNam.c_str());
  assert(iStat == 0);

  // Write Title row to file
  oCsvStr = oShapeItemCsv.GetCsvFileTitle();
  oPainterCsvFile.Wr_StrDS1(0,&oCsvStr);

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

  sstQt01PathElementCsv2Cls oShapeItemCsv;
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
  sstQt01PathElementCsv2Cls oShapeItemCsv1;
  sstQt01PathElementCsv2Cls oShapeItemCsv2;
  sstQt01PathElementCsv2Cls oShapeItemCsv3;
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
  sstQt01PathElementCsv2Cls oShapeItemCsv1;
  sstQt01PathElementCsv2Cls oShapeItemCsv2;
  sstQt01PathElementCsv2Cls oShapeItemCsv3;
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
dREC04RECNUMTYP sstQt01PathStorageCls::RecordCount() const
{
  return this->poShapeItemRecTable->count();
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
     sstQt01PathElementCsv2Cls oElementRec;
     iStat = this->poShapeItemRecTable->Read(0,ii,&oElementRec);
     assert(iStat >= 0);
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
QColor sstQt01PathStorageCls::getColor(dREC04RECNUMTYP index)
{
  // assert(0);
  sstQt01PathMainRecCls oMainRec;
  int iStat = this->poShapeItemMainTable->Read(0,index,&oMainRec);
  assert(iStat >= 0);
  return oMainRec.getQCol();
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
  // assert(0);
  sstQt01ShapeItem oItem;
  QPainterPath oPath = this->getPath(index);
  QColor oCol = this->getColor(index);

  oItem.setColor(oCol);
  oItem.setPath(oPath);

  return oItem;
}
//=============================================================================
int sstQt01PathStorageCls::appendShapeItem(sstQt01ShapeItem oItem)
{
  // Append to element table
  QPainterPath oPath = oItem.getPath();
  // oPath.moveTo(oItem.getPosition());
  int iStat = this->AppendPath(0,oPath,oItem.getColor());
  assert(iStat >= 0);

  // Append to main table
  sstQt01PathMainRecCls oMainRec;
  oMainRec.setQCol(oItem.getColor());
  oMainRec.setPosition(oItem.getPosition());
  int iNumElements = oPath.elementCount();
  dREC04RECNUMTYP dLastRecNo = this->poShapeItemRecTable->count();
  oMainRec.setStartElementRecNo(dLastRecNo-iNumElements+1);
  oMainRec.setNumElements(iNumElements);

  dREC04RECNUMTYP dRecNo = 0;
  iStat = this->poShapeItemMainTable->WritNew(0,&oMainRec,&dRecNo);
  assert(iStat >= 0);

  // move position from main table to element table
  this->addPosition(dRecNo);

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
                  initialItemColor());
  this->appendShapeItem(oItem);

  oItem.createShapeItem(squarePath, "Square", initialItemPosition(squarePath),
                  initialItemColor());
  this->appendShapeItem(oItem);

  oItem.createShapeItem(trianglePath, "Triangle",
                  initialItemPosition(trianglePath), initialItemColor());
  this->appendShapeItem(oItem);

  return 0;
}
//=============================================================================
QPoint sstQt01PathStorageCls::initialItemPosition(const QPainterPath &path)
{
    int x;
    int y = (iHeight - (int)path.controlPointRect().height()) / 2;
    // if (shapeItems.size() == 0)
    if ( this->countItems() == 0)
        x = ((3 * iWidth) / 2 - (int)path.controlPointRect().width()) / 2;
    else
      // x = (width / shapeItems.size()
      x = (iWidth / this->countItems()
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
int sstQt01PathStorageCls::LoadVersion2File(int iKey, std::string oFilNam)
{
  if (iKey != 0) return -1;

  int iStat = 0;
  int iStat1 = 0;
  std::string oCsvStr;
  std::string oErrStr;
  sstQt01PathElementCsv2Cls oShapeItemCsv;  // Version 2 CSV String
  dREC04RECNUMTYP dRecNo = 0;
  sstMisc01AscFilCls oPainterCsvFile;

  iStat = oPainterCsvFile.fopenRd(0,oFilNam.c_str());
  if (iStat < 0) return -2;

  // Read and test title row
  iStat = oPainterCsvFile.Rd_StrDS1( 0, &oCsvStr);
  iStat =oCsvStr.compare(oShapeItemCsv.GetCsvFileTitle());
  if (iStat != 0) return -3;  // Version Error

  // load csv file into sst record table
  iStat1 = oPainterCsvFile.Rd_StrDS1( 0, &oCsvStr);
  while (iStat1 >= 0)
  {
    // interpret file row as path element
    iStat = oShapeItemCsv.ReadFromCsv( 0, oCsvStr, &oErrStr);
    if (iStat != 0) return -4;

    // store path element in table
    iStat = this->poShapeItemRecTable->WritNew(0,&oShapeItemCsv,&dRecNo);

    // Read next row from csv file
    iStat1 = oPainterCsvFile.Rd_StrDS1(0,&oCsvStr);
  }

  iStat = oPainterCsvFile.fcloseFil(0);

  return iStat;
}
//=============================================================================
int sstQt01PathStorageCls::LoadVersion1File(int iKey, std::string oFilNam)
{
  if (iKey != 0) return -1;
  int iStat = 0;
  int iStat1 = 0;
  std::string oCsvStr;
  std::string oErrStr;
  sstQt01PathElementCsv1Cls oShapeItem1Csv;  // Version 1 CSV String
  dREC04RECNUMTYP dRecNo = 0;
  sstMisc01AscFilCls oPainterCsvFile;

  iStat = oPainterCsvFile.fopenRd(0,oFilNam.c_str());
  if (iStat < 0) return -2;

  // Read and test title row
  iStat = oPainterCsvFile.Rd_StrDS1( 0, &oCsvStr);
  iStat =oCsvStr.compare(oShapeItem1Csv.GetCsvFileTitle());
  if (iStat != 0) return -2;  // Version Error

  // load csv file into sst record table
  iStat1 = oPainterCsvFile.Rd_StrDS1( 0, &oCsvStr);
  while (iStat1 >= 0)
  {
    // interpret file row as path element
    iStat = oShapeItem1Csv.ReadFromCsv( 0, oCsvStr, &oErrStr);
    if (iStat != 0) return -3;

    sstQt01PathElementCsv2Cls oShapeItem2Csv;  // Version 2 CSV String

    oShapeItem2Csv.setIXX(oShapeItem1Csv.getIXX());
    oShapeItem2Csv.setIYY(oShapeItem1Csv.getIYY());
    oShapeItem2Csv.setIType(oShapeItem1Csv.getIType());
    oShapeItem2Csv.setIColR(oShapeItem1Csv.getIColR());
    oShapeItem2Csv.setIColG(oShapeItem1Csv.getIColG());
    oShapeItem2Csv.setIColB(oShapeItem1Csv.getIColB());
    oShapeItem2Csv.setIPenWidth(1);
    oShapeItem2Csv.setIPenStyle(1);

    // store path element in table
    iStat = this->poShapeItemRecTable->WritNew(0,&oShapeItem2Csv,&dRecNo);

    // Read next row from csv file
    iStat1 = oPainterCsvFile.Rd_StrDS1(0,&oCsvStr);
  }

  iStat = oPainterCsvFile.fcloseFil(0);

  return iStat;
}
//=============================================================================
