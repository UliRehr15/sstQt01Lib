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

#include <QtWidgets>
#include <QTreeView>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QTextBrowser>
#include <QPen>
#include <QTableView>

#include <sstStr01Lib.h>
#include <sstMath01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>

QT_BEGIN_NAMESPACE
// class QPen;
class QAction;
class QPoint;
class QToolButton;
QT_END_NAMESPACE

// Defines ---------------------------------------------------------------------

// forward declaration ---------------------------------------------------------
class sstQt01PathTabMdlCls;
class TstRec1ModelCls;
class TstRec2ModelCls;
class sstQt01PathStoreViewCls;

// Structures and Classes ------------------------------------------------------
//==============================================================================
/**
* @brief Cls send informations from map to tab
*
* More Comment
*
* Changed: 19.11.18  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 19.11.18
*/
// ----------------------------------------------------------------------------
class sstQt01MapSignalCls
{
  public:   // Public functions
     sstQt01MapSignalCls();   // Constructor
   // ~X();   // Destructor
     //==============================================================================
     /**
     * @brief // getShapeItemListRecNo <BR>
     * dItemRecNo = oMapSignal.getShapeItemListRecNo();
     *
     * @return Shape Item List Record Number
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getShapeItemListRecNo() const;
     //==============================================================================
     /**
     * @brief // setShapeItemListRecNo <BR>
     * oMapSignal.setShapeItemListRecNo ( value);
     *
     * @param value [in] value
     */
     // ----------------------------------------------------------------------------
     void setShapeItemListRecNo(const dREC04RECNUMTYP &value);
     //==============================================================================
     /**
     * @brief // getExternTypeStr <BR>
     * oTypeStr = oMapSignal.getExternTypeStr();
     *
     * @return Extern Type String
     */
     // ----------------------------------------------------------------------------
     std::string getExternTypeStr() const;
     //==============================================================================
     /**
     * @brief // setExternTypeStr <BR>
     * oMapSignal.setExternTypeStr ( value);
     *
     * @param value [in] Extern Type String
     */
     // ----------------------------------------------------------------------------
     void setExternTypeStr(const std::string &value);
     //==============================================================================
     /**
     * @brief // getExternTypeTabRecNo <BR>
     * dItemRecNo = oMapSignal.getExternTypeTabRecNo();
     *
     * @return Extern Type Table record number
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getExternTypeTabRecNo() const;
     //==============================================================================
     /**
     * @brief // setExternTypeTabRecNo <BR>
     * oMapSignal.setExternTypeTabRecNo ( value);
     *
     * @param value [in] Extern Type Table record number
     */
     // ----------------------------------------------------------------------------
     void setExternTypeTabRecNo(const dREC04RECNUMTYP &value);
     //==============================================================================

private:  // Private functions
     dREC04RECNUMTYP dShapeItemListRecNo;  /**< Index No of ShapeItem in Vector list of map */
     std::string     oExternTypeStr;       /**< Type String of extern system */
     dREC04RECNUMTYP dExternTypeTabRecNo;  /**< Type Table record no of extern system */
};
//-----------------------------------------------------------------------------


//==============================================================================
/**
* @brief sst base qt table model class
*
* More Comment
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
class sstQt01TabMdlCls : public QAbstractTableModel
{
    Q_OBJECT
public:
  //==============================================================================
  /**
  * @brief // Constructor sstQt01TabMdlCls <BR>
  * sstQt01TabMdlCls oTabMdl(parent);
  *
  * @param parent [in] parent
  */
  // ----------------------------------------------------------------------------
  sstQt01TabMdlCls(QObject *parent);
  ~sstQt01TabMdlCls();
protected:
  std::vector<unsigned long int> sstTabVector;    /**< Vector maps table record positions when deleting */
