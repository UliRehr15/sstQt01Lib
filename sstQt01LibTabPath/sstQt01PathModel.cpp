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
// sstQt01PathModell.cpp   16.09.15  Re.    16.09.15  Re.
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

#include "sstQt01LibTabPath.h"

//=============================================================================
sstQt01PathMdlCls::sstQt01PathMdlCls(QObject *parent)
    :QAbstractTableModel(parent)
{
  int iStat = 0;
  // dREC04RECNUMTYP dLocRecNo = 0;
  // sstQt01PathElementCsvCls oLocTestRec;
  sstQt01PathElementCsvCls oLocTestRec;
  iStat = oTestRec1Table.LoadAllPathFromFile( 0, (char*) "Paint.csv");

  if (iStat == -2)
  {  // File not found

    // Generate test data
    // iStat = oLocTestRec.SetAll(33,(char*) "Test");
    // iStat = oTestRec1Table.WriteNew(0,&dLocRecNo,&oLocTestRec);
    // assert(iStat == 0);
    assert(0);
  }

  dREC04RECNUMTYP dRecNum = oTestRec1Table.RecordCount();

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
sstQt01PathMdlCls::~sstQt01PathMdlCls()
{
  // oTestRec1Table.CloseCsvFile(0,(char*) "test_rec1.csv");
  oTestRec1Table.StoreAllPathToFile( 0, (char*) "Paint.csv");
}
//=============================================================================
int sstQt01PathMdlCls::rowCount(const QModelIndex & /*parent*/) const
{
  // dREC04RECNUMTYP dLocCount = oTestRec1Table.RecordCount();
  // int iLocCount = (int) dLocCount;
  return oTestRec1Table.RecordCount();//iLocCount;
}
//=============================================================================
int sstQt01PathMdlCls::columnCount(const QModelIndex & /*parent*/) const
{
    return 6;
}
//=============================================================================
QVariant sstQt01PathMdlCls::data(const QModelIndex &index, int role) const
{
  int col = index.column();

  switch(role){
  case Qt::DisplayRole:
    {
      sstQt01PathElementCsvCls oTestRec1;

      oTestRec1Table.ReadRecPos ( 0, this->sstTabVector[index.row()], &oTestRec1);

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
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
QVariant sstQt01PathMdlCls::headerData(int section, Qt::Orientation orientation, int role) const
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
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
bool sstQt01PathMdlCls::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (role == Qt::EditRole)
    {
        //save value from editor to oTestRecDss
      sstQt01PathElementCsvCls oTestRec1;

      dREC04RECNUMTYP dRecNo = index.row() +1;
      oTestRec1Table.ReadRecPos ( 0, this->sstTabVector[index.row()], &oTestRec1);

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

      if (bOK) oTestRec1Table.WriteRecPos( 0, dRecNo, &oTestRec1);

    }
    return true;
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
Qt::ItemFlags sstQt01PathMdlCls::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}
//=============================================================================
bool sstQt01PathMdlCls::removeRows(int position, int rows, const QModelIndex &index)
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
bool sstQt01PathMdlCls::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    // rows is always = 1 at the moment
    // Position is 0 > n-1
    dREC04RECNUMTYP dRecNo = 0;

    for (int row = 0; row < rows; ++row) {
      sstQt01PathElementCsvCls oTestRec;
      oTestRec1Table.WriteNew(0,&dRecNo,&oTestRec);
    }

    endInsertRows();

    this->sstTabVector.push_back(dRecNo);

    return true;
}
//=============================================================================
//sstQt01TabViewCls::sstQt01TabViewCls()
//{
//    createActions();
//    setupContextMenu();
//}
////=============================================================================
//void sstQt01TabViewCls::setupContextMenu()
//{
//    addAction(cell_InsAction);
//    addAction(cell_DelAction);
//    setContextMenuPolicy(Qt::ActionsContextMenu);
//}
////=============================================================================
//void sstQt01TabViewCls::createActions()
//{
//  QString tt = QString::fromLatin1("&Zeilen lцschen");

//  cell_DelAction = new QAction(tt, this);
//  cell_DelAction->setShortcut(Qt::CTRL | Qt::Key_Minus);
//  connect(cell_DelAction, SIGNAL(triggered()), this, SLOT(actionRowsDelete()));

//  tt = QString::fromLatin1("&Zeile einfьgen am Ende");
//  cell_InsAction = new QAction( tt, this);
//  cell_InsAction->setShortcut(Qt::CTRL | Qt::Key_Plus);
//  connect(cell_InsAction, SIGNAL(triggered()), this, SLOT(actionRowsInsert()));

//}
////=============================================================================
//void sstQt01TabViewCls::actionRowsDelete()
//{
//  const QModelIndex index = this->selectionModel()->currentIndex();
//  int row = index.row();  // Get Positon of selected Row
//  int count = 1;  // Delete always one row
//  this->model()->removeRows(row,count,index);
//}
////=============================================================================
//void sstQt01TabViewCls::actionRowsInsert()
//{
//  const QModelIndex index = this->selectionModel()->currentIndex();
//  int row = this->model()->rowCount();  // Get Number of all defined rows
//  int count = 1;  // Append always one new row
//  this->model()->insertRows(row,count,index);
//}
////=============================================================================

