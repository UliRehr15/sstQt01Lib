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
 * @defgroup sstQt01Lib
 * sst Qt01 library
 */

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
// ----------------------------------------------------------------------------
  private:  // Private functions
     sstRec04Cls *poShapeItemRecTable;  /**< painter path element table */
     dREC04RECNUMTYP dActualReadPos;   /**< actual read position in table */
};
//==============================================================================

//-----------------------------------------------------------------------------


#endif

// --------------------------------------------------------------- File End ----
