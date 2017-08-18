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
// sstQt01PathElementCsv.cpp    02.09.16  Re.    02.09.16  Re.
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
sstQt01PathElementCsvCls::sstQt01PathElementCsvCls()
{
  this->iType = 0;        /**< Shape Item Type */
  this->iXX = 0;          /**< Coordinate X */
  this->iYY = 0;          /**< Coordinate Y */
  this->iColR = 0;        /**< Color Red */
  this->iColG = 0;        /**< Color Green */
  this->iColB = 0;        /**< Color Blue */

}
//=============================================================================
int sstQt01PathElementCsvCls::ReadFromCsv(int iKey, std::string oCsvStr, std::string *oErrStr)
{
  sstStr01Cls oCsvCnvt;

  int iStat = 0;
  // int iVal = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (iStat >= 0) iStat = oCsvCnvt.CsvString2_Int2( 0, &oCsvStr,&this->iType);  // Type
  if (iStat >= 0) iStat = oCsvCnvt.CsvString2_Int2( 0, &oCsvStr,&this->iXX);  // X
  if (iStat >= 0) iStat = oCsvCnvt.CsvString2_Int2( 0, &oCsvStr,&this->iYY);  // Y
  if (iStat >= 0) iStat = oCsvCnvt.CsvString2_Int2( 0, &oCsvStr,&this->iColR);  // Color R
  if (iStat >= 0) iStat = oCsvCnvt.CsvString2_Int2( 0, &oCsvStr,&this->iColG);  // Color G
  if (iStat >= 0) iStat = oCsvCnvt.CsvString2_Int2( 0, &oCsvStr,&this->iColB);  // Color B
  *oErrStr = oCsvCnvt.GetErrorString();
  return iStat;
}
//=============================================================================
int sstQt01PathElementCsvCls::WriteToCsv(int iKey, std::string *oCsvStr, std::string *oErrStr)
{
  sstStr01Cls oCsvCnvt;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (iStat >= 0) iStat = oCsvCnvt.Csv_Int2_2String( 0, this->iType, oCsvStr);
  if (iStat >= 0) iStat = oCsvCnvt.Csv_Int2_2String( 0, this->iXX, oCsvStr);
  if (iStat >= 0) iStat = oCsvCnvt.Csv_Int2_2String( 0, this->iYY, oCsvStr);
  if (iStat >= 0) iStat = oCsvCnvt.Csv_Int2_2String( 0, this->iColR, oCsvStr);
  if (iStat >= 0) iStat = oCsvCnvt.Csv_Int2_2String( 0, this->iColG, oCsvStr);
  if (iStat >= 0) iStat = oCsvCnvt.Csv_Int2_2String( 0, this->iColB, oCsvStr);
  *oErrStr = oCsvCnvt.GetErrorString();

  return iStat;
}
//=============================================================================
std::string sstQt01PathElementCsvCls::GetCsvFileTitle()
{
  std::string oLocStr;
  //-----------------------------------------------------------------------------

  oLocStr = "iType;iXX;iYY;iColR;iColG;iColB";

  return oLocStr;
}
//=============================================================================
unsigned int sstQt01PathElementCsvCls::ColumnCount()
{
  unsigned int uiCol = 6;
  //-----------------------------------------------------------------------------

  return uiCol;
}
//=============================================================================
void sstQt01PathElementCsvCls::setAll(int iTmpType,int iTmpXX, int iTmpYY, QColor oTmpCol)
{
  int iTmpColR = 0;
  int iTmpColG = 0;
  int iTmpColB = 0;

  oTmpCol.getRgb(&iTmpColR,&iTmpColG,&iTmpColB);

  this->iType = iTmpType;
  this->iXX = iTmpXX;
  this->iYY = iTmpYY;
  this->iColR = iTmpColR;
  this->iColG = iTmpColG;
  this->iColB = iTmpColB;
}
//=============================================================================
int sstQt01PathElementCsvCls::getIType() const
{
  return iType;
}
//=============================================================================
void sstQt01PathElementCsvCls::setIType(int value)
{
  iType = value;
}
//=============================================================================
int sstQt01PathElementCsvCls::getIXX() const
{
  return iXX;
}
//=============================================================================
void sstQt01PathElementCsvCls::setIXX(int value)
{
  iXX = value;
}
//=============================================================================
void sstQt01PathElementCsvCls::addIXX(int value)
{
  iXX = iXX + value;
}
//=============================================================================
int sstQt01PathElementCsvCls::getIYY() const
{
  return iYY;
}
//=============================================================================
void sstQt01PathElementCsvCls::setIYY(int value)
{
  iYY = value;
}
//=============================================================================
void sstQt01PathElementCsvCls::addIYY(int value)
{
  iYY = iYY + value;
}
//=============================================================================
int sstQt01PathElementCsvCls::getIColR() const
{
  return iColR;
}
//=============================================================================
void sstQt01PathElementCsvCls::setIColR(int value)
{
  iColR = value;
}
//=============================================================================
int sstQt01PathElementCsvCls::getIColG() const
{
  return iColG;
}
//=============================================================================
void sstQt01PathElementCsvCls::setIColG(int value)
{
  iColG = value;
}
//=============================================================================
int sstQt01PathElementCsvCls::getIColB() const
{
  return iColB;
}
//=============================================================================
void sstQt01PathElementCsvCls::setIColB(int value)
{
  iColB = value;
}
//=============================================================================
void sstQt01PathElementCsvCls::setQCol(QColor oQCol)
{
  oQCol.getRgb(&this->iColR,&this->iColG,&this->iColB);
}
//=============================================================================
QColor sstQt01PathElementCsvCls::getQCol()
{
  QColor oCol;
  oCol.setRgb(this->iColR,this->iColG,this->iColB);
  return oCol;
}
//=============================================================================
sstQt01PathMainRecCls::sstQt01PathMainRecCls()
{
  this->iColR = 0;        /**< Color Red */
  this->iColG = 0;        /**< Color Green */
  this->iColB = 0;        /**< Color Blue */
  memset(this->cTooltip,0,30);
  this->dStartElementRecNo = 0;  /**< Start of Path in Element table */
  this->dNumElements = 0;        /**< Number of elements in path */
  this->iXX = 0;
  this->iYY = 0;
}
//=============================================================================
int sstQt01PathMainRecCls::getIColR() const
{
  return iColR;
}
//=============================================================================
void sstQt01PathMainRecCls::setIColR(int value)
{
  iColR = value;
}
//=============================================================================
int sstQt01PathMainRecCls::getIColG() const
{
  return iColG;
}
//=============================================================================
void sstQt01PathMainRecCls::setIColG(int value)
{
  iColG = value;
}
//=============================================================================
int sstQt01PathMainRecCls::getIColB() const
{
  return iColB;
}
//=============================================================================
void sstQt01PathMainRecCls::setIColB(int value)
{
  iColB = value;
}
//=============================================================================
void sstQt01PathMainRecCls::setTooltip(std::string oTooltip)
{
  strncpy(this->cTooltip,oTooltip.c_str(),30);
}
//=============================================================================
std::string sstQt01PathMainRecCls::getTooltip()
{
  return this->cTooltip;
}
//=============================================================================
void sstQt01PathMainRecCls::setQCol(QColor oQCol)
{
  oQCol.getRgb(&this->iColR,&this->iColG,&this->iColB);
}
//=============================================================================
QColor sstQt01PathMainRecCls::getQCol()
{
  QColor oCol;
  oCol.setRgb(this->iColR,this->iColG,this->iColB);
  return oCol;
}
//=============================================================================
dREC04RECNUMTYP sstQt01PathMainRecCls::getStartElementRecNo() const
{
return dStartElementRecNo;
}
//=============================================================================
void sstQt01PathMainRecCls::setStartElementRecNo(const dREC04RECNUMTYP &value)
{
dStartElementRecNo = value;
}
//=============================================================================
dREC04RECNUMTYP sstQt01PathMainRecCls::getNumElements() const
{
return dNumElements;
}
//=============================================================================
void sstQt01PathMainRecCls::setNumElements(const dREC04RECNUMTYP &value)
{
  dNumElements = value;
}
//=============================================================================
dREC04RECNUMTYP sstQt01PathMainRecCls::getEndElementRecNo() const
{
return dStartElementRecNo+dNumElements-1;
}
//=============================================================================
void sstQt01PathMainRecCls::setPosition(QPoint oPosition)
{
  this->iXX = oPosition.rx();
  this->iYY = oPosition.ry();
}
//=============================================================================
QPoint sstQt01PathMainRecCls::getPosition()
{
  QPoint oPnt;
  oPnt.setX(this->iXX);
  oPnt.setY(this->iYY);
  return oPnt;
}
//=============================================================================
