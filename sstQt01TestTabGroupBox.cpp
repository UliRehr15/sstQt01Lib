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
// sstQt01TestTabGroupBox.cpp    20.12.18  Re.   11.10.18  Re.
//
// Tree View Widget for editing group of sst tables, here TestRec1 and TestRec2.

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

//=============================================================================
sstQt01TestGroupBoxCls::sstQt01TestGroupBoxCls(sstMisc01PrtFilCls *poPrt)
{
  this->setTitle("Test-Tabellen");

  poTab1View = new sstQt01TstRec1ViewCls( poPrt);
  poTab2View = new sstQt01TstRec2ViewCls( poPrt);

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
  rootItem = new QStandardItem("Alle Tabellen");
  tabItem1 = new QStandardItem("Test-Tabelle 1");
  tabItem2 = new QStandardItem("Test-Tabelle 2");

  //building up the hierarchy
  rootNode->appendRow(rootItem);
  rootItem->appendRow(tabItem1);
  rootItem->appendRow(tabItem2);

  //register the model
  treeView->setModel(standardModel);
  treeView->expandAll();

  //selection changes shall trigger a slot
  QItemSelectionModel *selectionModel= treeView->selectionModel();
  connect(selectionModel, SIGNAL(selectionChanged (const QItemSelection &, const QItemSelection &)),
          this, SLOT(selectionChangedSlot(const QItemSelection &, const QItemSelection &)));

  // horizontalGroupBox = new QGroupBox(tr("Horizontal layout"));
  QHBoxLayout *layout = new QHBoxLayout;

  layout->addWidget(treeView);

  layout->addWidget(stackedWidget);

  this->setLayout(layout);

}
//=============================================================================
sstQt01TestGroupBoxCls::~sstQt01TestGroupBoxCls()
{
  delete this->tabItem2;
  delete this->tabItem1;
  delete this->rootItem;
  delete this->standardModel;
  delete this->treeView;
  delete this->stackedWidget; // delete view 1+2 too
}
//=============================================================================
void sstQt01TestGroupBoxCls::selectionChangedSlot(const QItemSelection & /*newSelection*/, const QItemSelection & /*oldSelection*/)
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
//=============================================================================

