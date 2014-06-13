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

TARGET = Euler
LIBS=-lm -lgmp

all: Euler

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) -o Euler -I ./include $(LIBS) $(SOURCES)

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
SOURCES += src/functions.c \
    src/main.c \
    src/prime_generator.c \
    src/Problem001.c \
    src/Problem002.c \
    src/Problem003.c \
    src/Problem004.c \
    src/Problem005.c \
    src/Problem006.c \
    src/Problem007.c \
    src/Problem008.c \
    src/Problem009.c \
    src/Problem010.c \
    src/Problem011.c \
    src/Problem012.c \
    src/Problem013.c \
    src/Problem014.c \
    src/Problem015.c \
    src/Problem016.c \
    src/Problem017.c \
    src/Problem018.c \
    src/Problem020.c \
    src/Problem021.c \
    src/Problem023.c \
    src/Problem025.c \
    src/Problem034.c \
    src/Problem038.c \
    src/Problem043.c \
    src/Problem045.c \
    src/Problem048.c \
    src/Problem053.c \
    src/Problem057.c \
    src/Problem059.c
