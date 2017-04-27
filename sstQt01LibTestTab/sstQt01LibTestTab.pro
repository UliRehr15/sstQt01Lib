TEMPLATE = app

CONFIG	 	 += warn_on
# CONFIG       += c++11

QT += widgets

CONFIG    -= release  # ist DEBUG aktiv

INCLUDEPATH += ../../sst_str01_lib/Header
INCLUDEPATH += ../../sst_misc01_lib/Header
INCLUDEPATH += ../../sst_rec04_lib/Header
INCLUDEPATH += ../../sstQt01Lib/Header

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


SOURCES  += \
    dialog.cpp \
    sstQt01_tstrec1_TabMdl.cpp \
    sstQt01_tstrec2_TabMdl.cpp \
    sstQt01LibTestTab.cpp \
    sstQt01_tstrec1_TabView.cpp \
    sstQt01_tstrec2_TabView.cpp

HEADERS  += \ 
    sst_qt_lib_test_tab.h \
    dialog.h


# install
TARGET =   sst_qt_lib_test_tab
