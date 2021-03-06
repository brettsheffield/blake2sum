# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (c) 2020 Brett Sheffield <bacs@librecast.net>

CFLAGS := -Wall -Wextra -Wpedantic -g
export CFLAGS
INSTALLDIR := /usr/local/bin
export INSTALLDIR
PROGRAM := blake2sum
export PROGRAM

.PHONY: all clean src test check install

all: src

install: all
	cd src && $(MAKE) $@

src:
	$(MAKE) -C $@

clean realclean:
	cd src && $(MAKE) $@

sparse: clean
	CC=cgcc $(MAKE) src

clang: clean
	CC=clang $(MAKE) src
