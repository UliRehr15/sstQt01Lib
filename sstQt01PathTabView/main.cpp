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
// main.cpp   18.08.17  Re.   23.02.17  Re.
//
// This testtool combines map and table with refreshing in both direction
// when editing qt painter path data.


#include <string>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // Q_INIT_RESOURCE(basicdrawing);


  QApplication app(argc, argv);
    Window window;
    window.show();
    return app.exec();
}