private:
};
//==============================================================================
/**
* @brief Definition Enum ShapeType_enum
*
* Type of Shape Item.
*
* Changed: 10.05.16  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 10.05.16
*/
// ----------------------------------------------------------------------------
enum _sstQt01ShapeType_enum
{ eSstQt01PathNoObj,     //!< Path Type No Object
  eSstQt01PathArea,      //!< Path Type Area
  eSstQt01PathCircle,    //!< Path Type Circle
  eSstQt01PathLine,      //!< Path Type Line
  eSstQt01PathPLine,     //!< Path Type Polyline
  eSstQt01PathText,      //!< Path Type Text
  eSstQt01PathObject,    //!< Path Type Object
  eSstQt01PathArc,       //!< Path Type Arc
  eSstQt01PathError,     //!< Path Type Error
};
typedef enum _sstQt01ShapeType_enum sstQt01ShapeType_enum;
//==============================================================================
/**
* @brief String convert class for enum ShapeType_enum
*
* Converts enum to string and back <BR>
*
* Changed: 08.07.15  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstQt01ShapeTypeCls
{
  public:   // Public functions
     sstQt01ShapeTypeCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // convert string II,DD,CC ... to type enum <BR>
     * iStat = oVarType.Str2Enm ( iKey, oTypeStr, &eLocType);
     *
     * @param iKey     [in]  For the moment 0
     * @param oTypeStr [in]  For the moment 0
     * @param eLocType [out] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Str2Enm (int                   iKey,
                              std::string           oTypeStr,
                              sstQt01ShapeType_enum *eLocType);
     //==============================================================================
     /**
     * @brief // convert type enum to cpp var type string II, DD, CC ... <BR>
     * iStat = oVarType.Enm2Str ( iKey, eCppType, *oTypeStr);
     *
     * @param iKey     [in]  For the moment 0
     * @param eCppType [in] For the moment 0
     * @param oTypeStr [out]  return string int, double, char ...
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Enm2Str (int                    iKey,
                  sstQt01ShapeType_enum   eCppType,
                  std::string           *oTypeStr);
     //==============================================================================
  private:  // Private functions
  // int Dum;        /**< Dummy */
};
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
  sstQt01ShapeItem();
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
    * @param ToolTip [in] ToolTip QString
    */
    // ----------------------------------------------------------------------------
    void setToolTip(const QString &ToolTip);
    //==============================================================================
    /**
    * @brief // set tooltip <BR>
    * iStat = oPathItem.setToolTip(ToolTip);
    *
    * @param ToolTip [in] ToolTip std::string
    */
    // ----------------------------------------------------------------------------
    void setToolTip(const std::string &ToolTip);
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
    * @brief // set pen <BR>
    * iStat = oPathItem.setPen(Pen);
    *
    * @param oPen [in] QPen
    */
    // ----------------------------------------------------------------------------
    void setPen(const QPen &oPen);
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
    * @brief // Return Bounding Box of QPainterPath Object <BR>
    * oPath = PathItem.getBoundingBox();
    *
    * @return QRectF
    */
    // ----------------------------------------------------------------------------
    QRectF getBoundingBox() const;
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
    * @brief // Get Pen <BR>
    * oPen = PathItem.getPen();
    *
    * @return QColor
    */
    // ----------------------------------------------------------------------------
    QPen getPen() const;
    //==============================================================================
    /**
    * @brief // Get ToolTip string <BR>
    * oToolTip = oShapeItem.getToolTip();
    *
    * @return QString
    */
    // ----------------------------------------------------------------------------
    QString getToolTip() const;
    //==============================================================================
    /**
    * @brief // createShapeItem
    * iStat = oShapeItem.createShapeItem( path, toolTip, pos, color, eShapeType);
    *
    * @param path         [in] path
    * @param toolTip      [in] tooltip
    * @param pos          [in] pos
    * @param color        [in] color
    * @param eShapeType   [in] Type
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    void createShapeItem(const QPainterPath &path,
                         const QString &toolTip, const QPoint &pos,
                         const QColor &color,
                         sstQt01ShapeType_enum eShapeType);
    //==============================================================================
    /**
    * @brief // Get ShapeType <BR>
    * oPen = PathItem.getShapeType();
    *
    * @return eShapeType
    */
    // ----------------------------------------------------------------------------
    sstQt01ShapeType_enum getShapeType() const;
    //==============================================================================
    /**
    * @brief // set ShapeType <BR>
    * iStat = oPathItem.setShapeType(value);
    *
    * @param value [in] eShapeType
    */
    // ----------------------------------------------------------------------------
    void setShapeType(const sstQt01ShapeType_enum &value);
    //==============================================================================
    /**
    * @brief // Get ID of extern object, for example dxf <BR>
    * dID = PathItem.getExternId();
    *
    * @return dID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getExternId() const;
    //==============================================================================
    /**
    * @brief // set ID of extern object, for example dxf <BR>
    * iStat = oPathItem.setExternId(value);
    *
    * @param value [in] dID
    */
    // ----------------------------------------------------------------------------
    void setExternId(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // Get Number of elements of PainterPath <BR>
    * iSize = PathItem.getSize();
    *
    * @return iSize
    */
    // ----------------------------------------------------------------------------
    int getSize();
    //==============================================================================
    /**
    * @brief // add position to path and set position to null <BR>
    * iStat = oPathItem.updatePosition();
    */
    // ----------------------------------------------------------------------------
    void updatePosition();
    //==============================================================================
    /**
    * @brief // Get extern Type string <BR>
    * oPen = PathItem.getExternStr();
    *
    * @return oTypeString
    */
    // ----------------------------------------------------------------------------
    std::string getExternStr() const;
    //==============================================================================
    /**
    * @brief // set extern Type string <BR>
    * iStat = oPathItem.setExternStr(value);
    *
    * @param value [in] o Type String
    */
    // ----------------------------------------------------------------------------
    void setExternStr(const std::string &value);
    //==============================================================================
    /**
    * @brief // Get Position in intern ShapeDisplayList <BR>
    * dID = oPathItem.getInternId();
    *
    * @return dID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getInternId() const;
    //==============================================================================
    /**
    * @brief // set Position in intern ShapeDisplayList <BR>
    * iStat = oPathItem.setInternId(value);
    *
    * @param value [in] dID
    */
    // ----------------------------------------------------------------------------
    void setInternId(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // get first path element of intern painter path <BR>
    * iStat = oPathItem.getFirstPathElement(value);
    *
    * @param oElement [out] return first path element
    *
    * @return iStat
    */
    // ----------------------------------------------------------------------------
    bool getFirstPathElement(QPainterPath::Element *oElement) const;
    //==============================================================================
    /**
    * @brief // Get Initial position of path when storing <BR>
    * oInitPos = oPathItem.getInitPos();
    *
    * @return InitPosition
    */
    // ----------------------------------------------------------------------------
    sstMath01dPnt2Cls getInitPos() const;
    //==============================================================================
    /**
    * @brief // Set Initial position with storing <BR>
    * oPathItem.setInitPos( oInitPos);
    *
    * @param oInitPos [in] Initial Position of Path
    */
    // ----------------------------------------------------------------------------
    void setInitPos(const sstMath01dPnt2Cls &oInitPos);

private:
    QPainterPath myPath;
    QPoint  myPosition;
    QColor  myColor;
    QPen    myPen;  // Width and Style
    QString myToolTip;  // Normally set from outside system
    sstQt01ShapeType_enum eShapeType;  // Painter Path Area, Circle, Line ...
    dREC04RECNUMTYP dExternID;    /**< Record Identifier of extern object, for example dxf */
    dREC04RECNUMTYP dInternID;    /**< Record Identifier in intern Shape List */
    std::string oExternStr;       /**< String Type Identifier of extern object, for example dxf "LINE" entity string */
    // QPoint oInitPos;              /**< Intertial Position */
    sstMath01dPnt2Cls oInitPos;              /**< Intertial Position */
};
//==============================================================================
/**
* @brief Path Element record plus Color as csv string <BR>
*
* for example: <BR>
* 0;215;193;111;190;0 <BR>
* element type = 0, Coordinates X,Y = 215, 193 <BR>
* Color 111,190,0 RGB <BR>
*
* Changed: 04.09.16  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 04.09.16
*/
// ----------------------------------------------------------------------------
class sstQt01PathElementCsv1Cls
{
  public:   // Public functions
     sstQt01PathElementCsv1Cls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Read path element object from csv string <BR>
     * iStat = oPathElement.ReadFromCsv( iKey, oCsvStr, *oErrStr);
     *
     * @param iKey    [in]     For the moment 0
     * @param oCsvStr [in]  Csv string
     * @param oErrStr [out] Result error string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadFromCsv(int iKey, std::string oCsvStr, std::string *oErrStr);
     //==============================================================================
     /**
     * @brief // write path element object to csv string <BR>
     * iStat = oPathElement.WriteToCsv( iKey, &oCsvStr, &oErrStr);
     *
     * @param iKey    [in]  For the moment 0
     * @param oCsvStr [out] result Csv string with path element / color data
     * @param oErrStr [out] Result error string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WriteToCsv(int iKey, std::string *oCsvStr, std::string *oErrStr);
     //==============================================================================
     /**
     * @brief // Get Title row for PainterPath Csv file <BR>
     * oTitleRowStr = oPathElement.GetCsvFileTitle();
     *
     * @return Title row string
     */
     // ----------------------------------------------------------------------------
     std::string GetCsvFileTitle();
     //==============================================================================
     /**
     * @brief // Get number of data elements in class <BR>
     * uiColumns = oPathElement.ColumnCount();
     *
     * @return Number of data elements
     */
     // ----------------------------------------------------------------------------
     unsigned int ColumnCount();
     //==============================================================================
     /**
     * @brief // set all data to path element object <BR>
     * iStat = oPathElement.setAll( iType, iXX, iYY, oColor);
     *
     * @param iType    [in]  int type
     * @param iXX      [in]  int coordinate x
     * @param iYY      [in]  int coordinate y
     * @param oColor   [in]  color
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     void setAll(int iType,int iXX, int iYY, QColor oColor);
     //==============================================================================
     /**
     * @brief // Get Element Type <BR>
     * oSection = oPathElement.GetIType()
     *
     * @return Type Int
     */
     // ----------------------------------------------------------------------------
     int getIType() const;
     //==============================================================================
     /**
     * @brief // Set Element Type <BR>
     * oPathElement.SetIType ( value);
     *
     * @param value [in] Element type 0,1,2 or 3
     */
     // ----------------------------------------------------------------------------
     void setIType(int value);
     //==============================================================================
     /**
     * @brief // Get X Coordinate <BR>
     *  iXX = oPathElement.GetIXX()
     *
     * @return X Coordinate
     */
     // ----------------------------------------------------------------------------
     int getIXX() const;
     //==============================================================================
     /**
     * @brief // Set X coordinate <BR>
     * oPathElement.SetIXX(oSection);
     *
     * @param value [in] coordinate X
     */
     // ----------------------------------------------------------------------------
     void setIXX(int value);
     //==============================================================================
     /**
     * @brief // add value to X coordinate <BR>
     * oPathElement.addIXX(oValue);
     *
     * @param value [in] coordinate X
     */
     // ----------------------------------------------------------------------------
     void addIXX(int value);
     //==============================================================================
     /**
     * @brief // Get Y Coordinate <BR>
     *  iYY = oPathElement.GetIYY()
     *
     * @return Y Coordinate
     */
     // ----------------------------------------------------------------------------
     int getIYY() const;
     //==============================================================================
     /**
     * @brief // Set Y Coordnate <BR>
     * oPathElement.SetIYY(value);
     *
     * @param value [in] Coordinate Y
     */
     // ----------------------------------------------------------------------------
     void setIYY(int value);
     //==============================================================================
     /**
     * @brief // add value to Y Coordnate <BR>
     * oPathElement.addIYY(value);
     *
     * @param value [in] Coordinate Y
     */
     // ----------------------------------------------------------------------------
     void addIYY(int value);
     //==============================================================================
     /**
     * @brief // Get Color Red <BR>
     *  iColR = oPathElement.GetSection()
     *
     * @return int color red
     */
     // ----------------------------------------------------------------------------
     int getIColR() const;
     //==============================================================================
     /**
     * @brief // Set Color Red <BR>
     * oPathElement.SetColR(value);
     *
     * @param value [in] color red
     */
     // ----------------------------------------------------------------------------
     void setIColR(int value);
     //==============================================================================
     /**
     * @brief // Get Color green <BR>
     *  iColG = oPathElement.GetIColG()
     *
     * @return int color green
     */
     // ----------------------------------------------------------------------------
     int getIColG() const;
     //==============================================================================
     /**
     * @brief // Set color green <BR>
     * oPathElement.setIColG(value);
     *
     * @param value [in] color green
     */
     // ----------------------------------------------------------------------------
     void setIColG(int value);
     //==============================================================================
     /**
     * @brief // Get Color Blue <BR>
     *  iColB = oPathElement.getIColB()
     *
     * @return int color blue
     */
     // ----------------------------------------------------------------------------
     int getIColB() const;
     //==============================================================================
     /**
     * @brief // Set color blue <BR>
     * oPathElement.setIColB(value);
     *
     * @param value [in] color blue
     */
     // ----------------------------------------------------------------------------
     void setIColB(int value);
     //==============================================================================
     /**
     * @brief // Set QColor <BR>
     * oPathElement.setQCol(value);
     *
     * @param oQCol [in] QColor
     */
     // ----------------------------------------------------------------------------
     void setQCol(QColor oQCol);
     //==============================================================================
     /**
     * @brief // Get QColor <BR>
     *  oQCol = oPathElement.getQCol()
     *
     * @return QColor
     */
     // ----------------------------------------------------------------------------
     QColor getQCol();
     //==============================================================================

private:  // Private functions
     int iType;        /**< Shape Item Type */
     int iXX;          /**< Coordinate X */
     int iYY;          /**< Coordinate Y */
     int iColR;        /**< Color Red */
     int iColG;        /**< Color Green */
     int iColB;        /**< Color Blue */
};
//==============================================================================
/**
* @brief Path Element record plus Color as csv string <BR>
*
* for example: <BR>
* 0;215;193;111;190;0 <BR>
* element type = 0, Coordinates X,Y = 215, 193 <BR>
* Color 111,190,0 RGB <BR>
*
* Changed: 04.09.16  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 04.09.16
*/
// ----------------------------------------------------------------------------
class sstQt01PathElementCsv2Cls
{
  public:   // Public functions
     sstQt01PathElementCsv2Cls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Read path element object from csv string <BR>
     * iStat = oPathElement.ReadFromCsv( iKey, oCsvStr, *oErrStr);
     *
     * @param iKey    [in]     For the moment 0
     * @param oCsvStr [in]  Csv string
     * @param oErrStr [out] Result error string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadFromCsv(int iKey, std::string oCsvStr, std::string *oErrStr);
     //==============================================================================
     /**
     * @brief // write path element object to csv string <BR>
     * iStat = oPathElement.WriteToCsv( iKey, &oCsvStr, &oErrStr);
     *
     * @param iKey    [in]  For the moment 0
     * @param oCsvStr [out] result Csv string with path element / color data
     * @param oErrStr [out] Result error string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WriteToCsv(int iKey, std::string *oCsvStr, std::string *oErrStr);
     //==============================================================================
     /**
     * @brief // Get Title row for PainterPath Csv file <BR>
     * oTitleRowStr = oPathElement.GetCsvFileTitle();
     *
     * @return Title row string
     */
     // ----------------------------------------------------------------------------
     std::string GetCsvFileTitle();
     //==============================================================================
     /**
     * @brief // Get number of data elements in class <BR>
     * uiColumns = oPathElement.ColumnCount();
     *
     * @return Number of data elements
     */
     // ----------------------------------------------------------------------------
     unsigned int ColumnCount();
     //==============================================================================
     /**
     * @brief // set all data to path element object <BR>
     * iStat = oPathElement.setAll( iType, iXX, iYY, oColor);
     *
     * @param iType    [in]  int type
     * @param iXX      [in]  int coordinate x
     * @param iYY      [in]  int coordinate y
     * @param oColor   [in]  color
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     void setAll(int iType,int iXX, int iYY, QColor oColor);
     //==============================================================================
     /**
     * @brief // set all data to path element object <BR>
     * iStat = oPathElement.setAll( iType, iXX, iYY, oColor);
     *
     * @param iTmpType    [in]  int type
     * @param iTmpXX      [in]  int coordinate x
     * @param iTmpYY      [in]  int coordinate y
     * @param oTmpCol     [in]  color
     * @param oTmpPen     [in]  color
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     void setAll(int iTmpType,int iTmpXX, int iTmpYY, QColor oTmpCol, QPen oTmpPen);
     //==============================================================================
     /**
     * @brief // Get Element Type <BR>
     * oSection = oPathElement.GetIType()
     *
     * @return Type Int
     */
     // ----------------------------------------------------------------------------
     int getIType() const;
     //==============================================================================
     /**
     * @brief // Set Element Type <BR>
     * oPathElement.SetIType ( value);
     *
     * @param value [in] Element type 0,1,2 or 3
     */
     // ----------------------------------------------------------------------------
     void setIType(int value);
     //==============================================================================
     /**
     * @brief // Get X Coordinate <BR>
     *  iXX = oPathElement.GetIXX()
     *
     * @return X Coordinate
     */
     // ----------------------------------------------------------------------------
     int getIXX() const;
     //==============================================================================
     /**
     * @brief // Set X coordinate <BR>
     * oPathElement.SetIXX(oSection);
     *
     * @param value [in] coordinate X
     */
     // ----------------------------------------------------------------------------
     void setIXX(int value);
     //==============================================================================
     /**
     * @brief // add value to X coordinate <BR>
     * oPathElement.addIXX(oValue);
     *
     * @param value [in] coordinate X
     */
     // ----------------------------------------------------------------------------
     void addIXX(int value);
     //==============================================================================
     /**
     * @brief // Get Y Coordinate <BR>
     *  iYY = oPathElement.GetIYY()
     *
     * @return Y Coordinate
     */
     // ----------------------------------------------------------------------------
     int getIYY() const;
     //==============================================================================
     /**
     * @brief // Set Y Coordnate <BR>
     * oPathElement.SetIYY(value);
     *
     * @param value [in] Coordinate Y
     */
     // ----------------------------------------------------------------------------
     void setIYY(int value);
     //==============================================================================
     /**
     * @brief // add value to Y Coordnate <BR>
     * oPathElement.addIYY(value);
     *
     * @param value [in] Coordinate Y
     */
     // ----------------------------------------------------------------------------
     void addIYY(int value);
     //==============================================================================
     /**
     * @brief // Get Color Red <BR>
     *  iColR = oPathElement.GetSection()
     *
     * @return int color red
     */
     // ----------------------------------------------------------------------------
     int getIColR() const;
     //==============================================================================
     /**
     * @brief // Set Color Red <BR>
     * oPathElement.SetColR(value);
     *
     * @param value [in] color red
     */
     // ----------------------------------------------------------------------------
     void setIColR(int value);
     //==============================================================================
     /**
     * @brief // Get Color green <BR>
     *  iColG = oPathElement.GetIColG()
     *
     * @return int color green
     */
     // ----------------------------------------------------------------------------
     int getIColG() const;
     //==============================================================================
     /**
     * @brief // Set color green <BR>
     * oPathElement.setIColG(value);
     *
     * @param value [in] color green
     */
     // ----------------------------------------------------------------------------
     void setIColG(int value);
     //==============================================================================
     /**
     * @brief // Get Color Blue <BR>
     *  iColB = oPathElement.getIColB()
     *
     * @return int color blue
     */
     // ----------------------------------------------------------------------------
     int getIColB() const;
     //==============================================================================
     /**
     * @brief // Set color blue <BR>
     * oPathElement.setIColB(value);
     *
     * @param value [in] color blue
     */
     // ----------------------------------------------------------------------------
     void setIColB(int value);
     //==============================================================================
     /**
     * @brief // Set QColor <BR>
     * oPathElement.setQCol(value);
     *
     * @param oQCol [in] QColor
     */
     // ----------------------------------------------------------------------------
     void setQCol(QColor oQCol);
     //==============================================================================
     /**
     * @brief // Get QColor <BR>
     *  oQCol = oPathElement.getQCol()
     *
     * @return QColor
     */
     // ----------------------------------------------------------------------------
     QColor getQCol();
     //==============================================================================
     /**
     * @brief // Get pen width <BR>
     *  oQCol = oPathElement.getIPenWidth();
     *
     * @return QColor
     */
     // ----------------------------------------------------------------------------
     int getIPenWidth() const;
     //==============================================================================
     /**
     * @brief // Set Pen Width <BR>
     * oPathElement.setIPenWidth(value);
     *
     * @param value [in] Pen Width
     */
     // ----------------------------------------------------------------------------
     void setIPenWidth(int value);
     //==============================================================================
     /**
     * @brief // Get Pen Style <BR>
     *  iPenStyle = oPathElement.getIPenStyle()
     *
     * @return int Pen Style
     */
     // ----------------------------------------------------------------------------
     int getIPenStyle() const;
     //==============================================================================
     /**
     * @brief // Set Pen Style <BR>
     * oPathElement.setIPenStyle(value);
     *
     * @param value [in] Pen Style
     */
     // ----------------------------------------------------------------------------
     void setIPenStyle(int value);
     //==============================================================================
     /**
     * @brief // Set from format version 1 record <BR>
     * oPathElement.setFromVers1(oShapeItemCsv1);
     *
     * @param oShapeItemCsv1 [in] Format version 1 record
     */
     // ----------------------------------------------------------------------------
     void setFromVers1(sstQt01PathElementCsv1Cls oShapeItemCsv1);
     //==============================================================================

private:  // Private functions
     int iType;        /**< Shape Item Type */
     int iXX;          /**< Coordinate X */
     int iYY;          /**< Coordinate Y */
     int iColR;        /**< Color Red */
     int iColG;        /**< Color Green */
     int iColB;        /**< Color Blue */
     int iPenWidth;    /**< Pen Width NEW */
     int iPenStyle;    /**< Pen Style NEW */

};
//==============================================================================
/**
* @brief Path Element record plus Color as csv string <BR>
*
* for example: <BR>
* 0;215;193;111;190;0 <BR>
* element type = 0, Coordinates X,Y = 215, 193 <BR>
* Color 111,190,0 RGB <BR>
*
* Changed: 04.09.16  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 04.09.16
*/
// ----------------------------------------------------------------------------
class sstQt01PathElementCsv3Cls
{
  public:   // Public functions
     sstQt01PathElementCsv3Cls();  // Constructor
     //==============================================================================
     /**
     * @brief // Read path element object from csv string <BR>
     * iStat = oPathElement.ReadFromCsv( iKey, oCsvStr, *oErrStr);
     *
     * @param iKey    [in]     For the moment 0
     * @param oCsvStr [in]  Csv string
     * @param oErrStr [out] Result error string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadFromCsv(int iKey, std::string oCsvStr, std::string *oErrStr);
     //==============================================================================
     /**
     * @brief // write path element object to csv string <BR>
     * iStat = oPathElement.WriteToCsv( iKey, &oCsvStr, &oErrStr);
     *
     * @param iKey    [in]  For the moment 0
     * @param oCsvStr [out] result Csv string with path element / color data
     * @param oErrStr [out] Result error string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WriteToCsv(int iKey, std::string *oCsvStr, std::string *oErrStr);
     //==============================================================================
     /**
     * @brief // Get Title row for PainterPath Csv file <BR>
     * oTitleRowStr = oPathElement.GetCsvFileTitle();
     *
     * @return Title row string
     */
     // ----------------------------------------------------------------------------
     std::string GetCsvFileTitle();
     //==============================================================================
     /**
     * @brief // Get number of data elements in class <BR>
     * uiColumns = oPathElement.ColumnCount();
     *
     * @return Number of data elements
     */
     // ----------------------------------------------------------------------------
     unsigned int ColumnCount();
     //==============================================================================
     /**
     * @brief // set all data to path element object <BR>
     * iStat = oPathElement.setAll( iType, iXX, iYY, oColor);
     *
     * @param iType    [in]  int type
     * @param iXX      [in]  int coordinate x
     * @param iYY      [in]  int coordinate y
     * @param oColor   [in]  color
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     void setAll(int iType,int iXX, int iYY, QColor oColor);
     //==============================================================================
     /**
     * @brief // set all data to path element object <BR>
     * iStat = oPathElement.setAll( iType, iXX, iYY, oColor);
     *
     * @param iTmpType    [in]  int type
     * @param iTmpXX      [in]  int coordinate x
     * @param iTmpYY      [in]  int coordinate y
     * @param oTmpCol     [in]  color
     * @param oTmpPen     [in]  color
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     void setAll(int iTmpType,int iTmpXX, int iTmpYY, QColor oTmpCol, QPen oTmpPen);
     //==============================================================================
     /**
     * @brief // Get Element Type <BR>
     * oSection = oPathElement.GetIType()
     *
     * @return Type Int
     */
     // ----------------------------------------------------------------------------
     int getIType() const;
     //==============================================================================
     /**
     * @brief // Set Element Type <BR>
     * oPathElement.SetIType ( value);
     *
     * @param value [in] Element type 0,1,2 or 3
     */
     // ----------------------------------------------------------------------------
     void setIType(int value);
     //==============================================================================
     /**
     * @brief // Get X Coordinate <BR>
     *  iXX = oPathElement.GetIXX()
     *
     * @return X Coordinate
     */
     // ----------------------------------------------------------------------------
     int getIXX() const;
     //==============================================================================
     /**
     * @brief // Set X coordinate <BR>
     * oPathElement.SetIXX(oSection);
     *
     * @param value [in] coordinate X
     */
     // ----------------------------------------------------------------------------
     void setIXX(int value);
     //==============================================================================
     /**
     * @brief // add value to X coordinate <BR>
     * oPathElement.addIXX(oValue);
     *
     * @param value [in] coordinate X
     */
     // ----------------------------------------------------------------------------
     void addIXX(int value);
     //==============================================================================
     /**
     * @brief // Get Y Coordinate <BR>
     *  iYY = oPathElement.GetIYY()
     *
     * @return Y Coordinate
     */
     // ----------------------------------------------------------------------------
     int getIYY() const;
     //==============================================================================
     /**
     * @brief // Set Y Coordnate <BR>
     * oPathElement.SetIYY(value);
     *
     * @param value [in] Coordinate Y
     */
     // ----------------------------------------------------------------------------
     void setIYY(int value);
     //==============================================================================
     /**
     * @brief // add value to Y Coordnate <BR>
     * oPathElement.addIYY(value);
     *
     * @param value [in] Coordinate Y
     */
     // ----------------------------------------------------------------------------
     void addIYY(int value);
     //==============================================================================
     /**
     * @brief // Get Color Red <BR>
     *  iColR = oPathElement.GetSection()
     *
     * @return int color red
     */
     // ----------------------------------------------------------------------------
     int getIColR() const;
     //==============================================================================
     /**
     * @brief // Set Color Red <BR>
     * oPathElement.SetColR(value);
     *
     * @param value [in] color red
     */
     // ----------------------------------------------------------------------------
     void setIColR(int value);
     //==============================================================================
     /**
     * @brief // Get Color green <BR>
     *  iColG = oPathElement.GetIColG()
     *
     * @return int color green
     */
     // ----------------------------------------------------------------------------
     int getIColG() const;
     //==============================================================================
     /**
     * @brief // Set color green <BR>
     * oPathElement.setIColG(value);
     *
     * @param value [in] color green
     */
     // ----------------------------------------------------------------------------
     void setIColG(int value);
     //==============================================================================
     /**
     * @brief // Get Color Blue <BR>
     *  iColB = oPathElement.getIColB()
     *
     * @return int color blue
     */
     // ----------------------------------------------------------------------------
     int getIColB() const;
     //==============================================================================
     /**
     * @brief // Set color blue <BR>
     * oPathElement.setIColB(value);
     *
     * @param value [in] color blue
     */
     // ----------------------------------------------------------------------------
     void setIColB(int value);
     //==============================================================================
     /**
     * @brief // Set QColor <BR>
     * oPathElement.setQCol(value);
     *
     * @param oQCol [in] QColor
     */
     // ----------------------------------------------------------------------------
     void setQCol(QColor oQCol);
     //==============================================================================
     /**
     * @brief // Get QColor <BR>
     *  oQCol = oPathElement.getQCol()
     *
     * @return QColor
     */
     // ----------------------------------------------------------------------------
     QColor getQCol();
     //==============================================================================
     /**
     * @brief // Get pen width <BR>
     *  oQCol = oPathElement.getIPenWidth();
     *
     * @return QColor
     */
     // ----------------------------------------------------------------------------
     int getIPenWidth() const;
     //==============================================================================
     /**
     * @brief // Set Pen Width <BR>
     * oPathElement.setIPenWidth(value);
     *
     * @param value [in] Pen Width
     */
     // ----------------------------------------------------------------------------
     void setIPenWidth(int value);
     //==============================================================================
     /**
     * @brief // Get Pen Style <BR>
     *  iPenStyle = oPathElement.getIPenStyle()
     *
     * @return int Pen Style
     */
     // ----------------------------------------------------------------------------
     int getIPenStyle() const;
     //==============================================================================
     /**
     * @brief // Set Pen Style <BR>
     * oPathElement.setIPenStyle(value);
     *
     * @param value [in] Pen Style
     */
     // ----------------------------------------------------------------------------
     void setIPenStyle(int value);
     //==============================================================================
     /**
     * @brief // Set from format version 2 record <BR>
     * oPathElement.setFromVers2(oShapeItemCsv2);
     *
     * @param oShapeItemCsv2 [in] Format version 2 record
     */
     // ----------------------------------------------------------------------------
     void setFromVers2(sstQt01PathElementCsv2Cls oShapeItemCsv2);
     //==============================================================================
     /**
     * @brief // Get ShapeType <BR>
     * eTypePen = PathElement.getShapeType();
     *
     * @return eShapeType
     */
     // ----------------------------------------------------------------------------
     sstQt01ShapeType_enum getShapeType() const;
     //==============================================================================
     /**
     * @brief // Get ShapeType <BR>
     * eTypePen = PathElement.getShapeType();
     *
     * @return eShapeType
     */
     // ----------------------------------------------------------------------------
     // std::string getSType() const;
     QString getSType() const;
     //==============================================================================
     /**
     * @brief // set ShapeType <BR>
     * iStat = oPathElement.setShapeType(value);
     *
     * @param value [in] eShapeType
     */
     // ----------------------------------------------------------------------------
     void setShapeType(const sstQt01ShapeType_enum &value);
     //==============================================================================
     /**
     * @brief // set ShapeType <BR>
     * iStat = oPathElement.setShapeType(value);
     *
     * @param value [in] ShapeType as string
     */
     // ----------------------------------------------------------------------------
     // void setSType(const std::string &value);
     void setSType(const QString value);
     //==============================================================================
     /**
     * @brief // return type of path csv row <BR>
     * iStat = oPathElement.isShapeType();
     *
     * @return bool true or false is Shape Type
     */
     // ----------------------------------------------------------------------------
     bool isShapeType();
     //==============================================================================

private:  // Private functions
     int iType;        /**< Shape Item Type */
     int iXX;          /**< Coordinate X */
     int iYY;          /**< Coordinate Y */
     int iColR;        /**< Color Red */
     int iColG;        /**< Color Green */
     int iColB;        /**< Color Blue */
     int iPenWidth;    /**< Pen Width */
     int iPenStyle;    /**< Pen Style */
     // char cItemType[11];   /**< Area, Circle,Line,Polyline,Arc,Text */
     sstQt01ShapeType_enum eShapeType;   /**< Area, Circle,Line,Polyline,Arc,Text */

};
//==============================================================================
/**
* @brief Path Element record plus Color as csv string <BR>
*
* for example: <BR>
* 0;215;193;111;190;0 <BR>
* element type = 0, Coordinates X,Y = 215, 193 <BR>
* Color 111,190,0 RGB <BR>
*
* Changed: 04.09.16  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 04.09.16
*/
// ----------------------------------------------------------------------------
class sstQt01PathMainRecCls
{
  public:   // Public functions
     sstQt01PathMainRecCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Read path element object from csv string <BR>
     * iStat = oPathElement.ReadFromCsv( iKey, oCsvStr, *oErrStr);
     *
     * @param iKey    [in]     For the moment 0
     * @param oCsvStr [in]  Csv string
     * @param oErrStr [out] Result error string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadFromCsv(int iKey, std::string oCsvStr, std::string *oErrStr);
     //==============================================================================
     /**
     * @brief // write path element object to csv string <BR>
     * iStat = oPathElement.WriteToCsv( iKey, &oCsvStr, &oErrStr);
     *
     * @param iKey    [in]  For the moment 0
     * @param oCsvStr [out] result Csv string with path element / color data
     * @param oErrStr [out] Result error string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WriteToCsv(int iKey, std::string *oCsvStr, std::string *oErrStr);
     //==============================================================================
     /**
     * @brief // Get Title row for PainterPath Csv file <BR>
     * oTitleRowStr = oPathElement.GetCsvFileTitle();
     *
     * @return Title row string
     */
     // ----------------------------------------------------------------------------
     std::string GetCsvFileTitle();
     //==============================================================================
     /**
     * @brief // set all data to path element object <BR>
     * iStat = oPathElement.setAll( iType, iXX, iYY, oColor);
     *
     * @param iType    [in]  int type
     * @param iXX      [in]  int coordinate x
     * @param iYY      [in]  int coordinate y
     * @param oColor   [in]  color
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     void setAll(int iType,int iXX, int iYY, QColor oColor);
     //==============================================================================
     /**
     * @brief // Get Element Type <BR>
     * oSection = oPathElement.GetIType()
     *
     * @return Type Int
     */
     // ----------------------------------------------------------------------------
     int getIType() const;
     //==============================================================================
     /**
     * @brief // Set Element Type <BR>
     * oPathElement.SetIType ( value);
     *
     * @param value [in] Element type 0,1,2 or 3
     */
     // ----------------------------------------------------------------------------
     void setIType(int value);
     //==============================================================================
     /**
     * @brief // Get X Coordinate <BR>
     *  iXX = oPathElement.GetIXX()
     *
     * @return X Coordinate
     */
     // ----------------------------------------------------------------------------
     int getIXX() const;
     //==============================================================================
     /**
     * @brief // Set X coordinate <BR>
     * oPathElement.SetIXX(oSection);
     *
     * @param value [in] coordinate X
     */
     // ----------------------------------------------------------------------------
     void setIXX(int value);
     //==============================================================================
     /**
     * @brief // Get Y Coordinate <BR>
     *  iYY = oPathElement.GetIYY()
     *
     * @return Y Coordinate
     */
     // ----------------------------------------------------------------------------
     int getIYY() const;
     //==============================================================================
     /**
     * @brief // Set Y Coordnate <BR>
     * oPathElement.SetIYY(value);
     *
     * @param value [in] Coordinate Y
     */
     // ----------------------------------------------------------------------------
     void setIYY(int value);
     //==============================================================================
     /**
     * @brief // Get Color Red <BR>
     *  iColR = oPathElement.GetSection()
     *
     * @return int color red
     */
     // ----------------------------------------------------------------------------
     int getIColR() const;
     //==============================================================================
     /**
     * @brief // Set Color Red <BR>
     * oPathElement.SetColR(value);
     *
     * @param value [in] color red
     */
     // ----------------------------------------------------------------------------
     void setIColR(int value);
     //==============================================================================
     /**
     * @brief // Get Color green <BR>
     *  iColG = oPathElement.GetIColG()
     *
     * @return int color green
     */
     // ----------------------------------------------------------------------------
     int getIColG() const;
     //==============================================================================
     /**
     * @brief // Set color green <BR>
     * oPathElement.setIColG(value);
     *
     * @param value [in] color green
     */
     // ----------------------------------------------------------------------------
     void setIColG(int value);
     //==============================================================================
     /**
     * @brief // Get Color Blue <BR>
     *  iColB = oPathElement.getIColB()
     *
     * @return int color blue
     */
     // ----------------------------------------------------------------------------
     int getIColB() const;
     //==============================================================================
     /**
     * @brief // Set color blue <BR>
     * oPathElement.setIColB(value);
     *
     * @param value [in] color blue
     */
     // ----------------------------------------------------------------------------
     void setIColB(int value);
     //==============================================================================
     /**
     * @brief // Set tooltip string <BR>
     * oPathItem.setTooltip(oTooltip);
     *
     * @param oTooltip [in] tooltip string
     */
     // ----------------------------------------------------------------------------
     void setTooltip(std::string oTooltip);
     //==============================================================================
     /**
     * @brief // Get Tooltip string <BR>
     * oTooltipStr = oPathItem.getTooltip();
     *
     * @return Tooltip String
     */
     // ----------------------------------------------------------------------------
     std::string getTooltip();
     //==============================================================================
     /**
     * @brief // Set QColor <BR>
     * oPathItem.setQCol(value);
     *
     * @param oQCol [in] QColor
     */
     // ----------------------------------------------------------------------------
     void setQCol(QColor oQCol);
     //==============================================================================
     /**
     * @brief // Get QColor <BR>
     *  oQCol = oPathItem.getQCol()
     *
     * @return QColor
     */
     // ----------------------------------------------------------------------------
     QColor getQCol();
     //==============================================================================
     /**
     * @brief // Get start record number in element table <BR>
     *  iColR = oPathItem.GetStartElementRecNo()
     *
     * @return start record number in element table
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getStartElementRecNo() const;
     //==============================================================================
     /**
     * @brief // Set start record number in element table <BR>
     * oPathItem.setStartElementRecNo(value);
     *
     * @param value [in] start record number in element table
     */
     // ----------------------------------------------------------------------------
     void setStartElementRecNo(const dREC04RECNUMTYP &value);
     //==============================================================================
     /**
     * @brief // Get start record number in element table <BR>
     *  iColR = oPathItem.GetNumElements()
     *
     * @return number of elements in actual path
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getNumElements() const;
     //==============================================================================
     /**
     * @brief // Set Number of elements <BR>
     * oPathItem.setNumElements(value);
     *
     * @param value [in] Number of elemnts
     */
     // ----------------------------------------------------------------------------
     void setNumElements(const dREC04RECNUMTYP &value);
     //==============================================================================
     /**
     * @brief // Get end record number in element table <BR>
     *  iColR = oPathItem.GetEndElementRecNo()
     *
     * @return end record number in element table
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getEndElementRecNo() const;
     //==============================================================================
     /**
     * @brief // Set position <BR>
     * oPathItem.setPosition(oPosition);
     *
     * @param oPosition [in] position
     */
     // ----------------------------------------------------------------------------
     void setPosition(QPoint oPosition);
     //==============================================================================
     /**
     * @brief // Get position <BR>
     *  oPosition = oPathItem.getPosition()
     *
     * @return QPoint position
     */
     // ----------------------------------------------------------------------------
     QPoint getPosition();
     //==============================================================================
     /**
     * @brief // Get Pen <BR>
     *  oPosition = oPathItem.getQPen()
     *
     * @return QPen pen
     */
     // ----------------------------------------------------------------------------
     QPen getQPen();
     //==============================================================================
     /**
     * @brief // Set pen <BR>
     * oPathItem.setQPen ( oQPen);
     *
     * @param oQPen [in] QPen
     */
     // ----------------------------------------------------------------------------
     void setQPen(QPen oQPen);
     //==============================================================================
     /**
     * @brief // Get Pen <BR>
     *  oPosition = oPathItem.getQPen()
     *
     * @return QPen pen
     */
     // ----------------------------------------------------------------------------
     int getIPenStyle() const;
     //==============================================================================
     /**
     * @brief // Set position <BR>
     * oPathItem.setIPenStyle( value);
     *
     * @param value [in] pen style
     */
     // ----------------------------------------------------------------------------
     void setIPenStyle(int value);
     //==============================================================================
     /**
     * @brief // Get Pen <BR>
     *  oPosition = oPathItem.getQPen()
     *
     * @return QPen pen
     */
     // ----------------------------------------------------------------------------
     int getIPenWidth() const;
     //==============================================================================
     /**
     * @brief // Set pen width <BR>
     * oPathItem.setIPenWidth( value);
     *
     * @param value [in] Pen Width
     */
     // ----------------------------------------------------------------------------
     void setIPenWidth(int value);
     //==============================================================================
     /**
     * @brief // Get ShapeType <BR>
     * oPen = PathItem.getShapeType();
     *
     * @return eShapeType
     */
     // ----------------------------------------------------------------------------
     sstQt01ShapeType_enum getShapeType() const;
     //==============================================================================
     /**
     * @brief // set ShapeType <BR>
     * iStat = oPathItem.setShapeType(value);
     *
     * @param value [in] eShapeType
     */
     // ----------------------------------------------------------------------------
     void setShapeType(const sstQt01ShapeType_enum &value);
     //==============================================================================
     /**
     * @brief // Get ID of extern object, for example dxf <BR>
     * dID = PathItem.getId();
     *
     * @return dID
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getExternId() const;
     //==============================================================================
     /**
     * @brief // set ID of extern object, for example dxf <BR>
     * iStat = oPathItem.setId(value);
     *
     * @param value [in] dID
     */
     // ----------------------------------------------------------------------------
     void setExternId(const dREC04RECNUMTYP &value);
     //==============================================================================

private:
     int iXX;        /**< Position X */
     int iYY;        /**< Position Y */
     int iColR;        /**< Color Red */
     int iColG;        /**< Color Green */
     int iColB;        /**< Color Blue */
     int iPenStyle;
     int iPenWidth;
     char cTooltip[30];  /**< Tooltip char string */
     dREC04RECNUMTYP dStartElementRecNo;  /**< Start of Path in Element table */
     dREC04RECNUMTYP dNumElements;        /**< Number of elements in path */
     dREC04RECNUMTYP dExternID;           /**< Identifier of extern object, for example dxf */
     sstQt01ShapeType_enum eShapeType;    /**< Area, Circle,Line,Polyline,Arc,Text */
};
//==============================================================================
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
  //==============================================================================
  /**
  * @brief // Constructur <BR>
  *
  * @param poPrt [in out] Protocol object
  */
  // ----------------------------------------------------------------------------
  sstQt01PathStorageCls(sstMisc01PrtFilCls *poPrt);  // Constructor
  ~sstQt01PathStorageCls();  // Destructor
  //==============================================================================
  /**
  * @brief // Load all pathes record rows from csv file into sst table object.  <BR>
  * iStat = oPathStorage.LoadAllPathFromFile (iKey, oFilNam);
  *
  * Format Version 2
  *
  * @param iKey    [in] For the moment 0
  * @param oFilNam [in] File name
  *
  * @return Errorstate
  *
  * @retval   =  0: OK
  * @retval   = -1: Wrong Key
  * @retval   = -2: File not found
  * @retval   = -3: Wrong File Header
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int LoadAllPathFromFile (int iKey, std::string oFilNam);
     /**
     * @brief // store all pathes from sst table object into csv file.  <BR>
     * iStat = oPathStorage.StoreAllPathToFile (iKey, oFilNam);
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
     * iStat = oPathStorage.AppendPath (iKey, oPath, ePathType, oColor, oPen);
     *
     * @param iKey      [in] For the moment 0
     * @param oPath     [in] QPainterPath object to store
     * @param ePathType [in] Color of Path
     * @param oColor    [in] Color of Path
     * @param oPen      [in] Color of Path
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int AppendPath(int                   iKey,
                    QPainterPath          oPath,
                    sstQt01ShapeType_enum ePathType,
                    QColor                oColor,
                    QPen                  oPen);
     //==============================================================================
     /**
     * @brief // append one QPainterPath at end of sst symbol table object  <BR>
     * iStat = oPathStorage.AppendPathSymbol (iKey, oPath, ePathType, oColor, oPen);
     *
     * @param iKey      [in] For the moment 0
     * @param oPath     [in] QPainterPath object to store
     * @param ePathType [in] Color of Path
     * @param oColor    [in] Color of Path
     * @param oPen      [in] Color of Path
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int AppendPathSymbol(int                   iKey,
                    QPainterPath          oPath,
                    sstQt01ShapeType_enum ePathType,
                    QColor                oColor,
                    QPen                  oPen);
     //==============================================================================
     /**
     * @brief // read next QPainterPath object from sst table object.  <BR>
     * iStat = oPathStorage.ReadNextPath (iKey, oPath, oColor);
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
     * iStat = oPathStorage.ReadPath (iKey, dStartElementRecNo, oPath);
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
     * iStat = oPathStorage.RecordCount ();
     *
     * @return Number of stored records
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP RecordCount() const;
     //==============================================================================
     /**
     * @brief // return number of columns of data table  <BR>
     * iStat = oPathStorage.ColumnCount ();
     *
     * @return Number of data table columns
     */
     // ----------------------------------------------------------------------------
     unsigned int ColumnCount() const;
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
     * @brief // mark deleted QPainterPath record in Path element sst table.  <BR>
     * iStat = oPathStorage.DeleteRecPos (iKey, dRecNo);
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
     * @return tooltip Qt String
     */
     // ----------------------------------------------------------------------------
     QString getToolTip(dREC04RECNUMTYP index);
     //==============================================================================
     /**
     * @brief // set tooltip string in main table <BR>
     * iStat = oPathStorage.setTooltip(index,oTooltip);
     *
     * @param index    [in] record number in main table
     * @param oTooltip [in] Tooltip Qt String
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
     * @brief // set tooltip string in main table <BR>
     * iStat = oPathStorage.setTooltip(index,oTooltip);
     *
     * @param index    [in] record number in main table
     * @param oTooltip [in] Tooltip String
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int setToolTip(dREC04RECNUMTYP index, std::string oTooltip);
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
     * @brief // set extern id to shape item in main table <BR>
     * iStat = oPathStorage.setExternID( index, dExternID);
     *
     * @param index     [in] record number in main table
     * @param dExternID [in] Extern ID of ShapeItem
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int setExternID(dREC04RECNUMTYP index, dREC04RECNUMTYP dExternID);
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
     int addPositionSym(dREC04RECNUMTYP index);
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
     * @brief // Get Pen for index path <BR>
     * iStat = oPathStorage.getPen(index);
     *
     * @param index [in] index of path
     *
     * @return Pen
     */
     // ----------------------------------------------------------------------------
     QPen getPen(dREC04RECNUMTYP index);
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
     * @brief // Get Shape Item from path table <BR>
     * iStat = oPathStorage.getShapeItem2(iKey, index, oShapeItem);
     *
     * @param iKey  [in] Zero for the moment
     * @param index [in] index of path
     * @param oShapeItem [out] index of path
     *
     * @return Path geometry
     */
     // ----------------------------------------------------------------------------
     int getShapeItem2(int iKey, dREC04RECNUMTYP index,sstQt01ShapeItem *oShapeItem);
     //==============================================================================
     /**
     * @brief // append item to storage at table end <BR>
     * iStat = oPathStorage.appendShapeItem(oItem);
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
     * @brief // append symbol item to storage at symbol table end <BR>
     * iStat = oPathStorage.appendItemSymbol(oItem);
     *
     * @param oItem [in] sst Shape item to append to table storage
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int appendItemSymbol(sstQt01ShapeItem oItem);
     //==============================================================================
     /**
     * @brief // return number of sst shape items in storage <BR>
     * iStat = oPathStorage.countItems();
     *
     * @return int number of actual stored shape items
     */
     // ----------------------------------------------------------------------------
     int countItems();
     //==============================================================================
     /**
     * @brief // create in empty path storage circle, square and triangel sst item <BR>
     * iStat = oPathStorage.createDefaultItems(iKey);
     *
     * @param iKey [in] Zero for the moment
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int createDefaultItems(int iKey);
     //==============================================================================
     /**
     * @brief // Search PathItem in Main Table with Row Num from Element Table <BR>
     * iStat = oPathStorage.SearchPathItem ( iKey, dRowNum, dItemNum);
     *
     * @param iKey     [in] For the moment 0
     * @param dRowNum  [in] Row Number in Element Table
     * @param dItemNum [out] Row Num in Main Table
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int SearchPathItem(int iKey, dREC04RECNUMTYP dRowNum, dREC04RECNUMTYP *dItemNum);
     //==============================================================================
     /**
     * @brief // Delete Path Item with number from storage <BR>
     * iStat = oPathStorage.DeletePathItem( iKey, dItemNum);
     *
     * @param iKey     [in] For the moment 0
     * @param dItemNum [in] Record number of item in main table
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int DeletePathItem(int iKey, dREC04RECNUMTYP dItemNum);
     //==============================================================================
     /**
     * @brief // Update number of elements of Path Item in main table <BR>
     * iStat = oPathStorage.UpdatePathItem( iKey, dItemNum);
     *
     * @param iKey     [in] For the moment 0
     * @param dItemNum [in] Record number of item in main table
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int UpdatePathItem (int iKey, dREC04RECNUMTYP dItemNum);
     //==============================================================================
     /**
     * @brief // Update path element table with infos from main table <BR>
     * iStat = oPathStorage.UpdateTabElement( iKey);
     *
     * Update Path Type in element table <BR>
     *
     * @param iKey     [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int UpdateTabElement(int iKey);
     //==============================================================================
     /**
     * @brief // Update color, pen in main tab from element table <BR>
     * iStat = oPathStorage.UpdateMainAttribFromEleTab( iKey);
     *
     * @param iKey     [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int UpdateMainAttribFromElemTab(int iKey);
     //==============================================================================
     /**
     * @brief // Get ID of extern object, for example dxf <BR>
     * dID = oPathStorage.getId(index);
     *
     * @param index   [in] Path number
     *
     * @return dID
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getExternId(dREC04RECNUMTYP index);
     //==============================================================================
     /**
     * @brief // Set Path View Storage from Path Table Storage <BR>
     * iStat = oPathStorage.setViewStoreData( iKey, &poPathViewStore);
     *
     * @param iKey            [in] For the moment 0
     * @param poPathViewStore [in out] Fill Path View Storage
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int setViewStoreData( int iKey, sstQt01PathStoreViewCls *poPathViewStore);
     //==============================================================================
     /**
     * @brief // Write Tooltips to all ShapeItems <BR>
     * iStat = oPathStorage.updateTooltips( iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int updateTooltips (int iKey);
     //==============================================================================
     /**
     * @brief // Replace existing ShapeItem in PathStorage with new one, if possible <BR>
     * iStat = oPathStorage.ReplaceShape( iKey, dIndex, oShapeItem);
     *
     * @param iKey       [in] For the moment 0
     * @param dIndex     [in] Position in PathStorage
     * @param oShapeItem [in] ShapeItem Object for replacing
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   = -1: Wrong Key
     * @retval   = -2: Shape Type wrong
     * @retval   = -2: Shape Size wrong
     * @retval   <  0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReplaceShape(int iKey, dREC04RECNUMTYP dIndex, sstQt01ShapeItem oShapeItem);
     //==============================================================================
     /**
     * @brief // Count elements from stored shape at position index. <BR>
     * dID = oPathStorage.countShapeElements(index);
     *
     * @param dIndex   [in] Path number
     *
     * @return iNumElements
     */
     // ----------------------------------------------------------------------------
     int countShapeElements(dREC04RECNUMTYP dIndex);
     //==============================================================================

  private:  // Private functions
     //==============================================================================
     /**
     * @brief // initialItemPosition <BR>
     * iStat = oPathStorage.initialItemPosition(path);
     *
     * @param path [in] path
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     QPoint initialItemPosition(const QPainterPath &path);
     //==============================================================================
     /**
     * @brief // initialItemColor <BR>
     * iStat = oPathStorage.initialItemColor();
     *
     * @return Color
     */
     // ----------------------------------------------------------------------------
     QColor initialItemColor();
     //==============================================================================
     /**
     * @brief // Find Format Version from csv file header row <BR>
     * iStat = oPathStorage.FindCsvFileVersion(iKey,sFilNam);
     *
     * @param sFilNam [in] Name of close path csv file
     *
     * @return Errorstate
     *
     * @retval   > 0: Format version in file
     * @retval   = 0: Unknown format
     * @retval   = -1: Wrong Key
     * @retval   = -2: File Open Error
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int FindCsvFileVersion(int iKey, const std::string sFilNam);
     //==============================================================================
     /**
     * @brief // Load all pathes record rows from csv file into sst table object.  <BR>
     * iStat = oPathStorage.LoadAllPathFromFile3 (iKey, oFilNam);
     *
     * Format Version 2
     *
     * @param iKey    [in] For the moment 0
     * @param oFilNam [in] File name
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     * @retval   = -2: File not found
     * @retval   = -3: Wrong File Header
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int LoadAllPathFromFile3 (int iKey, std::string oFilNam);
     //==============================================================================
     /**
     * @brief // Load all pathes record rows from csv file into sst table object.  <BR>
     * iStat = oPathStorage.LoadAllPathFromFile2 (iKey, oFilNam);
     *
     * Format Version 2
     *
     * @param iKey    [in] For the moment 0
     * @param oFilNam [in] File name
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     * @retval   = -2: File not found
     * @retval   = -3: Wrong File Header
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int LoadAllPathFromFile2 (int iKey, std::string oFilNam);
     //==============================================================================
     /**
        * @brief // Load all pathes record rows from csv file into sst table object.  <BR>
        * iStat = oPathStorage.LoadAllPathFromFile1 (iKey, oFilNam);
        *
        * Format Version 1
        *
        * @param iKey    [in] For the moment 0
        * @param oFilNam [in] File name
        *
        * @return Errorstate
        *
        * @retval   =  0: OK
        * @retval   = -1: Wrong Key
        * @retval   = -2: File not found
        * @retval   = -3: Wrong File Header
        * @retval   < 0: Unspecified Error
        */
     // ----------------------------------------------------------------------------
     int LoadAllPathFromFile1 (int iKey, std::string oFilNam);
     //==============================================================================
     /**
        * @brief // Update Number of elements per path in Maintable from Elementtable <BR>
        * iStat = oPathStorage.UpdateMainPathSizeFromEleTab(iKey);
        *
        * @param iKey [in] For the moment 0
        *
        * @return Errorstate
        *
        * @retval   = 0: OK
        * @retval   < 0: Unspecified Error
        */
     // ----------------------------------------------------------------------------
     int UpdateMainPathSizeFromEleTab (int iKey);
     //==============================================================================
     /**
        * @brief // Write new Main Record in table if Element is next path <BR>
        * iStat = oPathStorage.NewMainWithElement(iKey);
        *
        * Write Attributes, Tooltip and Start Position to main record
        *
        * @param iKey           [in] For the moment 0
        * @param oShapeItemCsv3 [in] Csv File Row Version 3
        *
        * @return Errorstate
        *
        * @retval   = 0: OK
        * @retval   < 0: Unspecified Error
        */
     // ----------------------------------------------------------------------------
     int NewMainWithElement (int iKey, sstQt01PathElementCsv3Cls *oShapeItemCsv3);
     //==============================================================================
     /**
        * @brief // Get Shapetype of path <BR>
        * dID = oPathStorage.getShapeType(index);
        *
        * @param index   [in] Path number
        *
        * @return dID
        */
     // ----------------------------------------------------------------------------
     sstQt01ShapeType_enum getShapeType(int index);
     //==============================================================================

     sstRec04Cls *poShapeItemRecTable;   /**< painter path element record table */
     sstRec04Cls *poShapeItemMainTable;  /**< painter path main table */
     sstRec04Cls *poShapeItemRecSymTable;   /**< painter path element record Symbol table */
     sstRec04Cls *poShapeItemMainSymTable;  /**< painter path main Symbol table */
     dREC04RECNUMTYP dActualReadPos;     /**< actual read position in Record table */
     dREC04RECNUMTYP dActualReadPosSym;     /**< actual read position in Record table */
     const int height = 300;
     const int width = 500;
     sstMisc01PrtFilCls *poPrt;
     unsigned int uiVersion;             /**< found format Version in csv file */
};
//==============================================================================
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
class sstQt01PathStoreViewCls
{
  public:   // Public functions
  //==============================================================================
  /**
  * @brief // Constructur <BR>
  *
  * @param poPrt [in out] Protocol object
  */
  // ----------------------------------------------------------------------------
  sstQt01PathStoreViewCls(sstMisc01PrtFilCls *poPrt);  // Constructor
  ~sstQt01PathStoreViewCls();  // Destructor
  //==============================================================================
  /**
  * @brief // Load all pathes record rows from csv file into sst table object.  <BR>
  * iStat = oPathStorage.LoadAllPathFromFile (iKey, oFilNam);
  *
  * Format Version 2
  *
  * @param iKey    [in] For the moment 0
  * @param oFilNam [in] File name
  *
  * @return Errorstate
  *
  * @retval   =  0: OK
  * @retval   = -1: Wrong Key
  * @retval   = -2: File not found
  * @retval   = -3: Wrong File Header
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int LoadAllPathFromFile (int iKey, std::string oFilNam);
     /**
     * @brief // store all pathes from sst table object into csv file.  <BR>
     * iStat = oPathStorage.StoreAllPathToFile (iKey, oFilNam);
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
     * iStat = oPathStorage.AppendPath (iKey, oPath, ePathType, oColor, oPen);
     *
     * @param iKey      [in] For the moment 0
     * @param oPath     [in] QPainterPath object to store
     * @param ePathType [in] Color of Path
     * @param oColor    [in] Color of Path
     * @param oPen      [in] Color of Path
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int AppendPath(int                   iKey,
                    QPainterPath          oPath,
                    sstQt01ShapeType_enum ePathType,
                    QColor                oColor,
                    QPen                  oPen);
     //==============================================================================
     /**
     * @brief // append one QPainterPath at end of sst symbol table object  <BR>
     * iStat = oPathStorage.AppendPathSymbol (iKey, oPath, ePathType, oColor, oPen);
     *
     * @param iKey      [in] For the moment 0
     * @param oPath     [in] QPainterPath object to store
     * @param ePathType [in] Color of Path
     * @param oColor    [in] Color of Path
     * @param oPen      [in] Color of Path
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int AppendPathSymbol(int                   iKey,
                    QPainterPath          oPath,
                    sstQt01ShapeType_enum ePathType,
                    QColor                oColor,
                    QPen                  oPen);
     //==============================================================================
     /**
     * @brief // read next QPainterPath object from sst table object.  <BR>
     * iStat = oPathStorage.ReadNextPath (iKey, oPath, oColor);
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
     * iStat = oPathStorage.ReadPath (iKey, dStartElementRecNo, oPath);
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
     * iStat = oPathStorage.RecordCount ();
     *
     * @return Number of stored records
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP RecordCount() const;
     //==============================================================================
     /**
     * @brief // return number of columns of data table  <BR>
     * iStat = oPathStorage.ColumnCount ();
     *
     * @return Number of data table columns
     */
     // ----------------------------------------------------------------------------
     unsigned int ColumnCount() const;
     //==============================================================================
     /**
     * @brief // Get Tooltip string for index path <BR>
     * iStat = oPathStorage.getToolTip(index);
     *
     * @param index [in] index of path
     *
     * @return tooltip Qt String
     */
     // ----------------------------------------------------------------------------
     QString getToolTip(dREC04RECNUMTYP index);
     //==============================================================================
     /**
     * @brief // set tooltip string in main table <BR>
     * iStat = oPathStorage.setTooltip(index,oTooltip);
     *
     * @param index    [in] record number in main table
     * @param oTooltip [in] Tooltip Qt String
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
     * @brief // set tooltip string in main table <BR>
     * iStat = oPathStorage.setTooltip(index,oTooltip);
     *
     * @param index    [in] record number in main table
     * @param oTooltip [in] Tooltip String
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int setToolTip(dREC04RECNUMTYP index, std::string oTooltip);
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
     int addPositionSym(dREC04RECNUMTYP index);
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
     * @brief // Get Pen for index path <BR>
     * iStat = oPathStorage.getPen(index);
     *
     * @param index [in] index of path
     *
     * @return Pen
     */
     // ----------------------------------------------------------------------------
     QPen getPen(dREC04RECNUMTYP index);
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
     * @brief // Get Shape Item from path table <BR>
     * iStat = oPathStorage.getShapeItem2(iKey, index, oShapeItem);
     *
     * @param iKey  [in] Zero for the moment
     * @param index [in] index of path
     * @param oShapeItem [out] index of path
     *
     * @return Path geometry
     */
     // ----------------------------------------------------------------------------
     int getShapeItem2(int iKey, dREC04RECNUMTYP index,sstQt01ShapeItem *oShapeItem);
     //==============================================================================
     /**
     * @brief // append item to storage at table end <BR>
     * iStat = oPathStorage.appendShapeItem(oItem);
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
     * @brief // append symbol item to storage at symbol table end <BR>
     * iStat = oPathStorage.appendItemSymbol(oItem);
     *
     * @param oItem [in] sst Shape item to append to table storage
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int appendItemSymbol(sstQt01ShapeItem oItem);
     //==============================================================================
     /**
     * @brief // return number of sst shape items in storage <BR>
     * iStat = oPathStorage.countItems();
     *
     * @return int number of actual stored shape items
     */
     // ----------------------------------------------------------------------------
     unsigned int countItems();
     //==============================================================================
     /**
     * @brief // create in empty path storage circle, square and triangel sst item <BR>
     * iStat = oPathStorage.createDefaultItems(iKey);
     *
     * @param iKey [in] Zero for the moment
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int createDefaultItems(int iKey);
     //==============================================================================
     /**
     * @brief // Search PathItem in Main Table with Row Num from Element Table <BR>
     * iStat = oPathStorage.SearchPathItem ( iKey, dRowNum, dItemNum);
     *
     * @param iKey     [in] For the moment 0
     * @param dRowNum  [in] Row Number in Element Table
     * @param dItemNum [out] Row Num in Main Table
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int SearchPathItem(int iKey, dREC04RECNUMTYP dRowNum, dREC04RECNUMTYP *dItemNum);
     //==============================================================================
     /**
     * @brief // Delete Path Item with number from storage <BR>
     * iStat = oPathStorage.DeletePathItem( iKey, dItemNum);
     *
     * @param iKey     [in] For the moment 0
     * @param dItemNum [in] Record number of item in main table
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int DeletePathItem(int iKey, dREC04RECNUMTYP dItemNum);
     //==============================================================================
     /**
     * @brief // Update number of elements of Path Item in main table <BR>
     * iStat = oPathStorage.UpdatePathItem( iKey, dItemNum);
     *
     * @param iKey     [in] For the moment 0
     * @param dItemNum [in] Record number of item in main table
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int UpdatePathItem (int iKey, dREC04RECNUMTYP dItemNum);
     //==============================================================================
     /**
     * @brief // Update path element table with infos from main table <BR>
     * iStat = oPathStorage.UpdateTabElement( iKey);
     *
     * Update Path Type in element table <BR>
     *
     * @param iKey     [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int UpdateTabElement(int iKey);
     //==============================================================================
     /**
     * @brief // Update color, pen in main tab from element table <BR>
     * iStat = oPathStorage.UpdateMainAttribFromEleTab( iKey);
     *
     * @param iKey     [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int UpdateMainAttribFromElemTab(int iKey);
     //==============================================================================
     /**
     * @brief // Get ID of extern object, for example dxf <BR>
     * dID = oPathStorage.getId(index);
     *
     * @param index       [in] Path number
     *
     * @return dID
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getExternId(dREC04RECNUMTYP index);
     //==============================================================================
     /**
     * @brief // Replace Shape Item in list Storage <BR>
     * dID = oPathStorage.replaceShapeItem(iKey, dIndex, oShapeItem);
     *
     * @param iKey        [in] For the moment 0
     * @param index       [in] Path number
     * @param oShapeItem  [in] Shape Item for writing
     *
     * @return dID
     */
     // ----------------------------------------------------------------------------
     int replaceShapeItem(int iKey, dREC04RECNUMTYP index, sstQt01ShapeItem oShapeItem);
     //==============================================================================

