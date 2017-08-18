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
// sstQt01PathPaintWidgetCls.cpp    26.04.17  Re.    14.08.16  Re.

#include <QtWidgets>

#include <stdlib.h>
#include <assert.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

//=============================================================================
sstQt01PathPaintWidgetCls::sstQt01PathPaintWidgetCls(sstMisc01PrtFilCls    *poTmpPrt,
                                                     sstQt01PathStorageCls *poTmpPathStorage)
{

  Q_INIT_RESOURCE(tooltips);

  if (poTmpPathStorage == NULL) assert (0);
  if (poTmpPathStorage->countItems() <= 0) assert(0);

  this->oPathStorage = poTmpPathStorage;
  this->poPrt = poTmpPrt;

  int iStat = 0;

  // Write tooltip strings to path items
  iStat = this->ItemsLoadFromFile3(0);
  assert(iStat == 0);

  setMouseTracking(true);
    setBackgroundRole(QPalette::Base);

    newCircleButton = createToolButton(tr("New Circle"),
                                       QIcon(":/images/circle.png"),
                                       SLOT(createNewCircle()));

    newSquareButton = createToolButton(tr("New Square"),
                                       QIcon(":/images/square.png"),
                                       SLOT(createNewSquare()));

    newTriangleButton = createToolButton(tr("New Triangle"),
                                         QIcon(":/images/triangle.png"),
                                         SLOT(createNewTriangle()));

    newLineButton = createToolButton(tr("New Line"),
                                         QIcon(":/images/line.png"),
                                         SLOT(createNewLine()));

    //=============================================================================
    // Create item templates
    circlePath.addEllipse(QRect(0, 0, 100, 100));
    squarePath.addRect(QRect(0, 0, 100, 100));

    qreal x = trianglePath.currentPosition().x();
    qreal y = trianglePath.currentPosition().y();
    trianglePath.moveTo(x + 120 / 2, y);
    trianglePath.lineTo(0, 100);
    trianglePath.lineTo(120, 100);
    trianglePath.lineTo(x + 120 / 2, y);

    linePath.moveTo( 0, 0);
    linePath.lineTo(100, 100);
    //=============================================================================

    setWindowTitle(tr("Tool Tips"));
    resize(500, 300);

    iActualItemIndex = 0;
    iItemInMotionIndex = 0;

}
//=============================================================================
sstQt01PathPaintWidgetCls::~sstQt01PathPaintWidgetCls()
{

}
//=============================================================================
bool sstQt01PathPaintWidgetCls::event(QEvent *event)
{
    if (event->type() == QEvent::ToolTip) {
        QHelpEvent *helpEvent = static_cast<QHelpEvent *>(event);
        int index = itemAt(helpEvent->pos());
        if (index != -1)
        {
          QToolTip::showText(helpEvent->globalPos(), (QString) this->oPathStorage->getToolTip(index));
        } else {
            QToolTip::hideText();
            event->ignore();
        }

        return true;
    }
    return QWidget::event(event);
}
//=============================================================================
void sstQt01PathPaintWidgetCls::resizeEvent(QResizeEvent * /* event */)
{
    int margin = style()->pixelMetric(QStyle::PM_DefaultTopLevelMargin);
    int x = width() - margin;
    int y = height() - margin;

    y = updateButtonGeometry(newCircleButton, x, y);
    y = updateButtonGeometry(newSquareButton, x, y);
    y = updateButtonGeometry(newTriangleButton, x, y);
    updateButtonGeometry(newLineButton, x, y);
}
//=============================================================================
void sstQt01PathPaintWidgetCls::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int iPathCount = (int) this->oPathStorage->countItems();
    for (int ii=1; ii <= iPathCount; ii++)
    {
        painter.translate(this->oPathStorage->getPosition(ii));
        painter.setBrush(this->oPathStorage->getColor(ii));
        painter.drawPath(this->oPathStorage->getPath(ii));
        painter.translate(-this->oPathStorage->getPosition(ii));
    }
}
//=============================================================================
void sstQt01PathPaintWidgetCls::sstPaintEvent()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int iPathCount = (int) this->oPathStorage->countItems();
    for (int ii=1; ii <= iPathCount; ii++)
    {
        painter.translate(this->oPathStorage->getPosition(ii));
        painter.setBrush(this->oPathStorage->getColor(ii));
        painter.drawPath(this->oPathStorage->getPath(ii));
        painter.translate(-this->oPathStorage->getPosition(ii));
    }
}
//=============================================================================
void sstQt01PathPaintWidgetCls::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        int index = itemAt(event->pos());
        if (index != -1)
        {
          iActualItemIndex = index;
          iItemInMotionIndex = index;

          oActualItem = this->oPathStorage->getShapeItem(index);
          // itemInMotion = &oActualItem;
            previousPosition = event->pos();
            // Move acual item to end of list. Will be found first with mouse
            //shapeItems.move(index, shapeItems.size() - 1);
            update();
        }
    }
}
//=============================================================================
void sstQt01PathPaintWidgetCls::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && iItemInMotionIndex > 0)
        moveItemTo(event->pos());
}
//=============================================================================
void sstQt01PathPaintWidgetCls::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && iItemInMotionIndex > 0)
    {
        moveItemTo(event->pos());
        this->oPathStorage->addPosition(this->iActualItemIndex);
        iItemInMotionIndex = 0;
    }
    emit PathMoveEvent();
}
//=============================================================================
void sstQt01PathPaintWidgetCls::createNewCircle()
{
    static int count = 1;
    createShapeItem(circlePath, tr("Circle <%1>").arg(++count),
                    randomItemPosition(), randomItemColor());
}
//=============================================================================
void sstQt01PathPaintWidgetCls::createNewSquare()
{
    static int count = 1;
    createShapeItem(squarePath, tr("Square <%1>").arg(++count),
                    randomItemPosition(), randomItemColor());
}
//=============================================================================
void sstQt01PathPaintWidgetCls::createNewTriangle()
{
    static int count = 1;
    createShapeItem(trianglePath, tr("Triangle <%1>").arg(++count),
                    randomItemPosition(), randomItemColor());
}
//=============================================================================
void sstQt01PathPaintWidgetCls::createNewLine()
{
    static int count = 1;
    createShapeItem(linePath, tr("Line <%1>").arg(++count),
                    randomItemPosition(), randomItemColor());
}
//=============================================================================
int sstQt01PathPaintWidgetCls::itemAt(const QPoint &pos)
{
  for (int i = this->oPathStorage->countItems(); i >= 1; --i)
  {
      const sstQt01ShapeItem &item = this->oPathStorage->getShapeItem(i);
      if (item.getBoundingBox().contains(pos - item.getPosition()))
          return i;
  }
    return -1;
}
//=============================================================================
void sstQt01PathPaintWidgetCls::moveItemTo(const QPoint &pos)
{
  QPoint offset = pos - previousPosition;
  QPoint oItemPos = this->oPathStorage->getPosition(iItemInMotionIndex);
    this->oPathStorage->setPosition(this->iActualItemIndex, oItemPos + offset);
    previousPosition = pos;
    update();
}
//=============================================================================
int sstQt01PathPaintWidgetCls::updateButtonGeometry(QToolButton *button, int x, int y)
{
    QSize size = button->sizeHint();
    button->setGeometry(x - size.rwidth(), y - size.rheight(),
                        size.rwidth(), size.rheight());

    return y - size.rheight()
           - style()->pixelMetric(QStyle::PM_DefaultLayoutSpacing);
}
//=============================================================================
void sstQt01PathPaintWidgetCls::createShapeItem(const QPainterPath &path,
                                 const QString &toolTip, const QPoint &pos,
                                 const QColor &color)
{
    sstQt01ShapeItem shapeItem;
    shapeItem.setPath(path);
    shapeItem.setToolTip(toolTip);
    shapeItem.setPosition(pos);
    shapeItem.setColor(color);
    this->oPathStorage->appendShapeItem(shapeItem);
    update();
}
//=============================================================================
QToolButton *sstQt01PathPaintWidgetCls::createToolButton(const QString &toolTip,
                                          const QIcon &icon, const char *member)
{
    QToolButton *button = new QToolButton(this);
    button->setToolTip(toolTip);
    button->setIcon(icon);
    button->setIconSize(QSize(32, 32));
    connect(button, SIGNAL(clicked()), this, member);

    return button;
}
//=============================================================================
QPoint sstQt01PathPaintWidgetCls::initialItemPosition(const QPainterPath &path)
{
  int x = 0;
  int y = 0;
    y = (height() - (int)path.controlPointRect().height()) / 2;
    if (this->oPathStorage->countItems() == 0)
        x = ((3 * width()) / 2 - (int)path.controlPointRect().width()) / 2;
    else
      x = (width() / this->oPathStorage->countItems()
             - (int)path.controlPointRect().width()) / 2;

    return QPoint(x, y);
}
//=============================================================================
QPoint sstQt01PathPaintWidgetCls::randomItemPosition()
{
    return QPoint(qrand() % (width() - 120), qrand() % (height() - 120));
}
//=============================================================================
QColor sstQt01PathPaintWidgetCls::initialItemColor()
{
  return QColor::fromHsv(((this->oPathStorage->countItems() + 1) * 85) % 256, 255, 190);
}
//=============================================================================
QColor sstQt01PathPaintWidgetCls::randomItemColor()
{
    return QColor::fromHsv(qrand() % 256, 255, 190);
}
//=============================================================================
int sstQt01PathPaintWidgetCls::ItemsLoadFromFile3 (int iKey)
//-----------------------------------------------------------------------------
{
  QPoint oPnt(0,0);
  QPainterPath *poPath;
  QColor oColor;
  int iPathNo = 0;

  int iRet  = 0;
  int iStat = 0;
  int iStat1 = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // read next path from shape item table
  poPath = new (QPainterPath);
  iStat1 = this->oPathStorage->ReadNextPath( 0, poPath, &oColor);

  while (iStat1 >= 0)
  {
    iPathNo++;
    int iElements = poPath->elementCount();
    switch (iElements)
    {
    case 2:
    this->oPathStorage->setToolTip( iPathNo, tr("Line"));
    break;
    case 4:
    this->oPathStorage->setToolTip( iPathNo, tr("Triangle"));
    break;
    case 5:
      this->oPathStorage->setToolTip( iPathNo, tr("Square"));
      break;
    case 13:
      this->oPathStorage->setToolTip( iPathNo, tr("Circle"));
      break;
    default:
      assert(0);
      break;
    }

    delete poPath;
    poPath = new (QPainterPath);
    iStat1 = this->oPathStorage->ReadNextPath( 0, poPath, &oColor);
  }

  delete poPath;

  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstQt01PathPaintWidgetCls::ItemsCreate (int iKey)
//-----------------------------------------------------------------------------
{
  QColor oColor;
  QPoint oPos;
  int iRet  = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  createShapeItem(circlePath, tr("Circle"), initialItemPosition(circlePath),
                  initialItemColor());
  createShapeItem(squarePath, tr("Square"), initialItemPosition(squarePath),
                  initialItemColor());
  createShapeItem(trianglePath, tr("Triangle"),
                  initialItemPosition(trianglePath), initialItemColor());
  createShapeItem(linePath, tr("Line"),
                  initialItemPosition(linePath), initialItemColor());

  return iRet;
}
//=============================================================================
QSize sstQt01PathPaintWidgetCls::minimumSizeHint() const
{
    return QSize(100, 100);
}
//=============================================================================
QSize sstQt01PathPaintWidgetCls::sizeHint() const
{
    return QSize(400, 200);
}
//=============================================================================
