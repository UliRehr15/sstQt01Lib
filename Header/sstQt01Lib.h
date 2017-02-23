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
// sstQt01Lib.h   12.08.16  Re.   12.08.16  Re.
//
// Datastructures and Prototypes for system "sstQt01Lib"
//

#ifndef   _SST_QT01_LIB_HEADER
#define   _SST_QT01_LIB_HEADER

/**
 * @defgroup sstQt01Lib sst Qt01 library
 */

#include <QDialog>
#include <QtWidgets>
#include <QAbstractTableModel>
#include <QTableView>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>

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


// Defines ---------------------------------------------------------------------

// forward declaration ---------------------------------------------------------

class sstQt01PathTabMdlCls;

// Structures and Classes ------------------------------------------------------
//==============================================================================
/**
* @brief sst extended QPainterPath shape class
*
* one Path object Extended with color and string tooltip <BR>
*
* Changed: 26.01.17  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 26.01.17
*/
// ----------------------------------------------------------------------------
class sstQt01ShapeItem
{
public:
  //==============================================================================
  /**
  * @brief // set path object <BR>
  * iStat = oPathItem.setPath(Path);
  *
  * @param Path [in] QPainterPath object
  */
  // ----------------------------------------------------------------------------
    void setPath(const QPainterPath &Path);
    //==============================================================================
    /**
    * @brief // set tooltip <BR>
    * iStat = oPathItem.setToolTip(ToolTip);
    *
    * @param ToolTip [in] ToolTip string
    */
    // ----------------------------------------------------------------------------
    void setToolTip(const QString &ToolTip);
    //==============================================================================
    /**
    * @brief // set Position <BR>
    * iStat = oPathItem.setPosition(Position);
    *
    * @param Position [in] QPainterPath object
    */
    // ----------------------------------------------------------------------------
    void setPosition(const QPoint &Position);
    //==============================================================================
    /**
    * @brief // set color <BR>
    * iStat = oPathItem.setColor(Path);
    *
    * @param Color [in] QColor
    */
    // ----------------------------------------------------------------------------
    void setColor(const QColor &Color);
    //==============================================================================
    /**
    * @brief // Get QPainterPath <BR>
    * oPath = PathItem.getPath();
    *
    * @return QPainterPath
    */
    // ----------------------------------------------------------------------------
    QPainterPath getPath() const;
    //==============================================================================
    /**
    * @brief // Get Position <BR>
    * oPosition = PathItem.getPosition();
    *
    * @return QPoint
    */
    // ----------------------------------------------------------------------------
    QPoint getPosition() const;
    //==============================================================================
    /**
    * @brief // Get Color <BR>
    * oColor = PathItem.getColor();
    *
    * @return QColor
    */
    // ----------------------------------------------------------------------------
    QColor getColor() const;
    //==============================================================================
    /**
    * @brief // Get ToolTip string <BR>
    * oToolTip = PathItem.getToolTip();
    *
    * @return QString
    */
    // ----------------------------------------------------------------------------
    QString getToolTip() const;
    //==============================================================================

private:
    QPainterPath myPath;
    QPoint myPosition;
    QColor myColor;
    QString myToolTip;
};
/**
* @brief storage class for painter path objects <BR>
*
* FIFO storage, reading/writing to csv file <BR>
*
* Changed: 05.09.16  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 05.09.16
*/
// ----------------------------------------------------------------------------
class sstQt01PathStorageCls
{
  public:   // Public functions
     sstQt01PathStorageCls();  // Constructor
    ~sstQt01PathStorageCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Load all pathes record rows from csv file in sst table object.  <BR>
     * iStat = oPathStorage.LoadAllPathFromFile (iKey, oFilNam);
     *
     * @param iKey    [in] For the moment 0
     * @param oFilNam [in] File name
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int LoadAllPathFromFile (int iKey, std::string oFilNam);
     //==============================================================================
     /**
     * @brief // store all pathes from sst table object into csv file.  <BR>
     * iStat = oPathStorage.LoadAllPathFromFile (iKey, oFilNam);
     *
     * @param iKey    [in] For the moment 0
     * @param oFilNam [in] File name
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int StoreAllPathToFile (int iKey, std::string oFilNam);
     //==============================================================================
     /**
     * @brief // append one QPainterPath at end of sst table object  <BR>
     * iStat = oPathStorage.LoadAllPathFromFile (iKey, oFilNam);
     *
     * @param iKey   [in] For the moment 0
     * @param oPath  [in] QPainterPath object to store
     * @param oColor [in] Color of Path
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int AppendPath(int iKey,  QPainterPath oPath, QColor oColor);
     //==============================================================================
     /**
     * @brief // read next QPainterPath object from sst table object.  <BR>
     * iStat = oPathStorage.LoadAllPathFromFile (iKey, oFilNam);
     *
     * @param iKey   [in] For the moment 0
     * @param oPath  [out] QPainterPath object
     * @param oColor [out] Color of Path
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadNextPath(int iKey,  QPainterPath *oPath, QColor *oColor);
     //==============================================================================
     /**
     * @brief // read next QPainterPath object from sst table object.  <BR>
     * iStat = oPathStorage.LoadAllPathFromFile (iKey, oFilNam);
     *
     * @param iKey               [in] For the moment 0
     * @param dStartElementRecNo [in] For the moment 0
     * @param oPath              [out] QPainterPath object
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadPath(int iKey, dREC04RECNUMTYP dStartElementRecNo, QPainterPath *oPath);
     //==============================================================================
     /**
     * @brief // return number of stored records  <BR>
     * iStat = oPathStorage.LoadAllPathFromFile (iKey, oFilNam);
     *
     * @return Number of stored records
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP RecordCount() const;
     //==============================================================================
     /**
     * @brief // read QPainterPath record from sst table object.  <BR>
     * iStat = oPathStorage.ReadRecPos (iKey, dRecNo, vRecAdr);
     *
     * @param iKey    [in]  For the moment 0
     * @param dRecNo  [in]  Record number
     * @param vRecAdr [out] return Path record at adress
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadRecPos (int iKey, dREC04RECNUMTYP dRecNo, void* vRecAdr) const;
     //==============================================================================
     /**
     * @brief // write QPainterPath record to sst table object.  <BR>
     * iStat = oPathStorage.WriteRecPos (iKey, dRecNo, vRecAdr);
     *
     * @param iKey    [in] For the moment 0
     * @param dRecNo  [out] record number
     * @param vRecAdr [out] write path record from adress
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WriteRecPos (int iKey, dREC04RECNUMTYP dRecNo, void* vRecAdr);
     //==============================================================================
     /**
     * @brief // mark deleted QPainterPath record in sst table object.  <BR>
     * iStat = oPathStorage.LoadAllPathFromFile (iKey, oFilNam);
     *
     * @param iKey   [in] For the moment 0
     * @param dRecNo [in] record number
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int DeleteRecPos (int iKey, dREC04RECNUMTYP dRecNo);
     //==============================================================================
     /**
     * @brief // write next QPainterPath record into sst table object.  <BR>
     * iStat = oPathStorage.WriteNew (iKey, &dRecNo, vRecAdr);
     *
     * @param iKey    [in] For the moment 0
     * @param dRecNo  [out] new record number
     * @param vRecAdr [in] path record at adress for writing
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WriteNew (int iKey, dREC04RECNUMTYP *dRecNo, void* vRecAdr);
     //==============================================================================
     /**
     * @brief // Get Tooltip string for index path <BR>
     * iStat = oPathStorage.getToolTip(index);
     *
     * @param index [in] index of path
     *
     * @return tooltip string
     */
     // ----------------------------------------------------------------------------
     QString getToolTip(dREC04RECNUMTYP index);
     //==============================================================================
     /**
     * @brief // set tooltip string in main table <BR>
     * iStat = oPathStorage.setTooltip(index,oTooltip);
     *
     * @param index    [in] record number in main table
     * @param oTooltip [in] Tooltip string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int setToolTip(dREC04RECNUMTYP index, QString oTooltip);
     //==============================================================================
     /**
     * @brief // set position to shape item in main table <BR>
     * iStat = oPathStorage.setPosition(index,oPosition);
     *
     * @param index     [in] record number in main table
     * @param oPosition [in] Position point
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int setPosition(dREC04RECNUMTYP index, QPoint oPosition);
     //==============================================================================
     /**
     * @brief // Get color of shape item <BR>
     * oPosition = oPathStorage.getPosition(index);
     *
     * @param index [in] index of path
     *
     * @return QPoint
     */
     // ----------------------------------------------------------------------------
     QPoint getPosition(dREC04RECNUMTYP index);
     //==============================================================================
     /**
     * @brief // add position to shape item in main table <BR>
     * iStat = oPathStorage.addPosition(index,oPosition);
     *
     * @param index     [in] record number in main table
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int addPosition(dREC04RECNUMTYP index);
     //==============================================================================
     /**
     * @brief // Get Color for index path <BR>
     * iStat = oPathStorage.getColor(index);
     *
     * @param index [in] index of path
     *
     * @return Color
     */
     // ----------------------------------------------------------------------------
     QColor getColor(dREC04RECNUMTYP index);
     //==============================================================================
     /**
     * @brief // Get Path from path table <BR>
     * iStat = oPathStorage.getPath(index);
     *
     * @param index [in] index of path
     *
     * @return Path geometry
     */
     // ----------------------------------------------------------------------------
     QPainterPath getPath(dREC04RECNUMTYP index);
     //==============================================================================
     /**
     * @brief // Get Shape Item from path table <BR>
     * iStat = oPathStorage.getShapeItem(index);
     *
     * @param index [in] index of path
     *
     * @return Path geometry
     */
     // ----------------------------------------------------------------------------
     sstQt01ShapeItem getShapeItem(dREC04RECNUMTYP index);
     //==============================================================================
     /**
     * @brief // append item to storage at table end <BR>
     * iStat = oPathStorage.appendShapeItem();
     *
     * @param oItem [in] sst Shape item to append to table storage
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int appendShapeItem(sstQt01ShapeItem oItem);
     //==============================================================================
     /**
     * @brief // return number of sst shape items in storage <BR>
     * iStat = oPathStorage.countItems();
     *
     * @return int number of actual stored shape items
     */
     // ----------------------------------------------------------------------------
     int countItems();
// ----------------------------------------------------------------------------
  private:  // Private functions
     sstRec04Cls *poShapeItemRecTable;   /**< painter path element record table */
     sstRec04Cls *poShapeItemMainTable;  /**< painter path main table */
     dREC04RECNUMTYP dActualReadPos;     /**< actual read position in table */
};
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
  */
  // ----------------------------------------------------------------------------
  sstQt01PathTabMdlCls(QObject *parent);
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
    //==============================================================================
