TEMPLATE	= lib
CONFIG		+= warn_on
CONFIG    += qt
CONFIG    += c++11


# CONFIG    -= debug    # RELEASE is active
CONFIG    -= release  # DEBUG is active

CONFIG    += staticlib

QT += widgets

INCLUDEPATH += ../sst_rec04_lib/Header
INCLUDEPATH += ../sst_misc01_lib/Header
INCLUDEPATH += ../sstMath01Lib/Header
INCLUDEPATH += ../sst_str01_lib/Header
INCLUDEPATH += ./Header

HEADERS		+= ./Header/sstQt01Lib.h
HEADERS		+= sstQt01LibInt.h

SOURCES		+= sstQt01Tab.cpp \
    sstQt01ExPath.cpp \
    sstQt01MapPath.cpp \
    sstQt01ShapeItem2.cpp \
    sstQt01TabView.cpp \
    sstQt01ShapeItem.cpp \
    sstQt01PathTabModel.cpp \
    sstQt01PathPaintWidget.cpp \
    sstQt01TestPaintWidget.cpp \
    sstQt01PathTabView.cpp \
    sstQt01View.cpp \
    sstQt01_tstrec1_TabMdl.cpp \
    sstQt01_tstrec1_TabView.cpp \
    sstQt01_tstrec2_TabMdl.cpp \
    sstQt01_tstrec2_TabView.cpp \
    sstQt01BaseTabMdl.cpp \
    sstQt01PathElementCsv1.cpp \
    sstQt01PathElementCsv2.cpp \
    sstQt01PathElementCsv3.cpp \
    sstQt01ShapeType.cpp \
    sstQt01PathStoreView.cpp \
    sstQt01PathStoreTab.cpp \
    sstQt01TestTabGroupBox.cpp \
    sstQt01MapSignal.cpp
#    sstStr01DefType.cpp \

OTHER_FILES += README.md

RESOURCES    += tooltips.qrc
RESOURCES    += images.qrc

debug{
  TARGET		= sstQt01Lib_d
}
release{
  TARGET		= sstQt01Lib_r
}

DESTDIR     = ../libs

DISTFILES += \
    sstQt01Lib.odt

qtHaveModule(printsupport): QT += printsupport
qtHaveModule(opengl): QT += opengl


