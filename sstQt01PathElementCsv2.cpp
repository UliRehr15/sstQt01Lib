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
// sstQt01PathElementCsv2.cpp    06.06.17  Re.    06.06.17  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include <QtWidgets>
#include <QTreeView>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QTextBrowser>
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
sstQt01PathElementCsv2Cls::sstQt01PathElementCsv2Cls()
{
  this->iType = 0;        /**< Shape Item Type */
  this->iXX = 0;          /**< Coordinate X */
  this->iYY = 0;          /**< Coordinate Y */
  this->iColR = 0;        /**< Color Red */
  this->iColG = 0;        /**< Color Green */
  this->iColB = 0;        /**< Color Blue */
  this->iPenWidth = 1;    /**< Pen Width */
  this->iPenStyle = 1;    /**< Pen Style */
}
//=============================================================================
int sstQt01PathElementCsv2Cls::ReadFromCsv(int iKey, std::string oCsvStr, std::string *oErrStr)
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
  if (iStat >= 0) iStat = oCsvCnvt.CsvString2_Int2( 0, &oCsvStr,&this->iPenWidth);
  if (iStat >= 0) iStat = oCsvCnvt.CsvString2_Int2( 0, &oCsvStr,&this->iPenStyle);
  *oErrStr = oCsvCnvt.GetErrorString();
  return iStat;
}
//=============================================================================
int sstQt01PathElementCsv2Cls::WriteToCsv(int iKey, std::string *oCsvStr, std::string *oErrStr)
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
  *oErrStr = oCsvCnvt.GetErrorString();

  return iStat;
}
//=============================================================================
std::string sstQt01PathElementCsv2Cls::GetCsvFileTitle()
{
  std::string oLocStr;
  //-----------------------------------------------------------------------------

  oLocStr = "iType;iXX;iYY;iColR;iColG;iColB;iPenWidth;iPenStyle";

  return oLocStr;
}
//=============================================================================
void sstQt01PathElementCsv2Cls::setAll(int iTmpType,int iTmpXX, int iTmpYY, QColor oTmpCol)
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
void sstQt01PathElementCsv2Cls::setAll(int iTmpType,int iTmpXX, int iTmpYY, QColor oTmpCol, QPen oTmpPen)
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
int sstQt01PathElementCsv2Cls::getIType() const
{
  return iType;
}
//=============================================================================
void sstQt01PathElementCsv2Cls::setIType(int value)
{
  iType = value;
}
//=============================================================================
int sstQt01PathElementCsv2Cls::getIXX() const
{
  return iXX;
}
//=============================================================================
void sstQt01PathElementCsv2Cls::setIXX(int value)
{
  iXX = value;
}
//=============================================================================
void sstQt01PathElementCsv2Cls::addIXX(int value)
{
  iXX = iXX + value;
}
//=============================================================================
int sstQt01PathElementCsv2Cls::getIYY() const
{
  return iYY;
}
//=============================================================================
void sstQt01PathElementCsv2Cls::setIYY(int value)
{
  iYY = value;
}
//=============================================================================
void sstQt01PathElementCsv2Cls::addIYY(int value)
{
  iYY = iYY + value;
}
//=============================================================================
int sstQt01PathElementCsv2Cls::getIColR() const
{
  return iColR;
}
//=============================================================================
void sstQt01PathElementCsv2Cls::setIColR(int value)
{
  iColR = value;
}
//=============================================================================
int sstQt01PathElementCsv2Cls::getIColG() const
{
  return iColG;
}
//=============================================================================
void sstQt01PathElementCsv2Cls::setIColG(int value)
{
  iColG = value;
}
//=============================================================================
int sstQt01PathElementCsv2Cls::getIColB() const
{
  return iColB;
}
//=============================================================================
void sstQt01PathElementCsv2Cls::setIColB(int value)
{
  iColB = value;
}
//=============================================================================
void sstQt01PathElementCsv2Cls::setQCol(QColor oQCol)
{
  oQCol.getRgb(&this->iColR,&this->iColG,&this->iColB);
}
//=============================================================================
QColor sstQt01PathElementCsv2Cls::getQCol()
{
  QColor oCol;
  oCol.setRgb(this->iColR,this->iColG,this->iColB);
  return oCol;
}
//=============================================================================
int sstQt01PathElementCsv2Cls::getIPenWidth() const
{
return iPenWidth;
}
//=============================================================================
void sstQt01PathElementCsv2Cls::setIPenWidth(int value)
{
iPenWidth = value;
}
//=============================================================================
int sstQt01PathElementCsv2Cls::getIPenStyle() const
{
return iPenStyle;
}
//=============================================================================
void sstQt01PathElementCsv2Cls::setIPenStyle(int value)
{
iPenStyle = value;
}
//=============================================================================
unsigned int sstQt01PathElementCsv2Cls::ColumnCount()
{
  return 8;
}
//=============================================================================
void sstQt01PathElementCsv2Cls::setFromVers1(sstQt01PathElementCsv1Cls oShapeItemCsv1)
{
  this->iType = oShapeItemCsv1.getIType();        /**< Shape Item Type */
  this->iXX   = oShapeItemCsv1.getIXX();          /**< Coordinate X */
  this->iYY   = oShapeItemCsv1.getIYY();          /**< Coordinate Y */
  this->iColR = oShapeItemCsv1.getIColR();        /**< Color Red */
  this->iColG = oShapeItemCsv1.getIColG();        /**< Color Green */
  this->iColB = oShapeItemCsv1.getIColB();        /**< Color Blue */
  // this->iPenWidth;    /**< Pen Width */
  // this->iPenStyle;    /**< Pen Style */
}
//=============================================================================
