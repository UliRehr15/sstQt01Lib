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
// sstQt01MapPath.cpp   12.01.21  Re.   12.01.21  Re.

#include <list>

#include <QtWidgets>
#include <QFont>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "sstQt01LibInt.h"

#include <QtWidgets>

sstQt01MapPath::sstQt01MapPath(const QColor &color, int x, int y, const sstQt01ShapeItem2 oTmpExtPathList)
{
    this->x = x;
    this->y = y;
    this->color = color;
    setZValue((x + y) % 2);  // Calculate high of symbol for moving and hiding with other symbols

    this->oExtPathList = oTmpExtPathList;

    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptHoverEvents(true);

    this->oBoundingRect = oTmpExtPathList.getBoundingBox();
}

QRectF sstQt01MapPath::boundingRect() const
{
  return oBoundingRect;
}

QPainterPath sstQt01MapPath::shape() const
{
    QPainterPath path;
    path.addRect(oBoundingRect);
    return path;
}

void sstQt01MapPath::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
  int iStat = 0;

  QColor fillColor = (option->state & QStyle::State_Selected) ? color.darker(150) : color;
  if (option->state & QStyle::State_MouseOver)
      fillColor = fillColor.lighter(125);

  // Level of detail
  // const qreal lod = option->levelOfDetailFromTransform(painter->worldTransform());

    QPen oldPen = painter->pen();
    QPen pen = oldPen;
    int width = 5;
    if (option->state & QStyle::State_Selected)
        width += 2;
    if (this->oExtPathList.getShapeType() == eSstQt01PathObject)
      iStat = 0;

    pen.setWidth(width);
    QBrush b = painter->brush();

    sstQt01ExPath oMyExtPath;

    std::list <sstQt01ExPath> oPathList;  /**< List of extended Painter Path objects */

    oExtPathList.resetReading();

    oPathList = oExtPathList.getList();

//    while (oExtPathList.readNext(&oMyExtPath) == true)
//    {
//      QColor oExtPathColor = oMyExtPath.getColor();
//      fillColor = (option->state & QStyle::State_Selected) ? oExtPathColor.darker(150) : oExtPathColor;
//      if (option->state & QStyle::State_MouseOver)
//        fillColor = fillColor.lighter(125);
//      painter->setPen(pen);
//      painter->setBrush(Qt::NoBrush);

//      QPainterPath oPath1 = oMyExtPath.getPath();
//      QPainterPath::Element oElement;
//      oElement = oPath1.elementAt(0);
//      int iNumEle = oPath1.elementCount();
//      painter->drawPath(oPath1);
//    }


    // for(std::list<sstQt01ExPath>::iterator pos=oExtPathList.begin();pos!=oExtPathList.end();++pos)
    for( std::list<sstQt01ExPath>::iterator pos=oPathList.begin();pos!=oPathList.end();++pos)
    {
      sstQt01ExPath oMyExtPath = *pos;
      QColor oExtPathColor = oMyExtPath.getColor();
      fillColor = (option->state & QStyle::State_Selected) ? oExtPathColor.darker(150) : oExtPathColor;
      if (option->state & QStyle::State_MouseOver)
          fillColor = fillColor.lighter(125);
      painter->setPen(pen);
      painter->setBrush(Qt::NoBrush);

      QPainterPath oPath1 = oMyExtPath.getPath();
      QPainterPath::Element oElement;
      oElement = oPath1.elementAt(0);
      // int iNumEle = oPath1.elementCount();

      painter->drawPath(oMyExtPath.getPath());
    }

    // Draw red ink
    if (stuff.size() > 1) {
        QPen p = painter->pen();
        painter->setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter->setBrush(Qt::NoBrush);
        QPainterPath path;
        path.moveTo(stuff.first());
        for (int i = 1; i < stuff.size(); ++i)
            path.lineTo(stuff.at(i));
        painter->drawPath(path);
        painter->setPen(p);
    }
}

void sstQt01MapPath::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void sstQt01MapPath::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void sstQt01MapPath::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}

