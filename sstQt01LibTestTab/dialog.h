// dialog.h   12.11.14  Re.   12.11.14  Re.
//
// Datastructures and Prototypes for system "dialog"
//

#ifndef SST_DIALOG_H
#define SST_DIALOG_H

#include <QDialog>
#include <QtWidgets>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "sst_qt_lib_test_tab.h"

QT_BEGIN_NAMESPACE
class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog();
    ~Dialog();

private:
    void createMenu();
    void createHorizontalGroupBox1();
    void createHorizontalGroupBox2();

    enum { NumGridRows = 3, NumButtons = 4 };

    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox1;
    QGroupBox *horizontalGroupBox2;

    QMenu *fileMenu;
    QAction *exitAction;

    TstRec1ModelCls  *pTstRec1Model;
    // TstRec1ViewCls   *pTstRec1View;
    sstQt01TabViewCls   *pTstRec1View;

    TstRec2ModelCls  *pTstRec2Model;
    // TstRec2ViewCls   *pTstRec2View;
    sstQt01TabViewCls   *pTstRec2View;

};

#endif // DIALOG_H
