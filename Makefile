CC     = gcc
CFLAGS = -Wall
BUILD  = quadratics utils fibs toBinary

all: $(BUILD)	

clean: 
	    /bin/rm -f $(BUILD) *.o core
			cd Quadratics; make clean
			cd Utilities; make clean
			cd Fibonacci; make clean
			cd BinaryConversions; make clean

quadratics: 
	         cd Quadratics; make 
utils: 
	         cd Utilities; make 
fibs: 
	         cd Fibonacci; make 
toBinary: 
	         cd BinaryConversions; make 
