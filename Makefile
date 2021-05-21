CC     = gcc
CFLAGS = -Wall
BUILD  = quadratics utils fibs

all: $(BUILD)	

clean: 
	    /bin/rm -f $(BUILD) *.o core
			cd Quadratics; make clean
			cd Utilities; make clean
			cd Fibonacci; make clean

quadratics: 
	         cd Quadratics; make 
utils: 
	         cd Utilities; make 
fibs: 
	         cd Fibonacci; make 