  private:  // Private functions
     //==============================================================================
     /**
     * @brief // initialItemPosition <BR>
     * iStat = oPathStorage.initialItemPosition(path);
     *
     * @param path [in] path
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     QPoint initialItemPosition(const QPainterPath &path);
     //==============================================================================
     /**
     * @brief // initialItemColor <BR>
     * iStat = oPathStorage.initialItemColor();
     *
     * @return Color
     */
     // ----------------------------------------------------------------------------
     QColor initialItemColor();
     //==============================================================================
     /**
     * @brief // Find Format Version from csv file header row <BR>
     * iStat = oPathStorage.FindCsvFileVersion(iKey,sFilNam);
     *
     * @param sFilNam [in] Name of close path csv file
     *
     * @return Errorstate
     *
     * @retval   > 0: Format version in file
     * @retval   = 0: Unknown format
     * @retval   = -1: Wrong Key
     * @retval   = -2: File Open Error
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int FindCsvFileVersion(int iKey, const std::string sFilNam);
     //==============================================================================
     /**
     * @brief // Load all pathes record rows from csv file into sst table object.  <BR>
     * iStat = oPathStorage.LoadAllPathFromFile3 (iKey, oFilNam);
     *
     * Format Version 2
     *
     * @param iKey    [in] For the moment 0
     * @param oFilNam [in] File name
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     * @retval   = -2: File not found
     * @retval   = -3: Wrong File Header
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int LoadAllPathFromFile3 (int iKey, std::string oFilNam);
     //==============================================================================
     /**
     * @brief // Load all pathes record rows from csv file into sst table object.  <BR>
     * iStat = oPathStorage.LoadAllPathFromFile2 (iKey, oFilNam);
     *
     * Format Version 2
     *
     * @param iKey    [in] For the moment 0
     * @param oFilNam [in] File name
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     * @retval   = -2: File not found
     * @retval   = -3: Wrong File Header
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int LoadAllPathFromFile2 (int iKey, std::string oFilNam);
     //==============================================================================
     /**
        * @brief // Load all pathes record rows from csv file into sst table object.  <BR>
        * iStat = oPathStorage.LoadAllPathFromFile1 (iKey, oFilNam);
        *
        * Format Version 1
        *
        * @param iKey    [in] For the moment 0
        * @param oFilNam [in] File name
        *
        * @return Errorstate
        *
        * @retval   =  0: OK
        * @retval   = -1: Wrong Key
        * @retval   = -2: File not found
        * @retval   = -3: Wrong File Header
        * @retval   < 0: Unspecified Error
        */
     // ----------------------------------------------------------------------------
     int LoadAllPathFromFile1 (int iKey, std::string oFilNam);
     //==============================================================================
     /**
        * @brief // Update Number of elements per path in Maintable from Elementtable <BR>
        * iStat = oPathStorage.UpdateMainPathSizeFromEleTab(iKey);
        *
        * @param iKey [in] For the moment 0
        *
        * @return Errorstate
        *
        * @retval   = 0: OK
        * @retval   < 0: Unspecified Error
        */
     // ----------------------------------------------------------------------------
     int UpdateMainPathSizeFromEleTab (int iKey);
     //==============================================================================
     /**
        * @brief // Write new Main Record in table if Element is next path <BR>
        * iStat = oPathStorage.NewMainWithElement(iKey);
        *
        * Write Attributes, Tooltip and Start Position to main record
        *
        * @param iKey           [in] For the moment 0
        * @param oShapeItemCsv3 [in] Csv File Row Version 3
        *
        * @return Errorstate
        *
        * @retval   = 0: OK
        * @retval   < 0: Unspecified Error
        */
     // ----------------------------------------------------------------------------
     int NewMainWithElement (int iKey, sstQt01PathElementCsv3Cls *oShapeItemCsv3);
     //==============================================================================
     /**
        * @brief // Get Shapetype of path <BR>
        * dID = oPathStorage.getShapeType(index);
        *
        * @param index   [in] Path number
        *
        * @return dID
        */
     // ----------------------------------------------------------------------------
     sstQt01ShapeType_enum getShapeType(int index);
     //==============================================================================

//     sstRec04Cls *poShapeItemRecTable;   /**< painter path element record table */
//     sstRec04Cls *poShapeItemMainTable;  /**< painter path main table */
//     sstRec04Cls *poShapeItemRecSymTable;   /**< painter path element record Symbol table */
//     sstRec04Cls *poShapeItemMainSymTable;  /**< painter path main Symbol table */
     QList<sstQt01ShapeItem> shapeItems;
     dREC04RECNUMTYP dActualReadPos;     /**< actual read position in Record table */
     dREC04RECNUMTYP dActualReadPosSym;     /**< actual read position in Record table */
     const int height = 300;
     const int width = 500;
     sstMisc01PrtFilCls *poPrt;
     unsigned int uiVersion;             /**< found format Version in csv file */
};
//==============================================================================
/**
* @brief Definition Class sstQt01TabViewCls
*
* More Comment
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
  //==============================================================================
  /**
  * @brief // Constructor for sstQt01TabViewCls <BR>
  *
  * @param poPrt         [in out] Pointer to Protocol object
  */
  // ----------------------------------------------------------------------------
  sstQt01TabViewCls(sstMisc01PrtFilCls    *poPrt);
                    //sstQt01PathStorageCls *poPathStorage);    // Constructor
  ~sstQt01TabViewCls();   // Destructor
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

