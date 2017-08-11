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
// sst_qt_lib_test_tab.h   22.04.17  Re.   03.03.15  Re.
//
// Datastructures and Prototypes for system "testframe for sst qt table apps"
//


#ifndef SST_QT_LIB_TEST_TAB_H
#define SST_QT_LIB_TEST_TAB_H

#include <QAbstractTableModel>
#include <QTableView>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include <vector>

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QLineEdit;
class QToolBar;
class QTableWidgetItem;
class QTableWidget;
QT_END_NAMESPACE

//==============================================================================
/**
* @brief Definition Class TstRec2ModelCls
*
* More Comment
*
* Changed: 19.02.10  Re.
*
* @ingroup examples
*
* @author Re.
*
* @date 19.02.10
*/
// ----------------------------------------------------------------------------
class TstRec1ModelCls : public QAbstractTableModel
{
    Q_OBJECT
public:
  TstRec1ModelCls(QObject *parent);
  ~TstRec1ModelCls();
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const ;
    bool removeRows(int position, int rows, const QModelIndex &index);
    bool insertRows(int position, int rows, const QModelIndex &index);


private:
    sstRec04TestRec1FncCls oTestRec1Table;  // is a table and function object for test rec1
    std::vector<unsigned long int> sstTabVector;    /**< Vector maps table record positions when deleting */
};
//==============================================================================
/**
* @brief Definition Class TstRec2ModelCls
*
* More Comment
*
* Changed: 19.02.10  Re.
*
* @ingroup examples
*
* @author Re.
*
* @date 19.02.10
*/
// ----------------------------------------------------------------------------
class TstRec2ModelCls : public QAbstractTableModel
{
    Q_OBJECT
public:
  TstRec2ModelCls(QObject *parent);
  ~TstRec2ModelCls();
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const ;
    bool removeRows(int position, int rows, const QModelIndex &index);
    bool insertRows(int position, int rows, const QModelIndex &index);


private:
    sstRec04TestRec2FncCls oTestRec2Table;
    std::vector<unsigned long int> sstTabVector;    /**< Vector maps table record positions when deleting */
};
//==============================================================================
/**
* @brief View Class for sstRec04 TstRec1 records
*
* Changed: 22.04.17  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 22.04.17
*/
// ----------------------------------------------------------------------------
class sstQt01TstRec1ViewCls : public sstQt01TabViewCls
{
  public:   // Public functions
     sstQt01TstRec1ViewCls(sstMisc01PrtFilCls    *poTmpPrt);  // Constructor
     ~sstQt01TstRec1ViewCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * iStat = oTestBase.Func_1(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
    // int Func_1(int iKey);
// ----------------------------------------------------------------------------
private:  // Private functions
     TstRec1ModelCls  *pTstRec1Model; /**< Dummy */
};
//==============================================================================
/**
* @brief View Class for sstRec04 TstRec2 records
*
* Changed: 22.04.17  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 22.04.17
*/
// ----------------------------------------------------------------------------
class sstQt01TstRec2ViewCls : public sstQt01TabViewCls
{
  public:   // Public functions
     sstQt01TstRec2ViewCls(sstMisc01PrtFilCls    *poTmpPrt);  // Constructor
     ~sstQt01TstRec2ViewCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * iStat = oTestBase.Func_1(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
    // int Func_1(int iKey);
// ----------------------------------------------------------------------------
private:  // Private functions
  TstRec2ModelCls  *pTstRec2Model; /**< Dummy */
};
//==============================================================================


#endif
