#include <assert.h>

#include <QtWidgets>
#include <QTreeView>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QTextBrowser>

#include <string>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstQt01Lib.h>

#include "sstQt01LibTestTab2.h"

Dialog::Dialog()
{

  this->poPrt = new sstMisc01PrtFilCls;
  this->poPrt->SST_PrtAuf(1,(char*)"sstQt01TabTest2.log");
  this->poTab1View = new sstQt01TstRec1ViewCls(this->poPrt);
  this->poTab2View = new sstQt01TstRec2ViewCls(this->poPrt);


  poTextWidget1 = new QTextBrowser;
  poTextWidget1->setPlainText(tr("TextWidget1"));

  stackedWidget = new QStackedWidget;
        stackedWidget->addWidget(poTextWidget1);
        stackedWidget->addWidget(poTab1View);
        stackedWidget->addWidget(poTab2View);

  treeView = new QTreeView(this);
  standardModel = new QStandardItemModel ;
  QStandardItem *rootNode = standardModel->invisibleRootItem();


  //defining a couple of items
  QStandardItem *rootItem = new QStandardItem("Alle Tabellen");
  QStandardItem *tabItem1 =  new QStandardItem("Test-Tabelle 1");
  QStandardItem *tabItem2 =     new QStandardItem("Test-Tabelle 2");

  //building up the hierarchy
  rootNode->    appendRow(rootItem);
  rootItem-> appendRow(tabItem1);
  rootItem-> appendRow(tabItem2);

  //register the model
  treeView->setModel(standardModel);
  treeView->expandAll();

  //selection changes shall trigger a slot
  QItemSelectionModel *selectionModel= treeView->selectionModel();
  connect(selectionModel, SIGNAL(selectionChanged (const QItemSelection &, const QItemSelection &)),
          this, SLOT(selectionChangedSlot(const QItemSelection &, const QItemSelection &)));
    createMenu();
    createHorizontalGroupBox();

    bigEditor = new QTextEdit;
    bigEditor->setPlainText(tr("This widget takes up all the remaining space "
                               "in the top-level layout."));

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    mainLayout = new QVBoxLayout;
    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(horizontalGroupBox);
    mainLayout->addWidget(bigEditor);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Basic Layouts"));
}

Dialog::~Dialog()
{
  delete this->poTab1View;
  delete this->poTab2View;
  this->poPrt->SST_PrtZu(1);
  delete this->poPrt;
}

void Dialog::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}

void Dialog::createHorizontalGroupBox()
{
    horizontalGroupBox = new QGroupBox(tr("Horizontal layout"));
    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(treeView);

    layout->addWidget(stackedWidget);

    horizontalGroupBox->setLayout(layout);
}

//QLabel *Dialog::createLabel(const QString &text)
//{
//    QLabel *label = new QLabel(text);
//    label->setFrameStyle(QFrame::Box | QFrame::Raised);
//    return label;
//}

void Dialog::selectionChangedSlot(const QItemSelection & /*newSelection*/, const QItemSelection & /*oldSelection*/)
{
    //get the text of the selected item
    const QModelIndex index = treeView->selectionModel()->currentIndex();
    QString selectedText = index.data(Qt::DisplayRole).toString();
    int selectedInt = index.row();  // get actual row of tree
    //find out the hierarchy level of the selected item
    int hierarchyLevel=1;
    QModelIndex seekRoot = index;
    while(seekRoot.parent() != QModelIndex())
    {
        seekRoot = seekRoot.parent();
        hierarchyLevel++;
    }
    QString showString = QString("%1, Level %2").arg(selectedText)
                         .arg(hierarchyLevel);
    setWindowTitle(showString);
    if (hierarchyLevel == 1)
    {
      stackedWidget->setCurrentIndex(0);
    }
    else
    {
      if (selectedInt == 0) stackedWidget->setCurrentIndex(1);
      else stackedWidget->setCurrentIndex(2);
    }
}
