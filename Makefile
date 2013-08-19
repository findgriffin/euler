IDIR =../utils
CC=gcc
CFLAGS=-I$(IDIR) -lm

ODIR=obj
LDIR =../lib

_DEPS = myhead.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

all: prob001/compare prob002/compare

prob%/prob.o: prob%/prob.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

prob%/prob.b: prob%/prob.o
	gcc -o $@ $^ $(CFLAGS)

prob%/answer-c: prob%/prob.b
	/usr/bin/time -f "%E" -o prob$*/time.c prob$*/prob.b > prob$*/answer-c
prob%/answer-py: prob%/prob.py
	/usr/bin/time -f "%E" -o prob$*/time.py prob$*/prob.py > prob$*/answer-py
prob%/answer-js: prob%/prob.js
	/usr/bin/time -f "%E" -o prob$*/time.js prob$*/prob.js > prob$*/answer-js

prob%/compare: prob%/answer-c prob%/answer-js prob%/answer-py

	echo -n "C:  " > prob$*/compare
	echo -n `cat prob$*/answer-c` >> prob$*/compare
	echo -n " in " >> prob$*/compare
	echo `cat prob$*/time.c` >> prob$*/compare

	echo -n "py: " >> prob$*/compare
	echo -n `cat prob$*/answer-py` >> prob$*/compare
	echo -n " in " >> prob$*/compare
	echo `cat prob$*/time.py` >> prob$*/compare

	echo -n "js: " >> prob$*/compare
	echo -n `cat prob$*/answer-js` >> prob$*/compare
	echo -n " in " >> prob$*/compare
	echo `cat prob$*/time.js` >> prob$*/compare

.PHONY: clean all

clean:
	rm -f */*.o */*.b */compare */answer-*
prob%/clean:
	rm -f prob$*/*.o prob$*/*.b prob$*/compare prob$*/answer.*
