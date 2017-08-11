TEMPLATE	    = app
CONFIG	 	   += warn_on
CONFIG       += qt
CONFIG       += windows
CONFIG       += c++11


QT += widgets

# CONFIG       -= debug  # RELEASE ist aktiv
CONFIG       -= release  # DEBUG ist aktiv


INCLUDEPATH += ../../sst_str01_lib/Header
INCLUDEPATH += ../../sst_misc01_lib/Header
INCLUDEPATH += ../../sst_rec04_lib/Header
INCLUDEPATH += ../../sstQt01Lib/Header

HEADERS     = \
    sstQt01LibTestTab2.h
SOURCES     = \
    sstQt01LibTestTab2.cpp \
    TabTest2_Dialog.cpp

debug{
  LIBS        += ../../libs/libsstQt01Lib_d.a
  LIBS        += ../../libs/libsst_rec04_lib_d.a
  LIBS        += ../../libs/libsst_misc01_lib_d.a
  LIBS        += ../../libs/libsst_str01_lib_d.a
}

release{

  win32-g++:QMAKE_LFLAGS += -static
  win32-g++:QMAKE_LFLAGS -= -mthreads
  win32-g++:QMAKE_LFLAGS_EXCEPTIONS_ON -= -mthreads
  win32-g++:QMAKE_CXXFLAGS_EXCEPTIONS_ON -= -mthreads

  LIBS        += ../../libs/libsstQt01Lib_r.a
  LIBS        += ../../libs/libsst_rec04_lib_r.a
  LIBS        += ../../libs/libsst_misc01_lib_r.a
  LIBS        += ../../libs/libsst_str01_lib_r.a
}

TARGET	  	= sstQt01LibTestTab2

# copy to deployment directory
# DESTDIR     = ../../../local_deploy
