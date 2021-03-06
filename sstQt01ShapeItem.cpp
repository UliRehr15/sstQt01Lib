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
// sstQt01ShapeItem.cpp    24.11.18  Re.    14.08.16  Re.

#include <QtWidgets>

#include <assert.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

//=============================================================================
sstQt01ShapeItem::sstQt01ShapeItem()
{
  this->eShapeType = eSstQt01PathNoObj;
  this->dExternID = 0;
  this->dInternID = 0;
}
//=============================================================================
QPainterPath sstQt01ShapeItem::getPath() const
{
  return myPath;
}
//=============================================================================
QRectF sstQt01ShapeItem::getBoundingBox() const
{
    return myPath.boundingRect();
}
//=============================================================================
QPoint sstQt01ShapeItem::getPosition() const
{
    return myPosition;
}
//=============================================================================
QColor sstQt01ShapeItem::getColor() const
{
    return myColor;
}
//=============================================================================
QPen sstQt01ShapeItem::getPen() const
{
    return myPen;
}
//=============================================================================
QString sstQt01ShapeItem::getToolTip() const
{
    return myToolTip;
}
//=============================================================================
void sstQt01ShapeItem::setPath(const QPainterPath &path)
{
    myPath = path;
}
//=============================================================================
void sstQt01ShapeItem::setToolTip(const QString &toolTip)
{
    myToolTip = toolTip;
}
//=============================================================================
void sstQt01ShapeItem::setToolTip(const std::string &toolTip)
{
    QString oLocQStr;
    oLocQStr = QString::fromStdString(toolTip);
    myToolTip = oLocQStr;
}
//=============================================================================
void sstQt01ShapeItem::setPosition(const QPoint &position)
{
    myPosition = position;
}
//=============================================================================
void sstQt01ShapeItem::setColor(const QColor &color)
{
    myColor = color;
}
//=============================================================================
void sstQt01ShapeItem::setPen(const QPen &oPen)
{
    myPen = oPen;
}
//=============================================================================
void sstQt01ShapeItem::createShapeItem(const QPainterPath &path,
                                 const QString &toolTip, const QPoint &pos,
                                 const QColor &color,
                                 sstQt01ShapeType_enum eShapeType)
{
    this->setPath(path);
    this->setToolTip(toolTip);
    this->setPosition(pos);
    this->setColor(color);
    this->setShapeType(eShapeType);
}
//=============================================================================
sstQt01ShapeType_enum sstQt01ShapeItem::getShapeType() const
{
return eShapeType;
}
//=============================================================================
void sstQt01ShapeItem::setShapeType(const sstQt01ShapeType_enum &value)
{
eShapeType = value;
}
//=============================================================================
dREC04RECNUMTYP sstQt01ShapeItem::getExternId() const
{
  return dExternID;
}
//=============================================================================
void sstQt01ShapeItem::setExternId(const dREC04RECNUMTYP &value)
{
  dExternID = value;
}
//=============================================================================
int sstQt01ShapeItem::getSize()
{
  return this->myPath.elementCount();
}
//=============================================================================
void sstQt01ShapeItem::updatePosition()
{
  this->myPath.translate(this->getPosition());
  QPoint oPoint(0,0);
  this->setPosition(oPoint);
}
//=============================================================================
std::string sstQt01ShapeItem::getExternStr() const
{
return oExternStr;
}
//=============================================================================
void sstQt01ShapeItem::setExternStr(const std::string &value)
{
oExternStr = value;
}
//=============================================================================
dREC04RECNUMTYP sstQt01ShapeItem::getInternId() const
{
  return dInternID;
}
//=============================================================================
void sstQt01ShapeItem::setInternId(const dREC04RECNUMTYP &value)
{
  dInternID = value;
}
//=============================================================================
bool sstQt01ShapeItem::getFirstPathElement(QPainterPath::Element *oElement) const
{
  if (this->myPath.elementCount() == 0) return false;
  *oElement = this->myPath.elementAt(0);
  return true;
}
//=============================================================================
sstMath01dPnt2Cls sstQt01ShapeItem::getInitPos() const
{
return oInitPos;
}
//=============================================================================
void sstQt01ShapeItem::setInitPos(const sstMath01dPnt2Cls &value)
{
oInitPos = value;
}
//=============================================================================
