# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (c) 2020 Brett Sheffield <bacs@librecast.net>

SHELL = /bin/sh
.SUFFIXES:
.SUFFIXES: .c .o
INSTALL := install
INSTALL_PROGRAM := $(INSTALL)
INSTALL_DATA := $(INSTALL) -m 644
prefix ?= /usr/local
exec_prefix := $(prefix)
bindir := $(exec_prefix)/bin
PROGRAM ?= blake2sum
CFLAGS +=
LDFLAGS += -lsodium
OBJS = $(PROGRAM).o

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(PROGRAM).o:

.PHONY: clean

clean:
	rm -f *.o

realclean: clean
	rm -f $(PROGRAM)

install:	all
		$(INSTALL) -d $(DESTDIR)$(bindir)
		$(INSTALL_PROGRAM) $(PROGRAM) $(DESTDIR)$(bindir)/$(PROGRAM)