private:
    sstQt01PathStorageCls oTestRec1Table;  // is a table and function object for test rec1
    std::vector<unsigned long int> sstTabVector;    /**< Vector maps table record positions when deleting */
};
//==============================================================================
/**
* @brief sst Table View
*
* Inherit from QTable View
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
class sstQt01TabViewCls : public QTableView
{
      Q_OBJECT
  public:   // Public functions
     sstQt01TabViewCls();   // Constructor
// ----------------------------------------------------------------------------
public slots:
     //==============================================================================
     /**
     * @brief actionRowsInsert
     */
     // ----------------------------------------------------------------------------
  void actionRowsInsert();
  //==============================================================================
  /**
  * @brief actionRowsDelete
  */
  // ----------------------------------------------------------------------------
  void actionRowsDelete();

protected:
  //==============================================================================
  /**
  * @brief setup ContextMenu with actions
  */
  // ----------------------------------------------------------------------------
    void setupContextMenu();
    //==============================================================================
    /**
    * @brief Create actions and connect to slots
    */
    // ----------------------------------------------------------------------------
    void createActions();

private:  // Private functions
  QAction *cell_InsAction;   /**< Insert Table Rows Action */
  QAction *cell_DelAction;   /**< Delete Table Rows Action */
};

//==============================================================================
/**
* @brief sstQt01PathPaintWidgetCls
*
* Changed: 23.02.17  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 23.02.17
*/
// ----------------------------------------------------------------------------
class sstQt01PathPaintWidgetCls : public QWidget
{
    Q_OBJECT

public:
  sstQt01PathPaintWidgetCls();
  ~sstQt01PathPaintWidgetCls();

protected:
  //==============================================================================
  /**
  * @brief // event <BR>
  *
  * @param event [in]
  */
  // ----------------------------------------------------------------------------
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    //==============================================================================
    /**
    * @brief // event <BR>
    *
    * @param event [in]
    */
    // ----------------------------------------------------------------------------
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
    //==============================================================================
    /**
    * @brief // event <BR>
    *
    * @param event [in]
    */
    // ----------------------------------------------------------------------------
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    //==============================================================================
    /**
    * @brief // event <BR>
    *
    * @param event [in]
    */
    // ----------------------------------------------------------------------------
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    //==============================================================================
    /**
    * @brief // event <BR>
    *
    * @param event [in]
    */
    // ----------------------------------------------------------------------------
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    //==============================================================================
    /**
    * @brief // event <BR>
    *
    * @param event [in]
    */
    // ----------------------------------------------------------------------------
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void createNewCircle();
    void createNewSquare();
    void createNewTriangle();

private:
    int updateButtonGeometry(QToolButton *button, int x, int y);
    void createShapeItem(const QPainterPath &path, const QString &toolTip,
                         const QPoint &pos, const QColor &color);
    int itemAt(const QPoint &pos);
    void moveItemTo(const QPoint &pos);
    int ItemsLoadFromFile3 (int iKey);
    int ItemsCreate (int iKey);

