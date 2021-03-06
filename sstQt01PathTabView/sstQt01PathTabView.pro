CONFIG     += c++11

QT += widgets

# CONFIG       -= debug  # RELEASE ist aktiv
CONFIG       -= release  # DEBUG ist aktiv

INCLUDEPATH += ../../sstQt01Lib/Header
INCLUDEPATH += ../../sst_rec04_lib/Header
INCLUDEPATH += ../../sst_misc01_lib/Header
INCLUDEPATH +=  ../../sstMath01Lib/Header
INCLUDEPATH += ../../sst_str01_lib/Header

debug{
  LIBS        += ../../libs/libsstQt01Lib_d.a
  LIBS        += ../../libs/libsst_rec04_lib_d.a
  LIBS        += ../../libs/libsst_misc01_lib_d.a
  LIBS        += ../../libs/libsstMath01Lib_d.a
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
  LIBS        += ../../libs/libsstMath01Lib_r.a
  LIBS        += ../../libs/libsst_str01_lib_r.a
}

HEADERS       = \
                window.h
SOURCES       = main.cpp \
                window.cpp
# RESOURCES     = basicdrawing.qrc

TARGET = sstQt01PathTabView

qtHaveModule(printsupport): QT += printsupport
qtHaveModule(opengl): QT += opengl
