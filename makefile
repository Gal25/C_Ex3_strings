CC=gcc
AR=ar
FLAGS= -Wall -g 
LM = -lm

all: stringProg

stringProg:  libStringProg.a
	$(CC) $(FLAGS) -o stringProg libStringProg.a 

libStringProg.a: string.o
	$(AR) -rcs libStringProg.a string.o

string.o: string.c string.h
	$(CC) $(FLAGS) -c string.c

.PHONY: clean all

clean:
	rm -f *.o *.a stringProg
