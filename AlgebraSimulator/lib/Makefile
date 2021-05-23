CC      = gcc 
CFLAGS  = -Wall -g
LIB     = libparser.a
LIBOBJS = parser.o
BUILD   = $(LIB)  

all: $(BUILD)

clean: 
			/bin/rm -f $(BUILD) *.o core

$(LIB): $(LIBOBJS)
	ar rcs $(LIB) $(LIBOBJS)

parser.o: parser.h
