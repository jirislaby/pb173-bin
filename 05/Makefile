CFLAGS=-Wall -Og -ggdb

all: to_load

elf: LDLIBS=-lelf

to_load: to_load.o
	ld -s -o $@ $^

%.o: %.s
	as -o $@ $^