    QPoint initialItemPosition(const QPainterPath &path);
    QPoint randomItemPosition();
    QColor initialItemColor();
    QColor randomItemColor();
    QToolButton *createToolButton(const QString &toolTip, const QIcon &icon,
                                  const char *member);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;


    // QList<sstQt01ShapeItem> shapeItems;
    QPainterPath circlePath;
    QPainterPath squarePath;
    QPainterPath trianglePath;

    QPoint previousPosition;
    // sstQt01ShapeItem *itemInMotion;
    int iItemInMotionIndex;
    sstQt01ShapeItem oActualItem;
    int iActualItemIndex;

    QToolButton *newCircleButton;
    QToolButton *newSquareButton;
    QToolButton *newTriangleButton;
    sstQt01PathStorageCls *oPathStorage;
};

//==============================================================================
/**
* @brief Test PainterPath Drawing widget
*
* template for sst base class <BR>
*
* Changed: 23.02.17  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 23.02.17
*/
// ----------------------------------------------------------------------------
class sstQt01TestPaintWidgetCls : public QWidget
{
    Q_OBJECT

public:
  //==============================================================================
  /**
  * @brief // Shape <BR>
  *
  * @param Shape
  */
  // ----------------------------------------------------------------------------
    enum Shape { Line, Points, Polyline, Polygon, Rect, RoundedRect, Ellipse, Arc,
                 Chord, Pie, Path, Text, Pixmap };

