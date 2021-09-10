CC = gcc
CFLAGS = -Wall -pedantic -std=gnu99
DEBUG = -g
TARGETS = read.out

.DEFAULT: all

.PHONY: all debug clean

all: $(TARGETS)

debug: CFLAGS += $(DEBUG)
debug: clean $(TARGETS)

read.out: read.c get_input.o
	$(CC) $(CFLAGS) read.c get_input.o -o read.out

get_input.o: get_input.c
	$(CC) $(CFLAGS) -c get_input.c -o get_input.o

clean:
	rm -f *.o *.out
