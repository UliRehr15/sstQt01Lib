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
// sstQt01PathTabModel.cpp   16.09.15  Re.    16.09.15  Re.
//
// qt model for sst Table painterpath

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

// #include "sstQt01LibTabPath.h"
#include "sstQt01LibInt.h"

//=============================================================================
sstQt01PathTabMdlCls::sstQt01PathTabMdlCls(QObject *parent,
                                           sstMisc01PrtFilCls    *poTmpPrt,
                                           sstQt01PathStorageCls *poTmpPathStorage)
    :sstQt01TabMdlCls(parent)
{
  int iStat = 0;
  this->poPrt = poTmpPrt;
  this->poPathStorage = poTmpPathStorage;

  dREC04RECNUMTYP dRecNum = poPathStorage->RecordCount();

  for (dREC04RECNUMTYP ll=1; ll<=dRecNum; ++ll)
  {
    this->sstTabVector.push_back(ll);;
  }

  connect(this,SIGNAL(TabUpdated()),this,SLOT(UpdateTab()));


  // Fatal Errors goes to an assert
  if (iStat < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }
}
//=============================================================================
sstQt01PathTabMdlCls::~sstQt01PathTabMdlCls()
{
}
//=============================================================================
int sstQt01PathTabMdlCls::rowCount(const QModelIndex & /*parent*/) const
{
  return poPathStorage->RecordCount();
}
//=============================================================================
int sstQt01PathTabMdlCls::columnCount(const QModelIndex & /*parent*/) const
{
    return this->poPathStorage->ColumnCount();
}
//=============================================================================
QVariant sstQt01PathTabMdlCls::data(const QModelIndex &index, int role) const
{
  int col = index.column();

  switch(role){
  case Qt::DisplayRole:
    {
      sstQt01PathElementCsvCls oTestRec1;

      poPathStorage->ReadRecPos ( 0, this->sstTabVector[index.row()], &oTestRec1);

      switch (index.column())
      {
      case 0:  return oTestRec1.getIType();
      case 1:  return oTestRec1.getIXX();
      case 2:  return oTestRec1.getIYY();
      case 3:  return oTestRec1.getIColR();
      case 4:  return oTestRec1.getIColG();
      case 5:  return oTestRec1.getIColB();
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
QVariant sstQt01PathTabMdlCls::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0: return QString("iType");
            case 1: return QString("iXX");
            case 2: return QString("iYY");
            case 3: return QString("iColR");
            case 4: return QString("iColG");
            case 5: return QString("iColB");
            }
        }
    }
    return QVariant();
}
//=============================================================================
bool sstQt01PathTabMdlCls::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (role == Qt::EditRole)
    {
        //save value from editor to oTestRecDss
      sstQt01PathElementCsvCls oTestRec1;

      dREC04RECNUMTYP dRecNo = index.row() +1;
      poPathStorage->ReadRecPos ( 0, this->sstTabVector[index.row()], &oTestRec1);

      bool bOK = 1;

      switch (index.column())
      {
      case 0: oTestRec1.setIType(value.toInt(&bOK)); break;
      case 1: oTestRec1.setIXX(value.toInt(&bOK)); break;
      case 2: oTestRec1.setIYY( value.toInt(&bOK)); break;
      case 3: oTestRec1.setIColR( value.toInt(&bOK)); break;
      case 4: oTestRec1.setIColG( value.toInt(&bOK)); break;
      case 5: oTestRec1.setIColB( value.toInt(&bOK)); break;
      }

      if (bOK) poPathStorage->WriteRecPos( 0, dRecNo, &oTestRec1);

    }

    // For refreshing map
    emit this->TabChanged();

    return true;
}
//=============================================================================
Qt::ItemFlags sstQt01PathTabMdlCls::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}
//=============================================================================
bool sstQt01PathTabMdlCls::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    // rows is always = 1 at the moment
    // Position is 0 > n-1

    for (int row = 0; row < rows; ++row) {
      poPathStorage->DeleteRecPos(0,position+1);
    }
    endRemoveRows();

    this->sstTabVector.erase (this->sstTabVector.begin()+position);

    return true;
}
//=============================================================================
bool sstQt01PathTabMdlCls::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    // rows is always = 1 at the moment
    // Position is 0 > n-1
    dREC04RECNUMTYP dRecNo = 0;

    for (int row = 0; row < rows; ++row) {
      sstQt01PathElementCsvCls oTestRec;
      poPathStorage->WriteNew(0,&dRecNo,&oTestRec);
    }

    endInsertRows();

    this->sstTabVector.push_back(dRecNo);

    return true;
}
//=============================================================================
void sstQt01PathTabMdlCls::ChangeTab()
{
  emit this->TabChanged();
}
//=============================================================================
void sstQt01PathTabMdlCls::UpdateTab()
{
  // Get actual size of path data table
  int iRow = (int) this->poPathStorage->RecordCount();
  int iCol = (int) this->poPathStorage->ColumnCount();

  // Indexing whole model table
  QModelIndex oIndex1 = this->index(0,0);
  QModelIndex oIndex2 = this->index(iCol-1,iRow-1);

  // emit system signal -dataChanged- is nessesary, because
  // data are changed outside of Table Model in map.
  emit this->dataChanged(oIndex1,oIndex2);
}
//=============================================================================
