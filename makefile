CC=gcc
AR=ar
FLAGS= -Wall -g 
LM = -lm

all: StringProg

StringProg:  libStringProg.a
	$(CC) $(FLAGS) -o StringProg libStringProg.a 

libStringProg.a: string.o
	$(AR) -rcs libStringProg.a string.o

string.o: string.c 
	$(CC) $(FLAGS) -c string.c

.PHONY: clean all

clean:
	rm -f *.o *.a StringProg