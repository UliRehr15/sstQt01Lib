// ds2_testrec_qt_model.h   03.03.15  Re.   03.03.15  Re.
//
// Datastructures and Prototypes for system "testrec model"
//


#ifndef SST_TESTREC_QT_MODEL_H
#define SST_TESTREC_QT_MODEL_H

#include <QAbstractTableModel>
#include <QTableView>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>

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

#endif // MYMODEL_H
