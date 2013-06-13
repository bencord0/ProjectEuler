# Copyright 2013 Ben Cordero
#
# This file is part of my ProjectEuler implementations.
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.

TEMPLATE = app
TARGET = Euler
DEPENDPATH += .
INCLUDEPATH += .
LIBS += -lgmp
CONFIG += console

# Input
HEADERS += euler.h \
    functions.h \
    prime_generator.h \
    Problem001.h \
    Problem002.h \
    Problem003.h \
    Problem004.h \
    Problem005.h \
    Problem006.h \
    Problem007.h \
    Problem008.h \
    Problem009.h \
    Problem010.h \
    Problem011.h \
    Problem012.h \
    Problem013.h \
    Problem014.h \
    Problem015.h \
    Problem016.h \
    Problem017.h \
    Problem018.h \
    Problem020.h \
    Problem021.h \
    Problem023.h \
    Problem025.h \
    Problem034.h \
    Problem038.h \
    Problem043.h \
    Problem045.h \
    Problem048.h \
    Problem053.h \
    Problem057.h \
    Problem059.h
SOURCES += functions.c \
    main.c \
    prime_generator.c \
    Problem001.c \
    Problem002.c \
    Problem003.c \
    Problem004.c \
    Problem005.c \
    Problem006.c \
    Problem007.c \
    Problem008.c \
    Problem009.c \
    Problem010.c \
    Problem011.c \
    Problem012.c \
    Problem013.c \
    Problem014.c \
    Problem015.c \
    Problem016.c \
    Problem017.c \
    Problem018.c \
    Problem020.c \
    Problem021.c \
    Problem023.c \
    Problem025.c \
    Problem034.c \
    Problem038.c \
    Problem043.c \
    Problem045.c \
    Problem048.c \
    Problem053.c \
    Problem057.c \
    Problem059.c
