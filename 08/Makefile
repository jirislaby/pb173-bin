CC=gcc
BITS=64
CFLAGS=-O2 -Wall -g -m$(BITS) -fno-stack-protector
LD=gcc
LDFLAGS=-O2 -g -m$(BITS) -nostdlib -Wl,-e -Wl,start

all: nostd

nostd: nostd.o

.PHONY: all
