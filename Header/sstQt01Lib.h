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

// Structures and Classes ------------------------------------------------------
//==============================================================================
/**
* @brief General view features for format data like dxf and other.
*
* coordinate transformation class
*
* Changed: 24.07.17  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 24.07.17
*/
// ----------------------------------------------------------------------------
class sstQt01FormatViewCls
{
  public:   // Public functions
     sstQt01FormatViewCls();   // Constructor
    // ~X();   // Destructor
//==============================================================================
/**
* @brief // Calculate Coordinate Transformation Matrice <BR>
* iStat = iStat = oPathStore.CalcCoorTrn( iKey, WC_Mima, ulDB_Max, dDC_Max);
*
* @param iKey     [in] For the moment 0
* @param WC_Mima  [in] Mbr of data
* @param ulDB_Max [in] Max of intern Database Coordinates
* @param dDC_Max  [in] Max of sceen device
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*/
// ----------------------------------------------------------------------------
    int CalcCoorTrn(int iKey, sstMath01Mbr2Cls WC_Mima, unsigned long ulDB_Max, double dDC_Max);
    //==============================================================================
    /**
    * @brief // transform coordinates from device to world coordinate system  <BR>
    * iStat = oPathStore.Transform_DC_WC(iKey, &dX, &dY);
    *
    * @param iKey  [in] For the moment 0
    * @param dX    [in out] X Value
    * @param dY    [in out] Y Value
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Transform_DC_WC (int iKey, double *dX, double *dY);
    //==============================================================================
    /**
    * @brief // transform coordinates from would to device coordinate system  <BR>
    * iStat = oPathStore.Transform_WC_DC(iKey, &dX, &dY);
    *
    * @param iKey  [in] For the moment 0
    * @param dX    [in out] HatchEdge object
    * @param dY    [in out] HatchEdge object
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Transform_WC_DC (int iKey, double *dX, double *dY);
    //==============================================================================
protected: // Protected functions
    sstMath01CoorTrnCls oTrn;  /**< Coordinate Transformation matrice class */
private:  // Private functions
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
    * @param Pen [in] QPen
    */
    // ----------------------------------------------------------------------------
    void setPen(const QPen &Pen);
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
    * oColor = PathItem.getPen();
    *
    * @return QPen
    */
    // ----------------------------------------------------------------------------
    QPen getPen() const;
    //==============================================================================
    /**
    * @brief // Get ToolTip string <BR>
    * oToolTip = oPathItem.getToolTip();
    *
    * @return QString
    */
    // ----------------------------------------------------------------------------
    QString getToolTip() const;
    //==============================================================================
    /**
    * @brief // Set Path, Tooltip, Position and Color to ShapeItem <BR>
    * iStat = oPathItem.createShapeItem( path, tooltip, pos, color);
    *
    * @param path    [in] QPainterPath
    * @param toolTip [in] Tooltip string
    * @param pos     [in] Position
    * @param color   [in] Color
    */
    // ----------------------------------------------------------------------------
    void createShapeItem(const QPainterPath &path,
                         const QString &toolTip, const QPoint &pos,
                         const QColor &color);
    //==============================================================================

private:
    QPainterPath myPath;    /**< Dummy */
    QPoint myPosition;      /**< Dummy */
    QColor myColor;         /**< Dummy */
    QString myToolTip;      /**< Dummy */
    QPen myPen;             /**< Dummy */
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
* @brief Path Element record plus Attributes as csv string (Version 2) <BR>
*
* for example: <BR>
* 0;215;193;111;190;0 <BR>
* element type = 0, Coordinates X,Y = 215, 193 <BR>
* Color 111,190,0 RGB <BR>
* Pen Width 1 <BR>
* Pen Style 1 <BR>
*
* Changed: 06.06.17  Re.
*
* @ingroup sstQt01Lib
*
* @author Re.
*
* @date 06.06.17
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
     * @brief // set all data to path element object <BR>
     * iStat = oPathElement.setAll( iType, iXX, iYY, oColor);
     *
     * @param iType    [in]  int type
     * @param iXX      [in]  int coordinate x
     * @param iYY      [in]  int coordinate y
     * @param oColor   [in]  color
     * @param oPen     [in]  pen
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     void setAll(int iType,int iXX, int iYY, QColor oColor, QPen oPen);
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
     * @brief // Get Value <BR>
     *  oQCol = oPathElement.getValue()
     *
     * @return Value
     */
     // ----------------------------------------------------------------------------
     int getIPenWidth() const;
     //==============================================================================
     /**
     * @brief // Set Value <BR>
     * oPathElement.setValue(value);
     *
     * @param value [in] Value
     */
     // ----------------------------------------------------------------------------
     void setIPenWidth(int value);
     //==============================================================================
     /**
     * @brief // Get Value <BR>
     *  oQCol = oPathElement.getValue()
     *
     * @return Value
     */
     // ----------------------------------------------------------------------------
     int getIPenStyle() const;
     //==============================================================================
     /**
     * @brief // Set Value <BR>
     * oPathElement.setValue(value);
     *
     * @param value [in] Value
     */
     // ----------------------------------------------------------------------------
     void setIPenStyle(int value);
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
     * @brief // Get QPen <BR>
     *  oQPen = oPathItem.getQPen();
     *
     * @return QColor
     */
     // ----------------------------------------------------------------------------
     QPen getQPen();
     //==============================================================================
     /**
     * @brief // Set QPen <BR>
     * oPathItem.setQPen(value);
     *
     * @param oQPen [in] QPen
     */
     // ----------------------------------------------------------------------------
     void setQPen(QPen oQPen);
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
     * @brief // Get Pen Style <BR>
     *  iPenStyle = oPathItem.getIPenStyle();
     *
     * @return int iPenStyle
     */
     // ----------------------------------------------------------------------------
     int getIPenStyle() const;
     //==============================================================================
     /**
     * @brief // Set Pen Style <BR>
     * oPathItem.setIPenStyle(iValue);
     *
     * @param value [in] iPenStyle
     */
     // ----------------------------------------------------------------------------
     void setIPenStyle(int value);
     //==============================================================================
     /**
     * @brief // Get Pen Width <BR>
     *  iPenWidth = oPathItem.getIPenWidth();
     *
     * @return int iPenWidth
     */
     // ----------------------------------------------------------------------------
     int getIPenWidth() const;
     //==============================================================================
     /**
     * @brief // Set Pen Widt <BR>
     * oPathItem.setIPenWidth(iValue);
     *
     * @param value [in] iPenWidth
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
     int iPenStyle;        /**< Pen Style */
     int iPenWidth;        /**< Pen Width */
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
     * @param oPen   [in] Pen of Path
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int AppendPath(int iKey,  QPainterPath oPath, QColor oColor, QPen oPen);
     //==============================================================================
     /**
     * @brief // read next QPainterPath object from sst table object.  <BR>
     * iStat = oPathStorage.LoadAllPathFromFile (iKey, oFilNam);
     *
     * @param iKey   [in] For the moment 0
     * @param oPath  [out] QPainterPath object
     * @param oColor [out] Color of Path
     * @param oPen   [out] Pen of Path
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadNextPath(int iKey,  QPainterPath *oPath, QColor *oColor, QPen *oPen);
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
     * @brief // Get QPen for index path <BR>
     * iStat = oPathStorage.getQPen(index);
     *
     * @param index [in] index of path
     *
     * @return Color
     */
     // ----------------------------------------------------------------------------
     QPen getQPen(dREC04RECNUMTYP index);
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
// ----------------------------------------------------------------------------
  private:  // Private functions
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * iStat = oPathStorage.Func_1(iKey);
     *
     * @param path [in out] QPainterPath
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
     * @return QColor
     */
     // ----------------------------------------------------------------------------
     QColor initialItemColor();
     //==============================================================================
     /**
     * @brief // Load Version 2 Data from PainterPath CSV File <BR>
     * iStat = oPathStorage.LoadVersion2File(iKey,poPainterCsvFile);
     *
     * @param iKey    [in] For the moment 0
     * @param oFilNam [in] Name of PainterPath FileNam
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     * @retval   = -2: Could file not open
     * @retval   = -3: Version Error
     * @retval   = -4: Data Interpret Error
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int LoadVersion2File(int iKey,  std::string oFilNam);
     //==============================================================================
     /**
     * @brief // Load Version 1 Data from PainterPath CSV File <BR>
     * iStat = oPathStorage.LoadVersion1File(iKey,poPainterCsvFile);
     *
     * @param iKey    [in] For the moment 0
     * @param oFilNam [in] Name of PainterPath FileNam
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     * @retval   = -2: Could file not open
     * @retval   = -3: Version Error
     * @retval   = -4: Data Interpret Error
     * @retval   <  0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int LoadVersion1File(int iKey,  std::string oFilNam);
     //==============================================================================

     sstRec04Cls *poShapeItemRecTable;   /**< painter path element record table */
     sstRec04Cls *poShapeItemMainTable;  /**< painter path main table */
     dREC04RECNUMTYP dActualReadPos;     /**< actual read position in table */
     int iHeight;  /**< Bounding Box for creating new path objects */
     int iWidth;   /**< Bounding Box for creating new path objects */
};
//==============================================================================
/**
* @brief Definition Class TstRec2ViewCls
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
  sstQt01TabViewCls();    // Constructor
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

private:  // Private functions
  QAction *cell_InsAction;   /**< Insert Table Rows Action */
  QAction *cell_DelAction;   /**< Delete Table Rows Action */
  // sstQt01PathTabMdlCls *poTabMdl;  /**< Dummy */
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
    * @brief // sst paint event <BR>
    */
    // ----------------------------------------------------------------------------
    void sstPaintEvent();
    //==============================================================================
