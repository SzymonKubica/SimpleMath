CC     = gcc
CFLAGS = -Wall -Ilib
LDLIBS = -Llib -lparser
BUILD  = libs test

all: $(BUILD)

clean: 
	    /bin/rm -f $(BUILD) *.o core
			cd lib; make clean

libs:
	   cd lib; make

test: test.o
