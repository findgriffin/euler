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

prob%/compare: prob%/prob.b prob%/prob.py prob%/prob.js
	echo c > prob$*/compare
	/usr/bin/time prob$*/prob.b >> prob$*/compare
	echo py >> prob$*/compare
	/usr/bin/time prob$*/prob.py >> prob$*/compare
	echo js >> prob$*/compare
	/usr/bin/time prob$*/prob.js >> prob$*/compare

.PHONY: clean

clean:
	rm -f */*.o */*.b
	rm -f */compare