public slots:
    //==============================================================================
    /**
    * @brief Slot -Table data changed- direction table to map
    */
    // ----------------------------------------------------------------------------
    void sstSlotChangeTab(sstQt01ShapeItem oShapeItem);
    //==============================================================================
    /**
    * @brief // slot: sst begin inserting rocords in path storage  <BR>
    * iStat = oTabView.sstSgnlBeginInsertRows(first,last);
    *
    * @param first [in] first record for inserting
    * @param last  [in] last record for inserting
    */
    // ----------------------------------------------------------------------------
    void sstSlotBeginInsertRows(int first, int last);
    //==============================================================================
    /**
    * @brief Slot -Insert records in path storage <BR>
    */
    // ----------------------------------------------------------------------------
    void sstSlotEndInsertRows();
    //==============================================================================
    /**
    * @brief // slot: sst begin deleting records in path storage  <BR>
    * iStat = oTabView.sstSgnlBeginRemoveRows(first,last);
    *
    * @param first [in] first record for deleting
    * @param last  [in] last record for deleting
    */
    // ----------------------------------------------------------------------------
    void sstSlotBeginRemoveRows(int first, int last);
    //==============================================================================
    /**
    * @brief Slot -Insert records in path storage <BR>
    */
    // ----------------------------------------------------------------------------
    void sstSlotEndRemoveRows();
    //==============================================================================
