IDIR =../utils
CC=gcc
CFLAGS=-I$(IDIR) -lm

ODIR=obj
LDIR =../lib

_DEPS = myhead.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

prob%/prob.o: prob%/prob.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

prob%/prob.b: prob%/prob.o
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f */*.o */*.b
	rm -f */answers
