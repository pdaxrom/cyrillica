TEMPLATE	= lib
CONFIG		+= qt warn_on release
HEADERS	=   keybshow.h kbdappletimpl.h
SOURCES	=   keybshow.cpp kbdappletimpl.cpp
TARGET		= kbdapplet
DESTDIR		= $(QPEDIR)/plugins/applets
INCLUDEPATH += $(QPEDIR)/include
DEPENDPATH      += ../$(QPEDIR)/include ..
LIBS            += -lqpe
VERSION		= 1.0.0

TRANSLATIONS += ../../i18n/de/libclockapplet.ts
