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

This Library is created with QT 5.9.5, QtCreator 4.5.2 and gcc 7.3.0.

Structure of coding projects should be:

.. [libs]
   [Doxygen_Output] <BR>
   [sst_str01_lib] (Lib for R/W of csv data) <BR>
   [sst_misc01_lib] (Lib of Log File handling) <BR>
   [sst_rec04_lib] (Lib for storing Table Data) <BR>
   [sstQt01Lib] <BR>

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
20.06.2017: Version 1.15: Extended Csv PainterPath Format with PenWidth, PenStyle.(Vers.2) <BR>
                          Doxygen Documentation for private elements too. <BR>
22.06.2017: Version 1.16: Path Table View/Model corrected. <BR>
24.06.2017: Version 1.17: Editing/Viewing PenStyle and PenWidth. <BR>
11.08.2017: Version 1.18: Linking sstMath01Lib. New Class sstQt01FormatViewCls. <BR>
11.08.2017: Version 1.19: More Transformation functions for Viewing. <BR>
18.08.2017: Version 1.20: Tool PathTabView: Now refreshing in both directions while editing path data. <BR>
01.09.2017: Version 1.21: Patch Refreshing/Resizing PathTable while inserting items in PathMap. <BR>
08.09.2017: Version 1.22: Preparing BeginRemoveRows/EndRemoveRows in PathTable. <BR>
20.09.2017: Version 1.23: Delete QPainterPath object from table, repaint map. <BR>
01.10.2017: Version 1.24: Insert/Delete Row function in QPainterPath object. <BR>
26.10.2017: Version 1.25: Restore Version 1.15. Lost with Project Copy. <BR>
24.11.2017: Version 1.26: New Buttons -Add polyline, arc, text-. <BR>
25.12.2017: Version 1.27: Extended Csv PainterPath Format with Object Type Flag. (Vers.3) <BR>
12.01.2018: Version 1.28: Improve handling with format versions. <BR>
19.01.2018: Version 1.29: Fix problem with write/read object type flag . <BR>
                          Fix problem with editing tab attributes. <BR>
26.01.2018: Version 1.30: Fix problem with drawing element arc. <BR>
19.02.2018: Version 1.31: Fix problem with showing tooltip string. <BR>
27.02.2018: Version 1.32: sstPathItem get new property -Extern Identifier-.  <BR>
02.03.2018: Version 1.33: Emit Signal -Extern Identifier- after release move painterpath. <BR>
15.03.2018: Version 1.34: Rename dID to dExternId, for example dxf. <BR>
23.03.2018: Version 1.35: Class sstQt01TabMdlCls is now public for Dxf Table Classes. <BR>
06.07.2018: Version 1.36: New Storage for symbol handling. Fixed problem with showing tooltips. <BR>
                          Fixed problem with more objects pathes. <BR>
27.07.2018: Version 1.37: New ShapeItem storage with QList for showing ShapeItems in MapView. <BR>
                          First Works, not in Use. <BR>
10.08.2018: Version 1.38: Lot of corrections. QListViewStore for ShapeItems use in LibTestView. <BR>
30.08.2018: Version 1.39: First works connect PainterPath Tab store (TabView) and QList Store (MapView). <BR>
31.08.2018: Version 1.40: small extensions. <BR>
14.09.2018: Version 1.41: C++ 11 override warnings fixed. <BR>
                          Inserted functions for update Tab Store from View Store and vice versa. <BR>
23.09.2018: Version 1.42: Fix problem with writing Tooltip string to ShapeItem. <BR>
18.10.2018: Version 1.43: Create TestGroupBoxWidget for editing more Tables parallel. <BR>
29.10.2018: Version 1.44: New function updatePosition for ShapeItem Class. <BR>
30.10.2018: Version 1.45: Documentation added to repository. <BR>
01.11.2018: Version 1.46: Better "in cell" editing for all tables. <BR>
24.11.2018: Version 1.47: New Class MapSignal for update. <BR>
14.12.2018: Version 1.48: ShapeItems knows its position in display list / ShapeItem Storage.<BR>
                          Message Update map from Tab with MapSignal. <BR>
21.12.2018: Version 1.49: Fixed problems with writing into closed protocol file. <BR>
27.01.2020: Version 1.50: ShapeItem: New feature InitPosition before Moving of Object.  <BR>
20.12.2020: Version 1.51: Some Doxygen warnings fixed.  <BR>

