CC=gcc
CFLAGS=$(OPT) -Wall -ggdb -g3 -fPIC
LD=gcc
LDFLAGS=$(OPT) -ggdb -g3 -fPIC
OPT=-O2

all: cov debug prof prof_pg thread

debug: debug.o

cov.o: cov.c
	$(CC) $(CFLAGS) --coverage -c -o $@ $<

cov: cov.o
	$(CC) $(LDFLAGS) --coverage -o $@ $<

prof_pg.o: prof.c
	$(CC) $(CFLAGS) -c -pg -o $@ $<

prof_pg: prof_pg.o
	$(CC) $(LDFLAGS) -pg -o $@ $<

prof: prof.o

thread: thread.o
	$(CC) $(LDFLAGS) -o $@ $< -lpthread

clean:
	rm -f *.o *.gcno cov debug mac prof prof_pg thread

.PHONY: all
