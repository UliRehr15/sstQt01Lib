
#ifndef SSTQT01TABTEST_H
#define SSTQT01TABTEST_H

#include <QtWidgets>
#include <QDialog>
#include <QTreeView>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QTextBrowser>

#include <string>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

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

private slots:
    void selectionChangedSlot(const QItemSelection & newSelection, const QItemSelection & oldSelection);

private:
    void createMenu();
    void createHorizontalGroupBox();

    enum { NumGridRows = 3, NumButtons = 2 };

    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox;
    QTextEdit *bigEditor;
    QDialogButtonBox *buttonBox;

    QMenu *fileMenu;
    QAction *exitAction;

    QTreeView *treeView;
    QStandardItemModel *standardModel;
    QTextBrowser *poTextWidget1;
    QVBoxLayout *mainLayout;
    QStackedWidget *stackedWidget;

    sstQt01TstRec1ViewCls *poTab1View;
    sstQt01TstRec2ViewCls *poTab2View;
    sstMisc01PrtFilCls *poPrt;

};

#endif // DIALOG_H
