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
// sstQt01ShapeItem.cpp    26.01.17  Re.    14.08.16  Re.

#include <QtWidgets>

#include <assert.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

//=============================================================================
QPainterPath sstQt01ShapeItem::getPath() const
{
    return myPath;
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