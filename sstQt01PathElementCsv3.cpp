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
// sstQt01PathElementCsv3.cpp    06.06.17  Re.    06.06.17  Re.
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
// #include <sstMath01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "sstQt01LibInt.h"

//=============================================================================
sstQt01PathElementCsv3Cls::sstQt01PathElementCsv3Cls()
{
  this->iType = 0;        /**< Shape Item Type */
  this->iXX = 0;          /**< Coordinate X */
  this->iYY = 0;          /**< Coordinate Y */
  this->iColR = 0;        /**< Color Red */
  this->iColG = 0;        /**< Color Green */
  this->iColB = 0;        /**< Color Blue */
  this->iPenWidth = 1;    /**< Pen Width */
  this->iPenStyle = 1;    /**< Pen Style */
  // memset(this->cItemType,0,11);
  this->eShapeType = eSstQt01PathUnknown;
}
//=============================================================================
int sstQt01PathElementCsv3Cls::ReadFromCsv(int iKey, std::string oCsvStr, std::string *oErrStr)
{
  sstStr01Cls oCsvCnvt;
  std::string sPathType;
  sstQt01ShapeTypeCls oPathTypeCnvt;
  sstQt01ShapeType_enum ePathType;

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
  if (iStat >= 0) iStat = oCsvCnvt.CsvString2_Int2( 0, &oCsvStr,&this->iPenWidth);
  if (iStat >= 0) iStat = oCsvCnvt.CsvString2_Int2( 0, &oCsvStr,&this->iPenStyle);
  if (iStat >= 0) iStat = oCsvCnvt.CsvString2_Str( 0, &oCsvStr,&sPathType);
  if (sPathType.length() > 0 && iStat >= 0)
  {
    iStat = oPathTypeCnvt.Str2Enm(0,sPathType,&ePathType);
    assert(iStat == 0);
    this->setShapeType(ePathType);
  }
  else
  {
    this->setShapeType(eSstQt01PathUnknown);
  }
  *oErrStr = oCsvCnvt.GetErrorString();
  return iStat;
}
//=============================================================================
int sstQt01PathElementCsv3Cls::WriteToCsv(int iKey, std::string *oCsvStr, std::string *oErrStr)
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
  if (iStat >= 0) iStat = oCsvCnvt.Csv_Int2_2String( 0, this->iPenWidth, oCsvStr);
  if (iStat >= 0) iStat = oCsvCnvt.Csv_Int2_2String( 0, this->iPenStyle, oCsvStr);
  if (iStat >= 0)
  {
    std::string sShapeType;
    sstQt01ShapeTypeCls oShapeTypeCnvt;
    iStat = oShapeTypeCnvt.Enm2Str(0,this->eShapeType,&sShapeType);
    if (iStat >= 0) iStat = oCsvCnvt.Csv_Str_2String( 0, sShapeType, oCsvStr);
  }
  *oErrStr = oCsvCnvt.GetErrorString();

  return iStat;
}
//=============================================================================
std::string sstQt01PathElementCsv3Cls::GetCsvFileTitle()
{
  std::string oLocStr;
  //-----------------------------------------------------------------------------

  oLocStr = "iType;iXX;iYY;iColR;iColG;iColB;iPenWidth;iPenStyle;cShapeType";

  return oLocStr;
}
//=============================================================================
void sstQt01PathElementCsv3Cls::setAll(int iTmpType,int iTmpXX, int iTmpYY, QColor oTmpCol)
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
void sstQt01PathElementCsv3Cls::setAll(int iTmpType,int iTmpXX, int iTmpYY, QColor oTmpCol, QPen oTmpPen)
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
  this->iPenStyle = (int) oTmpPen.style();
  this->iPenWidth = (int) oTmpPen.width();
}
//=============================================================================
int sstQt01PathElementCsv3Cls::getIType() const
{
  return iType;
}
//=============================================================================
void sstQt01PathElementCsv3Cls::setIType(int value)
{
  iType = value;
}
//=============================================================================
int sstQt01PathElementCsv3Cls::getIXX() const
{
  return iXX;
}
//=============================================================================
void sstQt01PathElementCsv3Cls::setIXX(int value)
{
  iXX = value;
}
//=============================================================================
void sstQt01PathElementCsv3Cls::addIXX(int value)
{
  iXX = iXX + value;
}
//=============================================================================
int sstQt01PathElementCsv3Cls::getIYY() const
{
  return iYY;
}
//=============================================================================
void sstQt01PathElementCsv3Cls::setIYY(int value)
{
  iYY = value;
}
//=============================================================================
void sstQt01PathElementCsv3Cls::addIYY(int value)
{
  iYY = iYY + value;
}
//=============================================================================
int sstQt01PathElementCsv3Cls::getIColR() const
{
  return iColR;
}
//=============================================================================
void sstQt01PathElementCsv3Cls::setIColR(int value)
{
  iColR = value;
}
//=============================================================================
int sstQt01PathElementCsv3Cls::getIColG() const
{
  return iColG;
}
//=============================================================================
void sstQt01PathElementCsv3Cls::setIColG(int value)
{
  iColG = value;
}
//=============================================================================
int sstQt01PathElementCsv3Cls::getIColB() const
{
  return iColB;
}
//=============================================================================
void sstQt01PathElementCsv3Cls::setIColB(int value)
{
  iColB = value;
}
//=============================================================================
void sstQt01PathElementCsv3Cls::setQCol(QColor oQCol)
{
  oQCol.getRgb(&this->iColR,&this->iColG,&this->iColB);
}
//=============================================================================
QColor sstQt01PathElementCsv3Cls::getQCol()
{
  QColor oCol;
  oCol.setRgb(this->iColR,this->iColG,this->iColB);
  return oCol;
}
//=============================================================================
int sstQt01PathElementCsv3Cls::getIPenWidth() const
{
return iPenWidth;
}
//=============================================================================
void sstQt01PathElementCsv3Cls::setIPenWidth(int value)
{
iPenWidth = value;
}
//=============================================================================
int sstQt01PathElementCsv3Cls::getIPenStyle() const
{
return iPenStyle;
}
//=============================================================================
void sstQt01PathElementCsv3Cls::setIPenStyle(int value)
{
iPenStyle = value;
}
//=============================================================================
unsigned int sstQt01PathElementCsv3Cls::ColumnCount()
{
  return 9;
}
//=============================================================================
void sstQt01PathElementCsv3Cls::setFromVers2(sstQt01PathElementCsv2Cls oShapeItemCsv2)
{
  this->iType = oShapeItemCsv2.getIType();        /**< Shape Item Type */
  this->iXX   = oShapeItemCsv2.getIXX();          /**< Coordinate X */
  this->iYY   = oShapeItemCsv2.getIYY();          /**< Coordinate Y */
  this->iColR = oShapeItemCsv2.getIColR();        /**< Color Red */
  this->iColG = oShapeItemCsv2.getIColG();        /**< Color Green */
  this->iColB = oShapeItemCsv2.getIColB();        /**< Color Blue */
  this->iPenWidth = oShapeItemCsv2.getIPenWidth();    /**< Pen Width */
  this->iPenStyle = oShapeItemCsv2.getIPenStyle();    /**< Pen Style */
}
//=============================================================================
sstQt01ShapeType_enum sstQt01PathElementCsv3Cls::getShapeType() const
{
  return eShapeType;
}
//=============================================================================
void sstQt01PathElementCsv3Cls::setShapeType(const sstQt01ShapeType_enum &value)
{
  eShapeType = value;
}
//=============================================================================
bool sstQt01PathElementCsv3Cls::isShapeType()
{
  switch (this->eShapeType)
  {
    case eSstQt01PathError:
    case eSstQt01PathUnknown:
        return false; break;
  default: return true; break;
  }
  return false;
}
//=============================================================================
