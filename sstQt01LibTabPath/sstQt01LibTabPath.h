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
// sstQt01LibTabPath.h   17.01.17  Re.   17.01.17  Re.
//
// Datastructures and Prototypes for system "sstQt01LibTabPath"
//


#ifndef SST_QT01LIB_TAB_PATH_H
#define SST_QT01LIB_TAB_PATH_H

#include <QDialog>
#include <QtWidgets>
#include <QAbstractTableModel>
#include <QTableView>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include <vector>

QT_BEGIN_NAMESPACE
class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;
class QToolBar;
class QTableWidgetItem;
class QTableWidget;
QT_END_NAMESPACE

class sstQt01PathMdlCls;

class sstQt01PathTabDialogCls : public QDialog
{
    Q_OBJECT

public:
    sstQt01PathTabDialogCls();
    ~sstQt01PathTabDialogCls();

private:
    void createMenu();
    void createHorizontalGroupBox1();
    void createHorizontalGroupBox2();

    enum { NumGridRows = 3, NumButtons = 4 };

    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox1;
    QGroupBox *horizontalGroupBox2;

    QMenu *fileMenu;
    QAction *exitAction;

    sstQt01PathMdlCls  *pTstRec1Model;
    sstQt01TabViewCls   *pTstRec1View;

    // TstRec2ModelCls  *pTstRec2Model;
    // TstRec2ViewCls   *pTstRec2View;

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
class sstQt01PathMdlCls : public QAbstractTableModel
{
    Q_OBJECT
public:
  sstQt01PathMdlCls(QObject *parent);
  ~sstQt01PathMdlCls();
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const ;
    bool removeRows(int position, int rows, const QModelIndex &index);
    bool insertRows(int position, int rows, const QModelIndex &index);


private:
    // sstRec04TestRec1FncCls oTestRec1Table;  // is a table and function object for test rec1
    sstQt01PathStorageCls oTestRec1Table;  // is a table and function object for test rec1
    std::vector<unsigned long int> sstTabVector;    /**< Vector maps table record positions when deleting */
};

//==============================================================================
/**
* @brief Definition Class TstRec2ViewCls
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
//class sstQt01TabViewCls : public QTableView
//{
//      Q_OBJECT
//  public:   // Public functions
//     sstQt01TabViewCls();   // Constructor
//// ----------------------------------------------------------------------------
//public slots:
//     //==============================================================================
//     /**
//     * @brief Shortstory
//     *
//     * @param iKey [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//  void actionRowsInsert();
//  //==============================================================================
//  /**
//  * @brief Shortstory
//  *
//  * @param iKey [in] For the moment 0
//  *
//  * @return Errorstate
//  *
//  * @retval   = 0: OK
//  * @retval   < 0: Unspecified Error
//  */
//  // ----------------------------------------------------------------------------
//  void actionRowsDelete();

//protected:
//  //==============================================================================
//  /**
//  * @brief setup ContextMenu with actions
//  */
//  // ----------------------------------------------------------------------------
//    void setupContextMenu();
//    //==============================================================================
//    /**
//    * @brief Create actions and connect to slots
//    */
//    // ----------------------------------------------------------------------------
//    void createActions();

//private:  // Private functions
//  QAction *cell_InsAction;   /**< Insert Table Rows Action */
//  QAction *cell_DelAction;   /**< Delete Table Rows Action */
////-----------------------------------------------------------------------------
//};
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
//class TstRec2ModelCls : public QAbstractTableModel
//{
//    Q_OBJECT
//public:
//  TstRec2ModelCls(QObject *parent);
//  ~TstRec2ModelCls();
//    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
//    int columnCount(const QModelIndex &parent = QModelIndex()) const;
//    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
//    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
//    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
//    Qt::ItemFlags flags(const QModelIndex & index) const ;
//    bool removeRows(int position, int rows, const QModelIndex &index);
//    bool insertRows(int position, int rows, const QModelIndex &index);


//private:
//    sstRec04TestRec2FncCls oTestRec2Table;
//    std::vector<unsigned long int> sstTabVector;    /**< Vector maps table record positions when deleting */
//};

//==============================================================================
/**
* @brief Definition Class TstRec2ViewCls
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
//class TstRec2ViewCls : public QTableView
//{
//      Q_OBJECT
//  public:   // Public functions
//     TstRec2ViewCls();   // Constructor
//// ----------------------------------------------------------------------------
//public slots:
//     //==============================================================================
//     /**
//     * @brief Shortstory
//     *
//     * @param iKey [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//  void actionRowsInsert();
//  //==============================================================================
//  /**
//  * @brief Shortstory
//  *
//  * @param iKey [in] For the moment 0
//  *
//  * @return Errorstate
//  *
//  * @retval   = 0: OK
//  * @retval   < 0: Unspecified Error
//  */
//  // ----------------------------------------------------------------------------
//  void actionRowsDelete();

//protected:
//  //==============================================================================
//  /**
//  * @brief setup ContextMenu with actions
//  */
//  // ----------------------------------------------------------------------------
//    void setupContextMenu();
//    //==============================================================================
//    /**
//    * @brief Create actions and connect to slots
//    */
//    // ----------------------------------------------------------------------------
//    void createActions();

//private:  // Private functions
//  QAction *cell_InsAction;   /**< Insert Table Rows Action */
//  QAction *cell_DelAction;   /**< Delete Table Rows Action */
////-----------------------------------------------------------------------------
//};

#endif // MYMODEL_H