signals:
    //==============================================================================
    /**
    * @brief Signal -Table data changed- direction table to map
    */
    // ----------------------------------------------------------------------------
    void sstSgnlTabChanged(sstQt01ShapeItem oShapeItem);
    //==============================================================================
    /**
    * @brief Signal -Table data changed- direction map to table
    */
    // ----------------------------------------------------------------------------
    void sstSgnlTabUpdated();
    //==============================================================================
    /**
    * @brief // signal: sst begin inserting rocords in path storage  <BR>
    * iStat = oTabView.sstSgnlBeginInsertRows(first,last);
    *
    * @param first [in] first record for inserting
    * @param last  [in] last record for inserting
    */
    // ----------------------------------------------------------------------------
    void sstSgnlBeginInsertRows(int first, int last);
    //==============================================================================
    /**
    * @brief // signal: sst End inserting records in path storage.  <BR>
    */
    // ----------------------------------------------------------------------------
    void sstSgnlEndInsertRows();
    //==============================================================================
    /**
    * @brief // signal: sst begin deleting records in path storage  <BR>
    * iStat = oTabView.sstSgnlBeginRemoveRows(first,last);
    *
    * @param first [in] first record for deleting
    * @param last  [in] last record for deleting
    */
    // ----------------------------------------------------------------------------
    void sstSgnlBeginRemoveRows(int first, int last);
    //==============================================================================
    /**
    * @brief // signal: sst End inserting records in path storage.  <BR>
    */
    // ----------------------------------------------------------------------------
    void sstSgnlEndRemoveRows();
    //==============================================================================

