TEMPLATE	= lib
CONFIG		+= warn_on
CONFIG    += qt

# CONFIG    -= debug  # ist RELEASE aktiv
CONFIG    -= release  # ist DEBUG aktiv

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
             sstQt01PathStorage.cpp \
    sstQt01TabView.cpp \
    sstQt01ShapeItem.cpp \
    sstQt01PathTabModel.cpp \
    sstQt01PathPaintWidget.cpp \
    sstQt01TestPaintWidget.cpp \
    sstQt01PathElementCsv1.cpp \
    sstQt01PathElementCsv2.cpp \
    sstQt01PathTabView.cpp \
    sstQt01FormatStore.cpp

OTHER_FILES += README.md

RESOURCES     = tooltips.qrc

debug{
  TARGET		= sstQt01Lib_d
}
release{
  TARGET		= sstQt01Lib_r
}

DESTDIR     = ../libs