private slots:
    //==============================================================================
    /**
    * @brief // Private Slot createNewCircle <BR>
    * iStat = oPathWidget.createNewCircle();
    */
    // ----------------------------------------------------------------------------
    void createNewCircle();
    //==============================================================================
    /**
    * @brief // Private Slot createNewSquare <BR>
    * iStat = oPathWidget.createNewSquare();
    */
    // ----------------------------------------------------------------------------
    void createNewSquare();
    //==============================================================================
    /**
    * @brief // Private Slot createNewTriangle <BR>
    * iStat = oPathWidget.createNewTriangle();
    */
    // ----------------------------------------------------------------------------
    void createNewTriangle();
    //==============================================================================
    /**
    * @brief // Private Slot createNewLine <BR>
    * iStat = oPathWidget.createNewLine();
    */
    // ----------------------------------------------------------------------------
    void createNewLine();

private:
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oPathWidget.Func_1(iKey);
    *
    * @param button [in] For the moment 0
    * @param x [in] For the moment 0
    * @param y [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int updateButtonGeometry(QToolButton *button, int x, int y);
    //==============================================================================
    /**
    * @brief // createShapeItem <BR>
    * iStat = oPathWidget.createShapeItem(path, tooltip, pos, color, pen);
    *
    * @param path    [in] QPainterPath object
    * @param toolTip [in] tooltip string
    * @param pos     [in] position
    * @param color   [in] color
    * @param pen     [in] pen
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    void createShapeItem(const QPainterPath &path, const QString &toolTip,
                         const QPoint &pos, const QColor &color, const QPen &pen);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oPathWidget.Func_1(iKey);
    *
    * @param pos [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int itemAt(const QPoint &pos);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oPathWidget.Func_1(iKey);
    *
    * @param pos [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    void moveItemTo(const QPoint &pos);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oPathWidget.Func_1(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ItemsLoadFromFile3 (int iKey);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oPathWidget.Func_1(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ItemsCreate (int iKey);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oPathWidget.Func_1(iKey);
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    QSize minimumSizeHint() const;
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oPathWidget.Func_1(iKey);
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    QSize sizeHint() const;
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oPathWidget.Func_1(iKey);
    *
    * @param path [in] For the moment 0
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
    * iStat = oPathWidget.Func_1(iKey);
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    QPoint randomItemPosition();
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oPathWidget.Func_1(iKey);
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    QColor initialItemColor();
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oPathWidget.Func_1(iKey);
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    QColor randomItemColor();
    //==============================================================================
    /**
    * @brief // initialItemPen <BR>
    * iStat = oPathWidget.initialItemPen();
    *
    * @return QPath
    */
    // ----------------------------------------------------------------------------
    QPen initialItemPen();
    //==============================================================================
    /**
    * @brief // randomItemPen <BR>
    * iStat = oPathWidget.randomItemPen();
    *
    * @return QPath
    */
    // ----------------------------------------------------------------------------
    QPen randomItemPen();
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oPathWidget.Func_1(iKey);
    *
    * @param toolTip [in] For the moment 0
    * @param icon [in] For the moment 0
    * @param member [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    QToolButton *createToolButton(const QString &toolTip, const QIcon &icon,
                                  const char *member);
    //==============================================================================

    // QList<sstQt01ShapeItem> shapeItems;
    QPainterPath circlePath;    /**< Dummy */
    QPainterPath squarePath;    /**< Dummy */
    QPainterPath trianglePath;  /**< Dummy */
    QPainterPath linePath;      /**< Dummy */

    QPoint previousPosition;    /**< Dummy */
    // sstQt01ShapeItem *itemInMotion;
    int iItemInMotionIndex;     /**< Dummy */
    sstQt01ShapeItem oActualItem; /**< Dummy */
    int iActualItemIndex;       /**< Dummy */

    QToolButton *newCircleButton;   /**< Dummy */
    QToolButton *newSquareButton;   /**< Dummy */
    QToolButton *newTriangleButton; /**< Dummy */
    QToolButton *newLineButton;     /**< Dummy */
    sstQt01PathStorageCls *oPathStorage; /**< Dummy */
    sstMisc01PrtFilCls *poPrt;      /**< Dummy */
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
    Shape shape;       /**< Dummy */
    QPen pen;          /**< Dummy */
    QBrush brush;      /**< Dummy */
    bool antialiased;  /**< Dummy */
    bool transformed;  /**< Dummy */
    QPixmap pixmap;    /**< Dummy */
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
class sstQt01PathTabViewCls : public sstQt01TabViewCls
{
  public:   // Public functions
  //==============================================================================
  /**
  * @brief // Shortstory <BR>
  * iStat = oTestBase.Func_1(iKey);
  *
  * @param poPrt         [in] Pointer to Protocol object
  * @param poPathStorage [in] Pointer to PathStorage object
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
     sstQt01PathTabViewCls( sstMisc01PrtFilCls    *poPrt,
                            sstQt01PathStorageCls *poPathStorage);  // Constructor
     //==============================================================================
     ~sstQt01PathTabViewCls();  // Destructor
     //==============================================================================
private:  // Private functions
     sstQt01PathTabMdlCls  *pTstRec1Model; /**< Dummy */
};
//==============================================================================

#endif

// --------------------------------------------------------------- File End ----