private:  // Private functions
  QAction *cell_InsAction;   /**< Insert Table Rows Action */
  QAction *cell_DelAction;   /**< Delete Table Rows Action */
  sstMisc01PrtFilCls    *poTmpPrt;  /**< Pointer to protocol object */
};
//==============================================================================
/**
* @brief Painter Path Table View Widget Class
*
* Show Painter Path Data as one Table
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
class sstQt01PathTabViewCls : public sstQt01TabViewCls
{
      Q_OBJECT
  public:   // Public functions
  //==============================================================================
  /**
  * @brief // Constructor for sstQt01TabViewCls <BR>
  *
  * @param poPrt         [in out] Pointer to Protocol object
  * @param poPathStorage [in out] Pointer to Path Storage object
  */
  // ----------------------------------------------------------------------------
    sstQt01PathTabViewCls(sstMisc01PrtFilCls    *poPrt,
                      sstQt01PathStorageCls *poPathStorage);    // Constructor
  ~sstQt01PathTabViewCls();   // Destructor
// ----------------------------------------------------------------------------
public slots:
  //==============================================================================
  /**
  * @brief Slot -Table data changed- direction map to table
  */
  // ----------------------------------------------------------------------------
  void sstSlotUpdateTab(sstQt01ShapeItem oShapeItem);
     //==============================================================================
     /**
     * @brief actionRowsInsert
     */
     // ----------------------------------------------------------------------------
  // void actionRowsInsert();
  //==============================================================================
  /**
  * @brief actionRowsDelete
  */
  // ----------------------------------------------------------------------------
  // void actionRowsDelete();

