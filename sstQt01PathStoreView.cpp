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
// sstQt01PathStoreView.cpp    23.07.18  Re.    23.07.18  Re.
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
sstQt01PathStoreViewCls::sstQt01PathStoreViewCls(sstMisc01PrtFilCls *poTmpPrt)
{
  dActualReadPos = 1;  // table reading starts at begin of table
  dActualReadPosSym = 1;  // table reading starts at begin of table
  this->poPrt = poTmpPrt;
  this->uiVersion = 0;  // default not known format version in csv file
}
//=============================================================================
sstQt01PathStoreViewCls::~sstQt01PathStoreViewCls()
{
}
//=============================================================================
int sstQt01PathStoreViewCls::LoadAllPathFromFile (int iKey, std::string oFilNam)
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

  return iStat;
}
//=============================================================================
int sstQt01PathStoreViewCls::LoadAllPathFromFile3 (int iKey, std::string oFilNam)
{
  sstQt01PathStorageCls *poPathTabStore;

  // int iStat1  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  poPathTabStore = new sstQt01PathStorageCls(this->poPrt);

  iStat = poPathTabStore->LoadAllPathFromFile(0,oFilNam);
  if (iStat < 0)
  {
    delete poPathTabStore;
    return -2;
  }

  for (int ll = 1; ll <= poPathTabStore->countItems(); ll++)
  {
    sstQt01ShapeItem oShapeItem = poPathTabStore->getShapeItem(ll);
    this->shapeItems.push_back(oShapeItem);
  }

  delete poPathTabStore;

  return iStat;
}
//=============================================================================
int sstQt01PathStoreViewCls::LoadAllPathFromFile2 (int iKey, std::string oFilNam)
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
int sstQt01PathStoreViewCls::LoadAllPathFromFile1 (int iKey, std::string oFilNam)
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
int sstQt01PathStoreViewCls::StoreAllPathToFile (int iKey, std::string oFilNam)
{
  sstQt01PathStorageCls *poPathTabStore;

  // int iStat1  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  poPathTabStore = new sstQt01PathStorageCls(this->poPrt);

  QList<sstQt01ShapeItem>::iterator it;
  for (it = this->shapeItems.begin(); it != this->shapeItems.end(); ++it)
  {
    poPathTabStore->appendShapeItem(*it);
  }

  iStat = poPathTabStore->StoreAllPathToFile(0,oFilNam);

  delete poPathTabStore;

  return iStat;
}
//=============================================================================
int sstQt01PathStoreViewCls::AppendPath(int          iKey,
                                      QPainterPath oTmpPath,
                                      sstQt01ShapeType_enum eTmpPathType,
                                      QColor       oTmpColor,
                                      QPen         oTmpPen)
{

  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  int iStat = 0;

  sstQt01ShapeItem oShapeItem;

  oShapeItem.setPath(oTmpPath);
  oShapeItem.setShapeType(eTmpPathType);
  oShapeItem.setColor(oTmpColor);
  oShapeItem.setPen(oTmpPen);

  this->shapeItems.append(oShapeItem);

  return iStat;
}
//=============================================================================
int sstQt01PathStoreViewCls::AppendPathSymbol(int          iKey,
                                      QPainterPath oTmpPath,
                                      sstQt01ShapeType_enum eTmpPathType,
                                      QColor       oTmpColor,
                                      QPen         oTmpPen)
{

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
  }

  return 0;
}
//=============================================================================
int sstQt01PathStoreViewCls::ReadNextPath(int iKey, QPainterPath *oTmpPath, QColor *oTmpColor)
{
  int iStat = 0;
  sstQt01ShapeItem oShapeItem;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // PainterPath object should be empty
  if (oTmpPath->elementCount() != 0) return -2;

  // stop reading at end of table
  if (this->dActualReadPos >= this->countItems()) return -3;

  oShapeItem = this->getShapeItem(this->dActualReadPos);
  this->dActualReadPos++;

  *oTmpPath = oShapeItem.getPath();

  *oTmpColor = oShapeItem.getColor();

  return iStat;
}
//=============================================================================
int sstQt01PathStoreViewCls::ReadPath(int iKey, dREC04RECNUMTYP dStartElementRecNo, QPainterPath *oTmpPath)
{
  sstQt01PathElementCsv3Cls oShapeItemCsv1;
  sstQt01PathElementCsv3Cls oShapeItemCsv2;
  sstQt01PathElementCsv3Cls oShapeItemCsv3;
  // int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // PainterPath object should be empty
  if (oTmpPath->elementCount() != 0) return -2;

  this->dActualReadPos = dStartElementRecNo;

  oTmpPath->moveTo(oShapeItemCsv1.getIXX(),oShapeItemCsv1.getIYY());

  return 0;
}
//=============================================================================
dREC04RECNUMTYP sstQt01PathStoreViewCls::RecordCount() const
{
  return 0;
}
//=============================================================================
unsigned int sstQt01PathStoreViewCls::ColumnCount() const
{
  sstQt01PathElementCsv3Cls oElementCsvRecord;
  return oElementCsvRecord.ColumnCount();
}
//=============================================================================
QString sstQt01PathStoreViewCls::getToolTip(dREC04RECNUMTYP index)
{
  sstQt01ShapeItem oShapeItem;
  int iStat = 0;
  oShapeItem = this->shapeItems.at(index-1);
  assert(iStat == 0);
  return oShapeItem.getToolTip();
}
//=============================================================================
int sstQt01PathStoreViewCls::setToolTip(dREC04RECNUMTYP index, QString oTooltip)
{
  int iStat = 0;
  sstQt01ShapeItem oShapeItem;
  oShapeItem = this->shapeItems.at(index-1);
  oShapeItem.setToolTip( oTooltip);
  this->shapeItems.replace(index-1,oShapeItem);
  return iStat;
}
//=============================================================================
int sstQt01PathStoreViewCls::setToolTip(dREC04RECNUMTYP index, std::string oTooltip)
{
  int iStat = 0;
  sstQt01ShapeItem oShapeItem;
  oShapeItem = this->shapeItems.at( index-1);
  oShapeItem.setToolTip( QString::fromStdString(oTooltip));
  this->shapeItems.replace( index-1, oShapeItem);
  return iStat;
}
//=============================================================================
int sstQt01PathStoreViewCls::setPosition(dREC04RECNUMTYP index, QPoint oPosition)
{
  int iStat = 0;
  sstQt01ShapeItem oShapeItem;
  oShapeItem = this->shapeItems.at( index-1);
  oShapeItem.setPosition(oPosition);
  this->shapeItems.replace( index-1, oShapeItem);
  return iStat;
}
//=============================================================================
QPoint sstQt01PathStoreViewCls::getPosition(dREC04RECNUMTYP index)
{
  int iStat = 0;
  sstQt01ShapeItem oShapeItem;
  oShapeItem = this->shapeItems.at( index-1);
  assert(iStat >= 0);
  return oShapeItem.getPosition();
}
//=============================================================================
int sstQt01PathStoreViewCls::addPosition(dREC04RECNUMTYP index)
{
  int iStat = 0;
  sstQt01ShapeItem oShapeItem;
  oShapeItem = this->shapeItems.at( index-1);
  assert(iStat >= 0);
  QPoint oPnt = oShapeItem.getPosition();
  oShapeItem.setPosition(oPnt);
  this->shapeItems.replace( index-1, oShapeItem);

  return 0;
}
//=============================================================================
int sstQt01PathStoreViewCls::addPositionSym(dREC04RECNUMTYP index)
{
  int iStat = 0;
  sstQt01ShapeItem oShapeItem;
  oShapeItem = this->shapeItems.at( index-1);
  QPoint oPnt = oShapeItem.getPosition();
  oShapeItem.setPosition(oPnt);
  this->shapeItems.replace( index-1, oShapeItem);

  return iStat;
}
//=============================================================================
QColor sstQt01PathStoreViewCls::getColor(dREC04RECNUMTYP index)
{
  sstQt01ShapeItem oShapeItem;
  oShapeItem = this->shapeItems.at( index-1);
  return oShapeItem.getColor();
}
//=============================================================================
QPen sstQt01PathStoreViewCls::getPen(dREC04RECNUMTYP index)
{
  sstQt01ShapeItem oShapeItem;
  oShapeItem = this->shapeItems.at( index-1);
  return oShapeItem.getPen();
}
//=============================================================================
QPainterPath sstQt01PathStoreViewCls::getPath(dREC04RECNUMTYP index)
{
  sstQt01ShapeItem oShapeItem;
  oShapeItem = this->shapeItems.at( index-1);
  QPainterPath oPath;
  oPath = oShapeItem.getPath();
  return oPath;
}
//=============================================================================
sstQt01ShapeItem sstQt01PathStoreViewCls::getShapeItem(dREC04RECNUMTYP index)
{
  sstQt01ShapeItem oItem;
  oItem = this->shapeItems.at( index-1);
  return oItem;
}
//=============================================================================
int sstQt01PathStoreViewCls::getShapeItem2(int iKey, dREC04RECNUMTYP index,sstQt01ShapeItem *poShapeItem)
{
  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstQt01ShapeItem oItem;
  *poShapeItem = this->shapeItems.at( index-1);

  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstQt01PathStoreViewCls::appendShapeItem(sstQt01ShapeItem oItem)
{
  // Append to element table
  QPainterPath oPath = oItem.getPath();
  int iStat = this->AppendPath(0,oPath,oItem.getShapeType(), oItem.getColor(),oItem.getPen());
  assert(iStat >= 0);

  return iStat;
}
//=============================================================================
int sstQt01PathStoreViewCls::appendItemSymbol(sstQt01ShapeItem oItem)
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
  dREC04RECNUMTYP dLastRecNo = 0;
  oMainRec.setStartElementRecNo(dLastRecNo-iNumElements+1);
  oMainRec.setNumElements(iNumElements);
  oMainRec.setShapeType(oItem.getShapeType());
  QString oToolTipStr = oItem.getToolTip();
  oMainRec.setTooltip(oToolTipStr.toStdString());

  // Store Extern Id for example dxf in sstPathStorage
  dREC04RECNUMTYP dExternId = oItem.getExternId();
  oMainRec.setExternId(dExternId);

  dREC04RECNUMTYP dRecNo = 0;

  // move position from main table to element table
  this->addPositionSym(dRecNo);

  return iStat;
}
//=============================================================================
unsigned int sstQt01PathStoreViewCls::countItems()
{
  unsigned int uiRecs = this->shapeItems.count();
  return uiRecs;
}
//=============================================================================
int sstQt01PathStoreViewCls::createDefaultItems(int iKey)
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
QPoint sstQt01PathStoreViewCls::initialItemPosition(const QPainterPath &path)
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
QColor sstQt01PathStoreViewCls::initialItemColor()
{
  return QColor::fromHsv(((this->countItems() + 1) * 85) % 256, 255, 190);
}
//=============================================================================
int sstQt01PathStoreViewCls::SearchPathItem(int iKey, dREC04RECNUMTYP dRowNum, dREC04RECNUMTYP *dItemNum)
{
  sstQt01PathMainRecCls oMainRec;
  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // dREC04RECNUMTYP dMaxRow =  this->poShapeItemMainTable->count();
  dREC04RECNUMTYP dMaxRow =  0;

  for (dREC04RECNUMTYP ll=1; ll <= dMaxRow; ll++)
  {
    if (dRowNum >= oMainRec.getStartElementRecNo() && dRowNum <= oMainRec.getEndElementRecNo())
    {
      *dItemNum = ll;
      return 0;
    }
  }

  *dItemNum = 0;
  iStat = -2;

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstQt01PathStoreViewCls::DeletePathItem(int iKey, dREC04RECNUMTYP dItemNum)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  this->shapeItems.removeAt(dItemNum-1);

  return iStat;
}
//=============================================================================
int sstQt01PathStoreViewCls::UpdatePathItem(int iKey, dREC04RECNUMTYP dItemNo)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  dREC04RECNUMTYP dNumItems = this->shapeItems.count();
  if (dItemNo > dNumItems ) return -2;

  return iStat;
}
//=============================================================================
int sstQt01PathStoreViewCls::UpdateTabElement(int iKey)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  return iStat;
}
//=============================================================================
int sstQt01PathStoreViewCls::UpdateMainAttribFromElemTab(int iKey)
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  return iStat;
}
//=============================================================================
int sstQt01PathStoreViewCls::FindCsvFileVersion(int iKey, const std::string sFilNam)
{
  sstQt01PathElementCsv1Cls oCsvVers1;
  sstQt01PathElementCsv2Cls oCsvVers2;
  sstQt01PathElementCsv3Cls oCsvVers3;
  sstMisc01AscFilCls oPathCsvFil;
  int iVers = 0;
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
int sstQt01PathStoreViewCls::UpdateMainPathSizeFromEleTab (int iKey)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // update number records per path in main table
  sstQt01PathMainRecCls oPathRec1;
  sstQt01PathMainRecCls oPathRec2;
  dREC04RECNUMTYP dNumRecs = 0;

  // Update last record in main table
  oPathRec2.setNumElements(dNumRecs);
  assert (iStat >= 0);

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstQt01PathStoreViewCls::NewMainWithElement (int iKey, sstQt01PathElementCsv3Cls *oShapeItemCsv3)
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
  }

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
sstQt01ShapeType_enum sstQt01PathStoreViewCls::getShapeType(int index)
{
  sstQt01ShapeItem oShapeItem;

  oShapeItem = this->shapeItems.at( index-1);

  return oShapeItem.getShapeType();
}
//=============================================================================
dREC04RECNUMTYP sstQt01PathStoreViewCls::getExternId(dREC04RECNUMTYP index)
{
  sstQt01ShapeItem oShapeItem;
  oShapeItem = this->shapeItems.at( index-1);
  int iStat = 0;
  assert(iStat >= 0);
  return oShapeItem.getExternId();
}
//=============================================================================

