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
// sstQt01LibTabPath.cpp    17.01.17 Re.    17.01.17  Re.
//
// testframe for editing PainterPath Csv data in sst qt table widget.

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

#include "sstQt01LibTabPath.h"

//=============================================================================
int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    sstQt01PathTabDialogCls dialog;
    dialog.show();

    return app.exec();

}
//=============================================================================
