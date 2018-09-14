#############################################################################
# Makefile for building: libsstQt01Lib_d.a
# Generated by qmake (3.1) (Qt 5.9.5)
# Project:  sstQt01Lib.pro
# Template: lib
# Command: /usr/lib/qt5/bin/qmake -o Makefile sstQt01Lib.pro -spec linux-clang CONFIG+=debug CONFIG+=qml_debug
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = clang
CXX           = clang++
DEFINES       = -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_QML_DEBUG
CFLAGS        = -pipe -g -fPIC -D_REENTRANT -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -g -fPIC -std=gnu++11 -D_REENTRANT -Wall -W $(DEFINES)
INCPATH       = -I. -I../sst_rec04_lib/Header -I../sst_misc01_lib/Header -I../sst_str01_lib/Header -IHeader -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -I. -isystem /usr/include/libdrm -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-clang
QMAKE         = /usr/lib/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/lib/qt5/bin/qmake -install qinstall
QINSTALL_PROGRAM = /usr/lib/qt5/bin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = sstQt01Lib_d1.0.0
DISTDIR = /home/uli/Entwicklung/sstQt01Lib/.tmp/sstQt01Lib_d1.0.0
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = sstQt01Tab.cpp \
		sstQt01TabView.cpp \
		sstQt01ShapeItem.cpp \
		sstQt01PathTabModel.cpp \
		sstQt01PathPaintWidget.cpp \
		sstQt01TestPaintWidget.cpp \
		sstQt01PathTabView.cpp \
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
		sstQt01PathStoreTab.cpp qrc_tooltips.cpp \
		moc_sstQt01Lib.cpp \
		moc_sstQt01LibInt.cpp
OBJECTS       = sstQt01Tab.o \
		sstQt01TabView.o \
		sstQt01ShapeItem.o \
		sstQt01PathTabModel.o \
		sstQt01PathPaintWidget.o \
		sstQt01TestPaintWidget.o \
		sstQt01PathTabView.o \
		sstQt01_tstrec1_TabMdl.o \
		sstQt01_tstrec1_TabView.o \
		sstQt01_tstrec2_TabMdl.o \
		sstQt01_tstrec2_TabView.o \
		sstQt01BaseTabMdl.o \
		sstQt01PathElementCsv1.o \
		sstQt01PathElementCsv2.o \
		sstQt01PathElementCsv3.o \
		sstQt01ShapeType.o \
		sstQt01PathStoreView.o \
		sstQt01PathStoreTab.o \
		qrc_tooltips.o \
		moc_sstQt01Lib.o \
		moc_sstQt01LibInt.o
DIST          = /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/clang.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-clang/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qml_debug.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		sstQt01Lib.pro Header/sstQt01Lib.h \
		sstQt01LibInt.h sstQt01Tab.cpp \
		sstQt01TabView.cpp \
		sstQt01ShapeItem.cpp \
		sstQt01PathTabModel.cpp \
		sstQt01PathPaintWidget.cpp \
		sstQt01TestPaintWidget.cpp \
		sstQt01PathTabView.cpp \
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
		sstQt01PathStoreTab.cpp
QMAKE_TARGET  = sstQt01Lib_d
DESTDIR       = ../libs/
TARGET        = libsstQt01Lib_d.a


first: all
####### Build rules

staticlib: ../libs/$(TARGET)

../libs/$(TARGET):  $(OBJECTS) $(OBJCOMP) 
	@test -d ../libs/ || mkdir -p ../libs/
	-$(DEL_FILE) ../libs/$(TARGET)
	$(AR) $(DESTDIR)$(TARGET) $(OBJECTS)


Makefile: sstQt01Lib.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-clang/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/clang.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-clang/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qml_debug.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		sstQt01Lib.pro \
		tooltips.qrc \
		/usr/lib/x86_64-linux-gnu/libQt5Widgets.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Gui.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Core.prl
	$(QMAKE) -o Makefile sstQt01Lib.pro -spec linux-clang CONFIG+=debug CONFIG+=qml_debug
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/clang.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-clang/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qml_debug.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
sstQt01Lib.pro:
tooltips.qrc:
/usr/lib/x86_64-linux-gnu/libQt5Widgets.prl:
/usr/lib/x86_64-linux-gnu/libQt5Gui.prl:
/usr/lib/x86_64-linux-gnu/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile sstQt01Lib.pro -spec linux-clang CONFIG+=debug CONFIG+=qml_debug

qmake_all: FORCE


