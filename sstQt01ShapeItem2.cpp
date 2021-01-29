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
// sstQt01ShapeItem2.cpp    24.11.18  Re.    14.08.16  Re.

#include <QtWidgets>

#include <assert.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "sstQt01LibInt.h"

// #include "sstQt01ExPath.h"
//#include "sstQt01MapPath.h"
//#include "MainWindow.h"
//#include "sstQt01View.h"
//#include "tonQtPtss01ViewTest.h"
//#include "sstQt01ShapeItem2.h"

//=============================================================================
sstQt01ShapeItem2::sstQt01ShapeItem2()
{
  this->eShapeType = eSstQt01PathNoObj;
  this->dExternID = 0;
  this->dInternID = 0;
  this->pos = oExtPathList.begin();
  this->oBoundingBox.setCoords(0,0,0,0);
}
//=============================================================================
sstQt01ShapeItem2::sstQt01ShapeItem2(const sstQt01ShapeItem2& oItem2)
{
  this->eShapeType = oItem2.eShapeType;
  this->dExternID = oItem2.dExternID;
  this->dInternID = oItem2.dInternID;
  this->pos = oItem2.pos;
  this->oBoundingBox = oItem2.oBoundingBox;
  this->oInitPos = oItem2.oInitPos;
  this->myToolTip = oItem2.myToolTip;
  this->myPosition = oItem2.myPosition;
  this->oExternStr = oItem2.oExternStr;
  this->oExtPathList = oItem2.oExtPathList;
}
//=============================================================================
sstQt01ShapeItem2 sstQt01ShapeItem2::operator=(const sstQt01ShapeItem2& oItem2)
{
  if(this == &oItem2) return *this;

  this->eShapeType = oItem2.eShapeType;
  this->dExternID = oItem2.dExternID;
  this->dInternID = oItem2.dInternID;
  this->pos = oItem2.pos;
  this->oBoundingBox = oItem2.oBoundingBox;
  this->oInitPos = oItem2.oInitPos;
  this->myToolTip = oItem2.myToolTip;
  this->myPosition = oItem2.myPosition;
  this->oExternStr = oItem2.oExternStr;
  this->oExtPathList = oItem2.oExtPathList;
  return *this;
}
//QPainterPath sstQt01ShapeItem2::getPath() const
//{
//  return myPath;
//}
//=============================================================================
QRectF sstQt01ShapeItem2::getBoundingBox() const
{
    return oBoundingBox;
}
//=============================================================================
QPoint sstQt01ShapeItem2::getPosition() const
{
    return myPosition;
}
//=============================================================================
//QColor sstQt01ShapeItem2::getColor() const
//{
//    return myColor;
//}
//=============================================================================
//QPen sstQt01ShapeItem2::getPen() const
//{
//    return myPen;
//}
//=============================================================================
QString sstQt01ShapeItem2::getToolTip() const
{
    return myToolTip;
}
//=============================================================================
void sstQt01ShapeItem2::setPath(const sstQt01ExPath &oExtPath)
{
    // myPath = path;
    oExtPathList.push_back(oExtPath);
    QPainterPath oPath = oExtPath.getPath();
    if (oPath.elementCount() > 0)
      oBoundingBox = oBoundingBox.united(oPath.boundingRect());
}
//=============================================================================
void sstQt01ShapeItem2::setToolTip(const QString &toolTip)
{
    myToolTip = toolTip;
}
//=============================================================================
void sstQt01ShapeItem2::setToolTip(const std::string &toolTip)
{
    QString oLocQStr;
    oLocQStr = QString::fromStdString(toolTip);
    myToolTip = oLocQStr;
}
//=============================================================================
void sstQt01ShapeItem2::setPosition(const QPoint &position)
{
    myPosition = position;
}
//=============================================================================
//void sstQt01ShapeItem2::setColor(const QColor &color)
//{
//    myColor = color;
//}
//=============================================================================
//void sstQt01ShapeItem2::setPen(const QPen &oPen)
//{
//    myPen = oPen;
//}
//=============================================================================
void sstQt01ShapeItem2::createShapeItem(const sstQt01ExPath &oExPath,
                                 const QString &toolTip, const QPoint &pos,
                                 const QColor &color,
                                 sstQt01ShapeType_enum eShapeType)
{
    this->setPath(oExPath);
    this->setToolTip(toolTip);
    this->setPosition(pos);
    // this->setColor(color);
    this->setShapeType(eShapeType);
}
//=============================================================================
sstQt01ShapeType_enum sstQt01ShapeItem2::getShapeType() const
{
return eShapeType;
}
//=============================================================================
void sstQt01ShapeItem2::setShapeType(const sstQt01ShapeType_enum &value)
{
eShapeType = value;
}
//=============================================================================
dREC04RECNUMTYP sstQt01ShapeItem2::getExternId() const
{
  return dExternID;
}
//=============================================================================
void sstQt01ShapeItem2::setExternId(const dREC04RECNUMTYP &value)
{
  dExternID = value;
}
//=============================================================================
int sstQt01ShapeItem2::getSize()
{
  // return this->myPath.elementCount();
  return 0;
}
//=============================================================================
void sstQt01ShapeItem2::updatePosition()
{
  // this->myPath.translate(this->getPosition());
  QPoint oPoint(0,0);
  this->setPosition(oPoint);
}
//=============================================================================
std::string sstQt01ShapeItem2::getExternStr() const
{
return oExternStr;
}
//=============================================================================
void sstQt01ShapeItem2::setExternStr(const std::string &value)
{
oExternStr = value;
}
//=============================================================================
dREC04RECNUMTYP sstQt01ShapeItem2::getInternId() const
{
  return dInternID;
}
//=============================================================================
void sstQt01ShapeItem2::setInternId(const dREC04RECNUMTYP &value)
{
  dInternID = value;
}
//=============================================================================
bool sstQt01ShapeItem2::getFirstPathElement(QPainterPath::Element *oElement) const
{
  // if (this->myPath.elementCount() == 0) return false;
  // *oElement = this->myPath.elementAt(0);
  return true;
}
//=============================================================================
sstMath01dPnt2Cls sstQt01ShapeItem2::getInitPos() const
{
return oInitPos;
}
//=============================================================================
void sstQt01ShapeItem2::setInitPos(const sstMath01dPnt2Cls &value)
{
oInitPos = value;
}
//=============================================================================
void sstQt01ShapeItem2::resetReading()
{
  this->pos = oExtPathList.begin();
}
//=============================================================================
bool sstQt01ShapeItem2::readNext(sstQt01ExPath *oMyExtPath)
{
 if(this->pos == oExtPathList.end()) return false;
 *oMyExtPath = *this->pos;
 std::advance(this->pos, 1);
 // this->pos++;
 return true;
}
//=============================================================================
    std::list <sstQt01ExPath> sstQt01ShapeItem2::getList()
    {
      return this->oExtPathList;
    }
//=============================================================================
