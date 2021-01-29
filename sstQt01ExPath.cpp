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
// sstQt01ExPath.cpp    12.04.20  Re.    12.04.20  Re.
//
// sst extented Painter Path Class
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include <sstMath01Lib.h>
#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "sstQt01LibInt.h"

// #include "sstQt01ExPath.h"

//=============================================================================
sstQt01ExPath::sstQt01ExPath()
{}
//=============================================================================
// Copy Constructor
sstQt01ExPath::sstQt01ExPath(const sstQt01ExPath& oExPath)
{
  this->oPen = oExPath.oPen;
  this->oPath = oExPath.oPath;
  this->oBrush = oExPath.oBrush;
  this->oColor = oExPath.oColor;
}
//=============================================================================
// Equal-Operator
sstQt01ExPath sstQt01ExPath::operator=(const sstQt01ExPath& oExPath)
{
  if (this == &oExPath) return *this;
  this->oPen = oExPath.oPen;
  this->oPath = oExPath.oPath;
  this->oBrush = oExPath.oBrush;
  this->oColor = oExPath.oColor;
  return *this;
}
//=============================================================================
sstQt01ExPath::~sstQt01ExPath()
{}
//=============================================================================
QPainterPath sstQt01ExPath::getPath() const
{
  return oPath;
}
//=============================================================================
void sstQt01ExPath::setPath(const QPainterPath &value)
{
  oPath = value;
}
//=============================================================================
QColor sstQt01ExPath::getColor() const
{
  return oColor;
}
//=============================================================================
void sstQt01ExPath::setColor(const QColor &value)
{
  oColor = value;
}
//=============================================================================
QBrush sstQt01ExPath::getBrush() const
{
  return oBrush;
}
//=============================================================================
void sstQt01ExPath::setBrush(const QBrush &value)
{
  oBrush = value;
}
//=============================================================================
QPen sstQt01ExPath::getPen() const
{
  return oColor;
}
//=============================================================================
void sstQt01ExPath::setPen(const QPen &value)
{
  oPen = value;
}
//=============================================================================


