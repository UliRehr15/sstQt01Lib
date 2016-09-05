TEMPLATE = app

CONFIG	 	 += warn_on
# CONFIG       += c++11

QT += widgets

CONFIG    -= release  # ist DEBUG aktiv

INCLUDEPATH += ../../sst_str01_lib/Header
INCLUDEPATH += ../../sst_misc01_lib/Header
INCLUDEPATH += ../../sst_rec04_lib/Header

debug{
  LIBS        += ../../libs/libsst_rec04_lib_d.a
  LIBS        += ../../libs/libsst_misc01_lib_d.a
  LIBS        += ../../libs/libsst_str01_lib_d.a
}

release{

  win32-g++:QMAKE_LFLAGS += -static
  win32-g++:QMAKE_LFLAGS -= -mthreads
  win32-g++:QMAKE_LFLAGS_EXCEPTIONS_ON -= -mthreads
  win32-g++:QMAKE_CXXFLAGS_EXCEPTIONS_ON -= -mthreads

  LIBS        += ../libs/libsst_ds2_lib_r.a
  LIBS        += ../libs/libsst_lib2_r.a
  LIBS        += ../libs/libsst_lib_r.a
  LIBS        += ../libs/libstr_lib_r.a
}


SOURCES  += \
    sst_qt_lib_test_Tab.cpp \
    sstDs2_tstrec1_qt_tab.cpp \
    sstDs2_tstrec2_qt_tab.cpp \
    dialog.cpp

HEADERS  += \ 
    sst_qt_lib_test_tab.h \
    dialog.h


# install
TARGET =   sst_qt_lib_test_tab
