# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (c) 2020 Brett Sheffield <bacs@librecast.net>

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
