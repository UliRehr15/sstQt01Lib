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
// sstQt01_tstrec1_TabMdl.cpp   16.09.15  Re.    16.09.15  Re.
//
// qt model and View for dss Table testrec1

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

//=============================================================================
TstRec1ModelCls::TstRec1ModelCls(QObject *parent)
    :sstQt01TabMdlCls(parent)
{
  int iStat = 0;
  dREC04RECNUMTYP dLocRecNo = 0;
  sstRec04TestRec1Cls oLocTestRec;
  iStat = oTestRec1Table.OpenReadCsvFile(0,(char*) "test_rec1.csv");

  if (iStat == -2)
  {  // File not found
    iStat = oLocTestRec.SetAll(33,(char*) "Test");
    iStat = oTestRec1Table.WriteNew(0,&dLocRecNo,&oLocTestRec);
    assert(iStat == 0);
  }

  dREC04RECNUMTYP dRecNum = oTestRec1Table.RecordCount();
  if (dRecNum == 0)
  {  // File found, but empty
    iStat = oLocTestRec.SetAll(33,(char*) "Test");
    iStat = oTestRec1Table.WriteNew(0,&dLocRecNo,&oLocTestRec);
    assert(iStat == 0);
  }

  dRecNum = oTestRec1Table.RecordCount();
  for (dREC04RECNUMTYP ll=1; ll<=dRecNum; ++ll)
  {
    this->sstTabVector.push_back(ll);;
  }

  // Fatal Errors goes to an assert
  if (iStat < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
TstRec1ModelCls::~TstRec1ModelCls()
{
  oTestRec1Table.CloseCsvFile(0,(char*) "test_rec1.csv");
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int TstRec1ModelCls::rowCount(const QModelIndex & /*parent*/) const
{
  return oTestRec1Table.RecordCount();
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int TstRec1ModelCls::columnCount(const QModelIndex & /*parent*/) const
{
    return 2;
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
QVariant TstRec1ModelCls::data(const QModelIndex &index, int role) const
{
  // int row = index.row();
  int col = index.column();

  switch(role){
  case Qt::DisplayRole:
    {
      sstRec04TestRec1Cls oTestRec1;

      int iStat = oTestRec1Table.ReadRecPos ( 0, this->sstTabVector[index.row()], &oTestRec1);
      assert (iStat == 0);

      switch (index.column())
      {
      // case 0:  return QString::number(oTestRec1.dVal, 'f', 4); break;
      case 0:  return oTestRec1.iVal;
      case 1:  return QString::fromUtf8( oTestRec1.cVal); break;
      default: return QString("Row%1, Column%2").arg(index.row() + 1).arg(index.column() +1); break;
      }
    }
  case Qt::FontRole:
      if (col == 5) //change font only for cell(0,0)
      {
          QFont boldFont;
          boldFont.setBold(true);
          return boldFont;
      }
      break;
    }
    return QVariant();
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
QVariant TstRec1ModelCls::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Int2");
            case 1:
                return QString("Character");
            }
        }
    }
    return QVariant();
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
bool TstRec1ModelCls::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (role == Qt::EditRole)
    {
        //save value from editor to oTestRecDss
      sstRec04TestRec1Cls oTestRec1;

      dREC04RECNUMTYP dRecNo = index.row() +1;
      oTestRec1Table.ReadRecPos ( 0, this->sstTabVector[index.row()], &oTestRec1);

      bool bOK = 1;

      switch (index.column())
      {
      // case 0: oTestRec1.dVal = value.toDouble(&bOK); break;
      case 0: oTestRec1.iVal = value.toInt(&bOK); break;
      case 1:
        {
          QString locStr = value.toString();
          strncpy(oTestRec1.cVal, locStr.toUtf8(),10);
          break;
        }
      }

      if (bOK) oTestRec1Table.WriteRecPos( 0, dRecNo, &oTestRec1);

    }
    return true;
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
Qt::ItemFlags TstRec1ModelCls::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}
//=============================================================================
bool TstRec1ModelCls::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    // rows is always = 1 at the moment
    // Position is 0 > n-1

    for (int row = 0; row < rows; ++row) {
      oTestRec1Table.DeleteRecPos(0,position+1);
    }
    endRemoveRows();

    this->sstTabVector.erase (this->sstTabVector.begin()+position);

    return true;
}
//=============================================================================
bool TstRec1ModelCls::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    // rows is always = 1 at the moment
    // Position is 0 > n-1
    dREC04RECNUMTYP dRecNo = 0;

    for (int row = 0; row < rows; ++row) {
      sstRec04TestRec1Cls oTestRec;
      oTestRec1Table.ReadRecPos(0,oTestRec1Table.RecordCount(),&oTestRec);
      oTestRec1Table.WriteNew(0,&dRecNo,&oTestRec);
    }

    endInsertRows();

    this->sstTabVector.push_back(dRecNo);

    return true;
}
//=============================================================================
