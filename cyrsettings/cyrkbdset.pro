TEMPLATE	= app
#CONFIG		= qt warn_on debug
CONFIG		= qt warn_on release
HEADERS		= cyrkbdset.h
SOURCES		= main.cpp cyrkbdset.cpp
LIBS            += -lqpe
TARGET		= cyrkbdset
INTERFACES	= cyrkbdsetbase.ui
TRANSLATIONS	= cyrkbdset-ru.ts
