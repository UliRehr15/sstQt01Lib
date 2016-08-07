TEMPLATE	= lib
CONFIG		+= warn_on
CONFIG    += qt

# CONFIG    -= debug  # ist RELEASE aktiv
CONFIG    -= release  # ist DEBUG aktiv

CONFIG    += staticlib

INCLUDEPATH = ./Header

HEADERS		+= ./Header/sstQt01Lib.h

SOURCES		+= sstTemplateLib.cpp

OTHER_FILES += readme.txt

debug{
  TARGET		= sstQt01Lib_d
}
release{
  TARGET		= sstQt01Lib_r
}

DESTDIR     = ../libs
