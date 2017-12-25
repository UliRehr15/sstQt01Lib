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
// sstQt01ShapeType.cpp    25.12.17  Re.    25.12.17  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

//=============================================================================
sstQt01ShapeTypeCls::sstQt01ShapeTypeCls()
{

}
//=============================================================================
int sstQt01ShapeTypeCls::Str2Enm (int                   iKey,
                                 std::string           oTypeStr,
                                 sstQt01ShapeType_enum *eLocType)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (oTypeStr.length() <= 10) return -2;

//    eSstQt01PathArea,      //!< Area        */
//    eSstQt01PathCircle,    //!< Circle      */
//    eSstQt01PathLine,      //!< Line        */
//    eSstQt01PathPLine,     //!< Polyline    */
//    eSstQt01PathText,      //!< Text        */
//    eSstQt01PathObject,    //!< Object      */
//    eSstQt01PathArc,       //!< Arc         */

  if(strncmp(oTypeStr.c_str(),"[PathTypeArea]",12) == 0)
  {
    *eLocType = eSstQt01PathArea;
  }
  else if(strncmp(oTypeStr.c_str(),"[PathTypeCircle]",14) == 0)
  {
    *eLocType = eSstQt01PathCircle;
  }
  else if(strncmp(oTypeStr.c_str(),"[PathTypeLine]",12) == 0)
  {
    *eLocType = eSstQt01PathLine;
  }
  else if(strncmp(oTypeStr.c_str(),"[PathTypePolyline]",16) == 0)
  {
    *eLocType = eSstQt01PathPLine;
  }
  else if(strncmp(oTypeStr.c_str(),"[PathTypeText]",12) == 0)
  {
    *eLocType = eSstQt01PathText;
  }
  else if(strncmp(oTypeStr.c_str(),"[PathTypeObject]",14) == 0)
  {
    *eLocType = eSstQt01PathObject;
  }
  else if(strncmp(oTypeStr.c_str(),"[PathTypeArc]",11) == 0)
  {
    *eLocType = eSstQt01PathArc;
  }
  else
  {
    *eLocType = eSstQt01PathUnknown;
    iStat = -1;
  }
  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstQt01ShapeTypeCls::Enm2Str (int                    iKey,
                                 sstQt01ShapeType_enum   eCppType,
                                 std::string           *oTypeStr)
//-----------------------------------------------------------------------------
{
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

//  { eSstQt01PathArea,      //!< Area        */
//    eSstQt01PathCircle,    //!< Circle      */
//    eSstQt01PathLine,      //!< Line        */
//    eSstQt01PathPLine,     //!< Polyline    */
//    eSstQt01PathText,      //!< Text        */
//    eSstQt01PathObject,    //!< Object      */
//    eSstQt01PathArc,       //!< Arc         */
//    eSstQt01PathUnknown,   //!< Path Type Unknown     */
//    eSstQt01PathError,     //!< Path Type Error       */

  switch (eCppType)
  {
  case eSstQt01PathArea:     *oTypeStr = "[PathTypeArea]";break;
  case eSstQt01PathCircle:   *oTypeStr = "[PathTypeCircle]";break;
  case eSstQt01PathLine:     *oTypeStr = "[PathTypeLine]";break;
  case eSstQt01PathPLine:    *oTypeStr = "[PathTypePolyline]";break;
  case eSstQt01PathText:     *oTypeStr = "[PathTypeText]";break;
  case eSstQt01PathObject:   *oTypeStr = "[PathTypeObject]";break;
  case eSstQt01PathArc:      *oTypeStr = "[PathTypeArc]";break;
  case eSstQt01PathUnknown:
  case eSstQt01PathError:
  default: *oTypeStr = "";break;
  }

  return iStat;
}
//=============================================================================
