TEMPLATE = lib
HEADERS = custominput.h keyboard.h keyboardhandler.h
SOURCES = custominput.cpp keyboard.cpp keyboardhandler.cpp

TARGET=cyrinput
DESTDIR=$(QPEDIR)/plugins/inputmethods
VERSION = 1.0.0

MOC_DIR = .moc
OBJECTS_DIR = .obj

INCLUDEPATH     += $(QPEDIR)/include
DEPENDPATH      += $(QPEDIR)/include
LIBS            += -lqpe

CONFIG +=
