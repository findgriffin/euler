
all: prob001/prob001

clean: 
	rm -f prob*/prob*.o

.PHONY: all clean

CFLAGS := -g -Wall -lm

prob%/prob%: prob%/prob%.o 
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

prob%/prob%.o: prob%/prob%.c utils/myhead.h
