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
// sstQt01_tstrec2_TabMdl.cpp   16.09.15  Re.    16.09.15  Re.
//
// qt model and View for dss Table testrec2


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

#include "sst_qt_lib_test_tab.h"

//=============================================================================
TstRec2ModelCls::TstRec2ModelCls(QObject *parent)
    :QAbstractTableModel(parent)
{
  int iStat = 0;
  dREC04RECNUMTYP dLocRecNo = 0;
  sstRec04TestRec2Cls oLocTestRec;

  iStat = oTestRec2Table.OpenReadCsvFile(0,(char*) "test_rec2.csv");

  if (iStat == -2)
  {  // File not found
    iStat = oLocTestRec.SetAll(1,1,2,2,1.1,2.2,true,(char*)"Test2");

    iStat = oTestRec2Table.WriteNew(0,&dLocRecNo,&oLocTestRec);
    // iStat = oTestRec2Table.CloseCsvFile(0,(char*)"test_rec2.csv");

    // iStat = oTestRec2Table.OpenReadCsvFile(0,(char*) "test_rec2.csv");
    assert(iStat == 0);

  }


  dREC04RECNUMTYP dRecNum = oTestRec2Table.RecordCount();

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
TstRec2ModelCls::~TstRec2ModelCls()
{
  oTestRec2Table.CloseCsvFile(0,(char*) "test_rec2.csv");
}
//=============================================================================
int TstRec2ModelCls::rowCount(const QModelIndex & /*parent*/) const
{
  return oTestRec2Table.RecordCount();
}
//=============================================================================
int TstRec2ModelCls::columnCount(const QModelIndex & /*parent*/) const
{
    return 8;
}
//=============================================================================
QVariant TstRec2ModelCls::data(const QModelIndex &index, int role) const
{
  // int row = index.row();
  int col = index.column();

  switch(role){
  case Qt::DisplayRole:
    {
      sstRec04TestRec2Cls oTestRec2;
      qlonglong lVal = 0;
      qulonglong ulVal = 0;

      oTestRec2Table.ReadRecPos ( 0, this->sstTabVector[index.row()], &oTestRec2);

      switch (index.column())
      {
      case 0: return oTestRec2.iVal; break;
      case 1:
        return oTestRec2.uiVal;
        break;
      case 2:  lVal = (qlonglong) oTestRec2.lVal;   return lVal;      break;
      case 3:  ulVal = (qulonglong) oTestRec2.ulVal;   return ulVal;      break;
//       case 4:  return oTestRec2.fVal; break;
      case 4:  return QString::number(oTestRec2.fVal, 'f', 2); break;
      case 5:  return QString::number(oTestRec2.dVal, 'f', 4); break;
      case 6:  return oTestRec2.bVal; break;
      case 7:  return QString::fromUtf8( oTestRec2.cVal); break;
      // case 8:  ulVal = (qulonglong) dRecNo;   return ulVal;      break;
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
QVariant TstRec2ModelCls::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Integer");
            case 1:
                return QString("Unsigned Int");
            case 2:
                return QString("Long");
            case 3:
                return QString("Unsigned Long");
            case 4:
                return QString("Real/Float");
            case 5:
                return QString("Double");
            case 6:
                return QString("Bool");
            case 7:
                return QString("Character");
            }
        }
    }
    return QVariant();
}
//=============================================================================
bool TstRec2ModelCls::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (role == Qt::EditRole)
    {
        //save value from editor to oTestRecDss
      sstRec04TestRec2Cls oTestRec2;

      dREC04RECNUMTYP dRecNo = index.row() +1;
      oTestRec2Table.ReadRecPos ( 0, this->sstTabVector[index.row()], &oTestRec2);

      bool bOK = 1;

      switch (index.column())
      {
      case 0: oTestRec2.iVal = value.toInt(&bOK);  break;
      case 1:
        oTestRec2.uiVal = value.toUInt(&bOK) ;
        break;
      case 2: oTestRec2.lVal = value.toLongLong(&bOK) ; break;
      case 3: oTestRec2.ulVal = value.toULongLong(&bOK) ; break;
      case 4: oTestRec2.fVal = value.toFloat(&bOK) ; break;
      case 5: oTestRec2.dVal = value.toDouble(&bOK); break;
      case 6: oTestRec2.bVal = value.toBool(); break;
      case 7:
        {
          QString locStr = value.toString();
          strncpy(oTestRec2.cVal, locStr.toUtf8(),10);
          break;
        }
      }

      if (bOK) oTestRec2Table.WriteRecPos( 0, dRecNo, &oTestRec2);

    }
    return true;
}
//=============================================================================
Qt::ItemFlags TstRec2ModelCls::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}
//=============================================================================
bool TstRec2ModelCls::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    // rows is always = 1 at the moment
    // Position is 0 > n-1

    for (int row = 0; row < rows; ++row) {
      oTestRec2Table.DeleteRecPos(0,position+1);
    }
    endRemoveRows();

    this->sstTabVector.erase (this->sstTabVector.begin()+position);

    return true;
}
//=============================================================================
bool TstRec2ModelCls::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    // rows is always = 1 at the moment
    // Position is 0 > n-1
    dREC04RECNUMTYP dRecNo = 0;

    for (int row = 0; row < rows; ++row) {
      sstRec04TestRec2Cls oTestRec;
      oTestRec2Table.WriteNew(0,&dRecNo,&oTestRec);
    }

    endInsertRows();

    this->sstTabVector.push_back(dRecNo);

    return true;
}
//=============================================================================
