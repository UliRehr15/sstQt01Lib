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
* @brief Path Element record plus Color as csv string <BR>
*
* for example: <BR>
* 0;215;193;111;190;0 <BR>
* element type = 0, Coordinates X,Y = 215, 193 <BR>
* Color 111,190,0 RGB <BR>
*
* Changed: 04.09.16  Re.
*
* @ingroup sstQt01LibInt
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
* @brief Path item record plus Color and tooltip string <BR>
*
* Changed: 04.09.16  Re.
*
* @ingroup sstQt01LibInt
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
     * iStat = oPathItem.ReadFromCsv( iKey, oCsvStr, *oErrStr);
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
     * iStat = oPathItem.WriteToCsv( iKey, &oCsvStr, &oErrStr);
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
     * oTitleRowStr = oPathItem.GetCsvFileTitle();
     *
     * @return Title row string
     */
     // ----------------------------------------------------------------------------
     std::string GetCsvFileTitle();
     //==============================================================================
     /**
     * @brief // set all data to path element object <BR>
     * iStat = oPathItem.setAll( iType, iXX, iYY, oColor);
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
     * oSection = oPathItem.GetIType()
     *
     * @return Type Int
     */
     // ----------------------------------------------------------------------------
     int getIType() const;
     //==============================================================================
     /**
     * @brief // Set Element Type <BR>
     * oPathItem.SetIType ( value);
     *
     * @param value [in] Element type 0,1,2 or 3
     */
     // ----------------------------------------------------------------------------
     void setIType(int value);
     //==============================================================================
     /**
     * @brief // Get X Coordinate <BR>
     *  iXX = oPathItem.GetIXX()
     *
     * @return X Coordinate
     */
     // ----------------------------------------------------------------------------
     int getIXX() const;
     //==============================================================================
     /**
     * @brief // Set X coordinate <BR>
     * oPathItem.SetIXX(oSection);
     *
     * @param value [in] coordinate X
     */
     // ----------------------------------------------------------------------------
     void setIXX(int value);
     //==============================================================================
     /**
     * @brief // Get Y Coordinate <BR>
     *  iYY = oPathItem.GetIYY()
     *
     * @return Y Coordinate
     */
     // ----------------------------------------------------------------------------
     int getIYY() const;
     //==============================================================================
     /**
     * @brief // Set Y Coordnate <BR>
     * oPathItem.SetIYY(value);
     *
     * @param value [in] Coordinate Y
     */
     // ----------------------------------------------------------------------------
     void setIYY(int value);
     //==============================================================================
     /**
     * @brief // Get Color Red <BR>
     *  iColR = oPathItem.GetSection()
     *
     * @return int color red
     */
     // ----------------------------------------------------------------------------
     int getIColR() const;
     //==============================================================================
     /**
     * @brief // Set Color Red <BR>
     * oPathItem.SetColR(value);
     *
     * @param value [in] color red
     */
     // ----------------------------------------------------------------------------
     void setIColR(int value);
     //==============================================================================
     /**
     * @brief // Get Color green <BR>
     *  iColG = oPathItem.GetIColG()
     *
     * @return int color green
     */
     // ----------------------------------------------------------------------------
     int getIColG() const;
     //==============================================================================
     /**
     * @brief // Set color green <BR>
     * oPathItem.setIColG(value);
     *
     * @param value [in] color green
     */
     // ----------------------------------------------------------------------------
     void setIColG(int value);
     //==============================================================================
     /**
     * @brief // Get Color Blue <BR>
     *  iColB = oPathItem.getIColB()
     *
     * @return int color blue
     */
     // ----------------------------------------------------------------------------
     int getIColB() const;
     //==============================================================================
     /**
     * @brief // Set color blue <BR>
     * oPathItem.setIColB(value);
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

private:
     int iXX;        /**< Position X */
     int iYY;        /**< Position Y */
     int iColR;        /**< Color Red */
     int iColG;        /**< Color Green */
     int iColB;        /**< Color Blue */
     char cTooltip[30];  /**< Tooltip char string */
     dREC04RECNUMTYP dStartElementRecNo;  /**< Start of Path in Element table */
     dREC04RECNUMTYP dNumElements;        /**< Number of elements in path */
};



#endif

// --------------------------------------------------------------- File End ----
