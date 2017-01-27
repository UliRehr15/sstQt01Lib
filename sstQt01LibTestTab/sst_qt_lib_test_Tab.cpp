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
// sst_qt_lib_test_Tab.cpp    16.09.15  Re.    16.09.15  Re.
//
// testframe for sst_qt Lib, special table functions

#include <QtWidgets/QApplication>
#include <QtWidgets/QTableView>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "dialog.h"
#include "sst_qt_lib_test_tab.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    Dialog dialog;
    dialog.show();

    return app.exec();

}
//! [Quoting ModelView Tutorial]