all: Makefile ../libs/$(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents tooltips.qrc $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents Header/sstQt01Lib.h sstQt01LibInt.h $(DISTDIR)/
	$(COPY_FILE) --parents sstQt01Tab.cpp sstQt01TabView.cpp sstQt01ShapeItem.cpp sstQt01PathTabModel.cpp sstQt01PathPaintWidget.cpp sstQt01TestPaintWidget.cpp sstQt01PathTabView.cpp sstQt01_tstrec1_TabMdl.cpp sstQt01_tstrec1_TabView.cpp sstQt01_tstrec2_TabMdl.cpp sstQt01_tstrec2_TabView.cpp sstQt01BaseTabMdl.cpp sstQt01PathElementCsv1.cpp sstQt01PathElementCsv2.cpp sstQt01PathElementCsv3.cpp sstQt01ShapeType.cpp sstQt01PathStoreView.cpp sstQt01PathStoreTab.cpp $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) ../libs/$(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all: qrc_tooltips.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_tooltips.cpp
qrc_tooltips.cpp: tooltips.qrc \
		/usr/lib/qt5/bin/rcc \
		images/circle.png \
		images/polyline.png \
		images/text.png \
		images/arc.png \
		images/line.png \
		images/square.png \
		images/triangle.png
	/usr/lib/qt5/bin/rcc -name tooltips tooltips.qrc -o qrc_tooltips.cpp

compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp
	clang++ -pipe -g -fPIC -std=gnu++11 -dM -E -o moc_predefs.h /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_sstQt01Lib.cpp moc_sstQt01LibInt.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_sstQt01Lib.cpp moc_sstQt01LibInt.cpp
moc_sstQt01Lib.cpp: ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-clang -I/home/uli/Entwicklung/sstQt01Lib -I/home/uli/Entwicklung/sst_rec04_lib/Header -I/home/uli/Entwicklung/sst_misc01_lib/Header -I/home/uli/Entwicklung/sst_str01_lib/Header -I/home/uli/Entwicklung/sstQt01Lib/Header -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/7.3.0 -I/usr/include/x86_64-linux-gnu/c++/7.3.0 -I/usr/include/c++/7.3.0/backward -I/usr/include/clang/6.0.0/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include Header/sstQt01Lib.h -o moc_sstQt01Lib.cpp

moc_sstQt01LibInt.cpp: ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		sstQt01LibInt.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-clang -I/home/uli/Entwicklung/sstQt01Lib -I/home/uli/Entwicklung/sst_rec04_lib/Header -I/home/uli/Entwicklung/sst_misc01_lib/Header -I/home/uli/Entwicklung/sst_str01_lib/Header -I/home/uli/Entwicklung/sstQt01Lib/Header -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/7.3.0 -I/usr/include/x86_64-linux-gnu/c++/7.3.0 -I/usr/include/c++/7.3.0/backward -I/usr/include/clang/6.0.0/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include sstQt01LibInt.h -o moc_sstQt01LibInt.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_rcc_clean compiler_moc_predefs_clean compiler_moc_header_clean 

####### Compile

sstQt01Tab.o: sstQt01Tab.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		sstQt01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01Tab.o sstQt01Tab.cpp

sstQt01TabView.o: sstQt01TabView.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		sstQt01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01TabView.o sstQt01TabView.cpp

sstQt01ShapeItem.o: sstQt01ShapeItem.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01ShapeItem.o sstQt01ShapeItem.cpp

sstQt01PathTabModel.o: sstQt01PathTabModel.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		sstQt01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01PathTabModel.o sstQt01PathTabModel.cpp

sstQt01PathPaintWidget.o: sstQt01PathPaintWidget.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01PathPaintWidget.o sstQt01PathPaintWidget.cpp

sstQt01TestPaintWidget.o: sstQt01TestPaintWidget.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01TestPaintWidget.o sstQt01TestPaintWidget.cpp

sstQt01PathTabView.o: sstQt01PathTabView.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		sstQt01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01PathTabView.o sstQt01PathTabView.cpp

sstQt01_tstrec1_TabMdl.o: sstQt01_tstrec1_TabMdl.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		sstQt01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01_tstrec1_TabMdl.o sstQt01_tstrec1_TabMdl.cpp

sstQt01_tstrec1_TabView.o: sstQt01_tstrec1_TabView.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		sstQt01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01_tstrec1_TabView.o sstQt01_tstrec1_TabView.cpp

sstQt01_tstrec2_TabMdl.o: sstQt01_tstrec2_TabMdl.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		sstQt01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01_tstrec2_TabMdl.o sstQt01_tstrec2_TabMdl.cpp

sstQt01_tstrec2_TabView.o: sstQt01_tstrec2_TabView.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		sstQt01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01_tstrec2_TabView.o sstQt01_tstrec2_TabView.cpp

sstQt01BaseTabMdl.o: sstQt01BaseTabMdl.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		sstQt01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01BaseTabMdl.o sstQt01BaseTabMdl.cpp

sstQt01PathElementCsv1.o: sstQt01PathElementCsv1.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		sstQt01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01PathElementCsv1.o sstQt01PathElementCsv1.cpp

sstQt01PathElementCsv2.o: sstQt01PathElementCsv2.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		sstQt01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01PathElementCsv2.o sstQt01PathElementCsv2.cpp

sstQt01PathElementCsv3.o: sstQt01PathElementCsv3.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		sstQt01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01PathElementCsv3.o sstQt01PathElementCsv3.cpp

sstQt01ShapeType.o: sstQt01ShapeType.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01ShapeType.o sstQt01ShapeType.cpp

sstQt01PathStoreView.o: sstQt01PathStoreView.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		sstQt01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01PathStoreView.o sstQt01PathStoreView.cpp

sstQt01PathStoreTab.o: sstQt01PathStoreTab.cpp ../sst_str01_lib/Header/sstStr01Lib.h \
		../sst_misc01_lib/Header/sstMisc01Lib.h \
		../sst_rec04_lib/Header/sstRec04Lib.h \
		Header/sstQt01Lib.h \
		sstQt01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstQt01PathStoreTab.o sstQt01PathStoreTab.cpp

qrc_tooltips.o: qrc_tooltips.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_tooltips.o qrc_tooltips.cpp

moc_sstQt01Lib.o: moc_sstQt01Lib.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_sstQt01Lib.o moc_sstQt01Lib.cpp

moc_sstQt01LibInt.o: moc_sstQt01LibInt.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_sstQt01LibInt.o moc_sstQt01LibInt.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

