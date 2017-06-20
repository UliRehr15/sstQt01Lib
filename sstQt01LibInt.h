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
// sstQt01LibInt.h   12.08.16  Re.   12.08.16  Re.
//
// Intern Datastructures and Prototypes for system "sstQt01Lib"
//

#ifndef   _SST_QT01_LIB_INT_HEADER
#define   _SST_QT01_LIB_INT_HEADER

/**
 * @defgroup sstQt01LibInt Intern sst Qt01 library
 */

#include <QTableView>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

// Defines ---------------------------------------------------------------------

// forward declaration ---------------------------------------------------------

// Structures and Classes ------------------------------------------------------
//==============================================================================
/**
* @brief sst Path Table Model Class
*
* Inherit from QAbstractTableModel
*
* Changed: 19.02.10  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 19.02.10
*/
// ----------------------------------------------------------------------------
class sstQt01PathTabMdlCls : public QAbstractTableModel
{
    Q_OBJECT
public:
  //==============================================================================
  /**
  * @brief // Constructor <BR>
  *
  * @param parent [in] For the moment 0
  * @param poPrt         [in out] Pointer to Protocol object
  * @param poPathStorage [in out] Pointer to Path Storage object
  *
  */
  // ----------------------------------------------------------------------------
  sstQt01PathTabMdlCls(QObject *parent,
                       sstMisc01PrtFilCls    *poPrt,
                       sstQt01PathStorageCls *poPathStorage);
  //==============================================================================
  /**
  * @brief // Destructor <BR>
  */
  // ----------------------------------------------------------------------------
  ~sstQt01PathTabMdlCls();
  //==============================================================================
  /**
  * @brief // rowCount <BR>
  * iStat = oPathTabMdl.rowCount ( parent);
  *
  * @param parent [in] For the moment 0
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    //==============================================================================
    /**
    * @brief // columnCount <BR>
    * iStat = oPathTabMdl.columnCount( parent);
    *
    * @param parent [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    //==============================================================================
    /**
    * @brief // data <BR>
    * iStat = oPathTabMdl.data(index, role);
    *
    * @param index [in] For the moment 0
    * @param role  [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    //==============================================================================
    /**
    * @brief // headerData <BR>
    * iStat = oPathTabMdl.headerData ( section, orientation, role);
    *
    * @param section     [in] For the moment 0
    * @param orientation [in] For the moment 0
    * @param role        [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    //==============================================================================
    /**
    * @brief // setData <BR>
    * iStat = oPathTabMdl.setData( index, value, role);
    *
    * @param index [in] For the moment 0
    * @param value [in] For the moment 0
    * @param role  [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    //==============================================================================
    /**
    * @brief // flags <BR>
    * iStat = oPathTabMdl.flags (index);
    *
    * @param index [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    Qt::ItemFlags flags(const QModelIndex & index) const ;
    //==============================================================================
    /**
    * @brief // removeRows  <BR>
    * iStat = oPathTabMdl.removeRows ( position, rows, index);
    *
    * @param position [in] For the moment 0
    * @param rows     [in] For the moment 0
    * @param index    [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    bool removeRows(int position, int rows, const QModelIndex &index);
    //==============================================================================
    /**
    * @brief // insertRows <BR>
    * iStat = oPathTabMdl.insertRows ( position, rows, index);
    *
    * @param position [in] For the moment 0
    * @param rows     [in] For the moment 0
    * @param index    [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    bool insertRows(int position, int rows, const QModelIndex &index);
public slots:
    //==============================================================================
    /**
    * @brief Slot Table data changed
    */
    // ----------------------------------------------------------------------------
    void ChangeTab();
signals:
    //==============================================================================
    /**
    * @brief Signal Table data changed
    */
    // ----------------------------------------------------------------------------
    void TabChanged();

    //==============================================================================
private:
    sstQt01PathStorageCls *poPathStorage;          /**< Is a table and function object for test rec1 */
    std::vector<unsigned long int> sstTabVector;   /**< Vector maps table record positions when deleting */
    sstMisc01PrtFilCls   *poPrt;                   /**< Dummy */
};


#endif

// --------------------------------------------------------------- File End ----