protected:
  //==============================================================================
  /**
  * @brief setup ContextMenu with actions
  */
  // ----------------------------------------------------------------------------
    // void setupContextMenu();
    //==============================================================================
    /**
    * @brief Create actions and connect to slots
    */
    // ----------------------------------------------------------------------------
    // void createActions();

public slots:
    //==============================================================================
    /**
    * @brief Slot Table data changed
    */
    // ----------------------------------------------------------------------------
    // void ChangeTab();
signals:
    //==============================================================================
    /**
    * @brief Signal Table data changed
    */
    // ----------------------------------------------------------------------------
    // void TabChanged();

private:  // Private functions
  // QAction *cell_InsAction;   /**< Insert Table Rows Action */
  // QAction *cell_DelAction;   /**< Delete Table Rows Action */
  sstQt01PathTabMdlCls *poTabMdl;
};
//==============================================================================
/**
* @brief Paint widget for sst path storage <BR>
*
* Move position and create new path items interactive. <BR>
*
* Changed: 26.04.17  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 26.04.17
*/
// ----------------------------------------------------------------------------
class sstQt01PathPaintWidgetCls : public QWidget
{
    Q_OBJECT

public:
  //==============================================================================
  /**
  * @brief // Constructor for PathPaintWidget <BR>
  *
  * @param poPrt         [in] Adress of Protocoll
  * @param poPathStorage [in] Adress of sstPathStorage
  */
  // ----------------------------------------------------------------------------
  sstQt01PathPaintWidgetCls(sstMisc01PrtFilCls    *poPrt,
                            // sstQt01PathStorageCls *poPathStorage);
                            sstQt01PathStoreViewCls *poPathStorage);
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
    //==============================================================================

public slots:
    //==============================================================================
    /**
    * @brief // slot function: sst paint event: map content is changed  <BR>
    */
    // ----------------------------------------------------------------------------
    void sstPaintEvent(sstQt01ShapeItem oShapeItem);
    //==============================================================================
private slots:
    void createNewCircle();
    void createNewSquare();
    void createNewTriangle();
    void createNewLine();
    void createNewPolyLine();
    void createNewArc();
    void createNewText();
signals:
    //==============================================================================
    /**
    * @brief // signal: sst painterpath move release event: map content is changed  <BR>
    */
    // ----------------------------------------------------------------------------
    void sstPathMoveReleaseSgnl(sstQt01ShapeItem oPathItem);
    //==============================================================================
    /**
    * @brief // signal: sst painterpath move release event: map content is changed  <BR>
    */
    // ----------------------------------------------------------------------------
    // void sstExtPathMoveReleaseSgnl(dREC04RECNUMTYP dId);
    // void sstExtPathMoveReleaseSgnl(sstQt01MapSignalCls oMapSignal);
    //==============================================================================
    /**
    * @brief // signal: sst begin inserting records in path storage  <BR>
    * iStat = oPathPaintWidget.sstSgnlBeginInsertRows(first,last);
    *
    * @param first [in] first record for inserting
    * @param last  [in] last record for inserting
    */
    // ----------------------------------------------------------------------------
    void sstSgnlBeginInsertRows(int first, int last);
    //==============================================================================
    /**
    * @brief // signal: sst End inserting records in path storage.  <BR>
    */
    // ----------------------------------------------------------------------------
    void sstSgnlEndInsertRows();
    //==============================================================================
    /**
    * @brief // signal: sst begin deleting records in path storage  <BR>
    * iStat = oPathPaintWidget.sstSgnlBeginRemoveRows(first,last);
    *
    * @param first [in] first record for delete
    * @param last  [in] last record for delete
    */
    // ----------------------------------------------------------------------------
    void sstSgnlBeginRemoveRows(int first, int last);
    //==============================================================================
    /**
    * @brief // signal: sst End deleting records in path storage.  <BR>
    */
    // ----------------------------------------------------------------------------
    void sstSgnlEndRemoveRows();
    //==============================================================================


private:

