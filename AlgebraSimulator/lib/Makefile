CC     = gcc
CFLAGS = -Wall -g
BUILD  = test 

all: $(BUILD)

clean: 
			/bin/rm -f $(BUILD) *.o core

parser.o: parser.h
test: test.o parser.o
test.o: parser.h
