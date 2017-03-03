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
// sstQt01LibTestView.cpp    14.08.16  Re.    14.08.16  Re.

#include <QtWidgets>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "sstQt01LibTestView.h"
// #include "sstQt01PathPaintWidget.h"

int main(int argc, char *argv[])
{
  sstMisc01PrtFilCls oPrt;
  oPrt.SST_PrtAuf(0,(char*)"sstQt01LibTestView.log");

  Q_INIT_RESOURCE(tooltips);

    QApplication app(argc, argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    sstQt01PathPaintWidgetCls oPathPaintWidget(&oPrt);
    oPathPaintWidget.show();
    return app.exec();
}
