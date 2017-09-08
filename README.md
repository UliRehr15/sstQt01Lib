# sstQt01Lib
sst Qt classes and functions

Read/Write Csv Data to Qt Spreadsheet-Table and edit this data.
   -Add Rows and delete Rows.
Storing QPainterPath data into csv file.
Widget for Editing QPainterPath Objects.

Tool sstQt01LibTestTab for test editing general csv tables.
Tool sstQt01LibTestTab2 for test editing more tables in one view widget.
Tool sstQt01LibTestView for showing/editing QPainterPath data from csv file in map view.
Tool sstQt01LibTabPath for editing QPainterPath data in table view from csv file.
Tool sstQt01PathTabView for combined Painter Path data editing in Table and Map.

Licence model:
* This is free software; you can redistribute and/or modify it under
* the terms of the GNU Lesser General Public Licence as published
* by the Free Software Foundation.
* See the COPYING file for more information.

Compile with QT 5.5 and QTCreator 3.5.1

Structure of coding projects should be:

.. [libs]
   [Doxygen_Output] <BR>
   [sst_str01_lib] <BR>
   [sst_misc01_lib] <BR>
   [sst_rec04_lib] <BR>

12.08.2016  Version 1.0: Checkin of test table project. <BR>
05.09.2016  Version 1.1: Classes for storing QPainterPath objects. <BR>
06.09.2016  Version 1.2: New Tool for testing path storing classes. <BR>
17.01.2017  Version 1.3: Adding title Row to PainterPath Csv file. <BR>
24.01.2017  Version 1.4: new tool for editing painter path table. <BR>
27.01.2017  Version 1.5: Move some classes from tool to lib. <BR>
10.02.2017  Version 1.6: Extend class PathStorage with several functions. <BR>
                         Tool TestView: Replace Path_QList with PathStorage. <BR>
11.02.2017: Version 1.7: Path Storage Record Classes now Lib intern. <BR>
                         Path Table Model Class now Lib. <BR>
                         Path Table Dialog Class now Lib. <BR>
23.02.2017: Version 1.8: New Test-Tool Combined Painter Path Table and Draw View. <BR>
03.03.2017: Version 1.9: PathPaintWidget has now Protocol-File, Tooltip problem fixed. <BR>
27.04.2017: Version 1.10: Small corrections in app TestTab. <BR>
19.05.2017: Version 1.11: Creation of PainterPath storage now outside of Map widget. <BR>
                          PainterPathMapWidget: New Element LINE. <BR>
22.05.2017: Version 1.12: Creation of PainterPath storage now outside of Tab widget. <BR>
28.05.2017: Version 1.13: Signals/Slots to update PathMapWidget after changing PathTabWidget.<BR>
01.06.2017: Version 1.14: New function CreateDefaultItems.  <BR>
20.06.2017: Version 1.15: Extended Csv PainterPath Format with PenWidth, PenStyle. <BR>
                          Doxygen Documentation for private elements too. <BR>
22.06.2017: Version 1.16: Path Table View/Model corrected. <BR>
24.06.2017: Version 1.17: Editing/Viewing PenStyle and PenWidth. <BR>
11.08.2017: Version 1.18: Linking sstMath01Lib. New Class sstQt01FormatViewCls. <BR>
11.08.2017: Version 1.19: More Transformation functions for Viewing. <BR>
18.08.2017: Version 1.20: Tool PathTabView: Now refreshing in both directions while editing path data. <BR>
01.09.2017: Version 1.21: Patch Refreshing/Resizing PathTable while inserting items in PathMap. <BR>
08.09.2017: Version 1.22: Preparing BeginRemoveRows/EndRemoveRows in PathTable. <BR>
