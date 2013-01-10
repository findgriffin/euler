
all: prob001/prob001.b

clean: 
	rm -f prob*/prob*.o prob*/prob*.b

.PHONY: all clean

CFLAGS :=--std=c99 -g -Wall  -lm

prob%/prob%.b: prob%/prob%.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

prob%/prob%.o: prob%/prob%.c utils/myhead.h

