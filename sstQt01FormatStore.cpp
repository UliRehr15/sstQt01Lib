// sstQt01FormatStore.cpp    18.07.17  Re.    18.07.17  Re.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>
#include <list>

#include <QtWidgets>
#include <QColor>
#include <QPainterPath>
#include <QPoint>

#include <sstStr01Lib.h>
#include <sstStr01FixColWidth.h>
#include <sstMath01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

//=============================================================================
sstQt01FormatViewCls::sstQt01FormatViewCls()
{

}
//=============================================================================
int sstQt01FormatViewCls::CalcCoorTrn(int iKey, sstMath01Mbr2Cls WC_Mima, unsigned long ulDB_Max, double dDC_Max)
{
  //-----------------------------------------------------------------------------
  if ( iKey < 0 || iKey > 1) return -1;

  int iStat = 0;

  iStat = this->oTrn.Calc_All( iKey, WC_Mima,  ulDB_Max, dDC_Max);

  return iStat;
}
//=============================================================================
//=============================================================================
int sstQt01FormatViewCls::Transform_DC_WC (int iKey, double *dX, double *dY)
//-----------------------------------------------------------------------------
{
  sstMath01fPnt2Cls fDC_Pnt;  // 2D Device (screen) coordinates as float
  sstMath01dPnt3Cls dWC_Pnt;  // 3D World coordinates as double

  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  fDC_Pnt.x = (float) *dX;
  fDC_Pnt.y = (float) *dY;

  this->oTrn.Pnt3DC_WC2(0,&fDC_Pnt, &dWC_Pnt);

  *dX = dWC_Pnt.x;
  *dY = dWC_Pnt.y;

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstQt01FormatViewCls::Transform_WC_DC (int iKey, double *dX, double *dY)
//-----------------------------------------------------------------------------
{
  sstMath01fPnt2Cls fDC_Pnt;  // 2D Device (screen) coordinates as float
  sstMath01dPnt3Cls dWC_Pnt;  // 3D World coordinates as double

  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  dWC_Pnt.x = *dX;
  dWC_Pnt.y = *dY;

  this->oTrn.Pnt3WC_DC2(0,&dWC_Pnt,&fDC_Pnt);

  *dX = fDC_Pnt.x;
  *dY = fDC_Pnt.y;

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
