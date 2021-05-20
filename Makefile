CC 			= gcc
CFLAGS 	= -Wall
BUILD		= quadratic

all: 		$(Build)
clean: 
				/bin/rm -f $(BUILD) *.o core
quadratic:		quadratic.o