    int updateButtonGeometry(QToolButton *button, int x, int y);
    void createShapeItem(const QPainterPath &path,
                         // const QString &toolTip,
                         const QPoint &pos,
                         const QColor &color,
                         const QPen &oPen,
                         const sstQt01ShapeType_enum eShapeType);
    int itemAt(const QPoint &pos);
    void moveItemTo(const QPoint &pos);
    int updateTooltips (int iKey);
    // int ItemsCreate (int iKey);
    // using QWidget::minimumSizeHint;
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;


    QPoint initialItemPosition(const QPainterPath &path);
    QPoint randomItemPosition();
    QColor initialItemColor();
    QColor randomItemColor();
    QPen initialItemPen();
    QPen randomItemPen();
    QToolButton *createToolButton(const QString &toolTip, const QIcon &icon,
                                  const char *member);

    // QList<sstQt01ShapeItem> shapeItems;
    QPainterPath circlePath;
    QPainterPath squarePath;
    QPainterPath trianglePath;
    QPainterPath linePath;
    QPainterPath polylinePath;
    QPainterPath arcPath;
    QPainterPath textPath;

    QPoint previousPosition;
    // sstQt01ShapeItem *itemInMotion;
    int iItemInMotionIndex;
    sstQt01ShapeItem oActualItem;
    int iActualItemIndex;

    QToolButton *newCircleButton;
    QToolButton *newSquareButton;
    QToolButton *newTriangleButton;
    QToolButton *newLineButton;
    QToolButton *newPolyLineButton;
    QToolButton *newArcButton;
    QToolButton *newTextButton;
    // sstQt01PathStorageCls *oPathStorage;
    sstQt01PathStoreViewCls *oPathStorage;
    sstMisc01PrtFilCls *poPrt;
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
  //==============================================================================
  /**
  * @brief // Constructor for sstQt01TstRec1ViewCls <BR>
  *
  * @param poPrt         [in] Adress of Protocoll
  */
  // ----------------------------------------------------------------------------
  sstQt01TstRec1ViewCls(sstMisc01PrtFilCls    *poPrt);  // Constructor
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
  //==============================================================================
  /**
  * @brief // Constructor for sstQt01TstRec2ViewCls <BR>
  *
  * @param poPrt         [in] Adress of Protocoll
  */
  // ----------------------------------------------------------------------------
     sstQt01TstRec2ViewCls(sstMisc01PrtFilCls    *poPrt);  // Constructor
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
/**
* @brief TestGroupBoxWidget for 2 Tables TestRec1View and TestRec2View
*
* Changed: 18.10.18  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 18.10.18
*/
// ----------------------------------------------------------------------------
class sstQt01TestGroupBoxCls : public QGroupBox
{
    Q_OBJECT

public:
  //==============================================================================
  /**
  * @brief // Constructor for TestGroupBox <BR>
  * sstQt01TestGroupBoxCls oTestGroupBox( poPrt);
  *
  * @param poPrt [in] Pointer to Protocol object
  */
  // ----------------------------------------------------------------------------
    sstQt01TestGroupBoxCls(sstMisc01PrtFilCls *poPrt);
    ~sstQt01TestGroupBoxCls();

private slots:
    void selectionChangedSlot(const QItemSelection & newSelection, const QItemSelection & oldSelection);


private:
    QStackedWidget        *stackedWidget;
    QTextBrowser          *poTextWidget1;
    sstQt01TstRec1ViewCls *poTab1View;
    sstQt01TstRec2ViewCls *poTab2View;
    QTreeView             *treeView;
    QStandardItemModel    *standardModel;
    QStandardItem *rootItem;
    QStandardItem *tabItem1;
    QStandardItem *tabItem2;

};
//==============================================================================


#endif

// --------------------------------------------------------------- File End ----
