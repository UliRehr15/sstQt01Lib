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

#include <QPen>
#include <QTableView>

#include <sstStr01Lib.h>
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
    * iStat = oShapeItem.createShapeItem( path, toolTip, pos, color);
    *
    * @param path    [in] path
    * @param toolTip [in] tooltip
    * @param pos     [in] pos
    * @param color   [in] color
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    void createShapeItem(const QPainterPath &path,
                         const QString &toolTip, const QPoint &pos,
                         const QColor &color);
    //==============================================================================

private:
    QPainterPath myPath;
    QPoint  myPosition;
    QColor  myColor;
    QPen    myPen;  // Width and Style
    QString myToolTip;
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
class sstQt01PathElementCsvCls
{
  public:   // Public functions
     sstQt01PathElementCsvCls();  // Constructor
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
     int iPenWidth;    /**< Pen Width */
     int iPenStyle;    /**< Pen Style */

};
//==============================================================================
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
     * iStat = oPathStorage.AppendPath (iKey, oPath, oColor);
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

  private:  // Private functions
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * iStat = oPathStorage.Func_1(iKey);
     *
     * @param iKey [in] For the moment 0
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
     * @brief // Shortstory <BR>
     * iStat = oPathStorage.Func_1(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     QColor initialItemColor();
     //==============================================================================


     sstRec04Cls *poShapeItemRecTable;   /**< painter path element record table */
     sstRec04Cls *poShapeItemMainTable;  /**< painter path main table */
     dREC04RECNUMTYP dActualReadPos;     /**< actual read position in table */
     const int height = 300;
     const int width = 500;
     sstMisc01PrtFilCls *poPrt;
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
    void sstSlotChangeTab();
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
    void sstSgnlTabChanged();
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
* @brief Definition Class sstQt01PathTabViewCls
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
  void sstSlotUpdateTab();
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
                            sstQt01PathStorageCls *poPathStorage);
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
    void sstPaintEvent();
    //==============================================================================
private slots:
    void createNewCircle();
    void createNewSquare();
    void createNewTriangle();
    void createNewLine();
signals:
    //==============================================================================
    /**
    * @brief // signal: sst paint event: map content is changed  <BR>
    */
    // ----------------------------------------------------------------------------
    void PathMoveEvent();
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
    void createShapeItem(const QPainterPath &path, const QString &toolTip,
                         const QPoint &pos, const QColor &color, const QPen &oPen);
    int itemAt(const QPoint &pos);
    void moveItemTo(const QPoint &pos);
    int ItemsLoadFromFile3 (int iKey);
    int ItemsCreate (int iKey);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;


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

    QPoint previousPosition;
    // sstQt01ShapeItem *itemInMotion;
    int iItemInMotionIndex;
    sstQt01ShapeItem oActualItem;
    int iActualItemIndex;

    QToolButton *newCircleButton;
    QToolButton *newSquareButton;
    QToolButton *newTriangleButton;
    QToolButton *newLineButton;
    sstQt01PathStorageCls *oPathStorage;
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

#endif

// --------------------------------------------------------------- File End ----

