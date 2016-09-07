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
// sortingbox.h    14.08.16  Re.    14.08.16  Re.

#ifndef SORTINGBOX_H
#define SORTINGBOX_H

#include <QWidget>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "sstQt01LibTestView.h"
#include "shapeitem.h"

QT_BEGIN_NAMESPACE
class QAction;
class QPoint;
class QToolButton;
QT_END_NAMESPACE

//! [0]
class SortingBox : public QWidget
{
    Q_OBJECT

public:
  SortingBox();
  ~SortingBox();

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void createNewCircle();
    void createNewSquare();
    void createNewTriangle();
//! [0]

//! [1]
private:
    int updateButtonGeometry(QToolButton *button, int x, int y);
    void createShapeItem(const QPainterPath &path, const QString &toolTip,
                         const QPoint &pos, const QColor &color);
    int itemAt(const QPoint &pos);
    void moveItemTo(const QPoint &pos);
    int ItemsLoadFromFile (int iKey, sstMisc01AscFilCls *oPainterCsvFile);
    int ItemsLoadFromFile2 (int iKey, sstMisc01AscFilCls *oPainterCsvFile);
    int ItemsLoadFromFile3 (int iKey);
    int ItemsCreate (int iKey);
    QPoint initialItemPosition(const QPainterPath &path);
    QPoint randomItemPosition();
    QColor initialItemColor();
    QColor randomItemColor();
    QToolButton *createToolButton(const QString &toolTip, const QIcon &icon,
//! [1]
                                  const char *member);

//! [2]
    QList<ShapeItem> shapeItems;
    QPainterPath circlePath;
    QPainterPath squarePath;
    QPainterPath trianglePath;

    QPoint previousPosition;
    ShapeItem *itemInMotion;

    QToolButton *newCircleButton;
    QToolButton *newSquareButton;
    QToolButton *newTriangleButton;
    sstQt01PathStorageCls *oPathStorage;
};
//! [2]

#endif
