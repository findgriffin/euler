IDIR =../utils
CC=gcc
CFLAGS=-I$(IDIR) -lm

ODIR=obj
LDIR =../lib

_DEPS = myhead.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

all: prob001/compare

prob%/prob.o: prob%/prob.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

prob%/prob.b: prob%/prob.o
	gcc -o $@ $^ $(CFLAGS)

prob%/answer.c: prob%/prob.b
	prob$*/prob.b > prob$*/answer.c
prob%/answer.py: prob%/prob.py
	prob$*/prob.py > prob$*/answer.py
prob%/answer.js: prob%/prob.js
	prob$*/prob.js > prob$*/answer.js

prob%/compare: prob%/prob.b prob%/prob.py prob%/prob.js
	echo c > prob$*/compare
	/usr/bin/time prob$*/prob.b >> prob$*/compare
	echo py >> prob$*/compare
	/usr/bin/time prob$*/prob.py >> prob$*/compare
	echo js >> prob$*/compare
	/usr/bin/time prob$*/prob.js >> prob$*/compare

.PHONY: clean all

clean:
	rm -f */*.o */*.b
	rm -f */compare
