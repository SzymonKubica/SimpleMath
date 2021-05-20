CC 			= gcc
CFLAGS 	= -Wall 
LIBS		= -lm
BUILD		= quadratic

all: 		$(BUILD)
clean: 
				/bin/rm -f $(BUILD) *.o core

quadratic:	quadratic.o
						$(CC) $(CFLAGS) quadratic.o -o $(BUILD) $(LIBS)