    //==============================================================================
    /**
    * @brief // Constructor <BR>
    *
    * @param parent [in] For the moment 0
    */
    // ----------------------------------------------------------------------------
    sstQt01TestPaintWidgetCls(QWidget *parent = 0);

    //==============================================================================
    /**
    * @brief // minimumSizeHint <BR>
    *
    * @return QSize
    */
    // ----------------------------------------------------------------------------
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    //==============================================================================
    /**
    * @brief // sizeHint <BR>
    *
    * @return QSize
    */
    // ----------------------------------------------------------------------------
    QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    *
    * @param shape [in] For the moment 0
    */
    // ----------------------------------------------------------------------------
    void setShape(Shape shape);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    *
    * @param pen [in] For the moment 0
    */
    // ----------------------------------------------------------------------------
    void setPen(const QPen &pen);
    //==============================================================================
    /**
    * @brief // setBrush <BR>
    *
    * @param brush [in] For the moment 0
    */
    // ----------------------------------------------------------------------------
    void setBrush(const QBrush &brush);
    //==============================================================================
    /**
    * @brief // setAntialiased <BR>
    *
    * @param antialiased [in] For the moment 0
    */
    // ----------------------------------------------------------------------------
    void setAntialiased(bool antialiased);
    //==============================================================================
    /**
    * @brief // setTransformed <BR>
    *
    * @param transformed [in] For the moment 0
    */
    // ----------------------------------------------------------------------------
    void setTransformed(bool transformed);
    //==============================================================================

protected:
    //==============================================================================
    /**
    * @brief // paintEvent <BR>
    *
    * @param event [in] For the moment 0
    */
    // ----------------------------------------------------------------------------
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    //==============================================================================

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
    QPixmap pixmap;
};

#endif

// --------------------------------------------------------------- File End ----

