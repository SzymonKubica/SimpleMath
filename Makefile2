CC     = gcc
CFLAGS = -Wall
BUILD  = quadratics utils  

all: $(BUILD)	

clean: 
	    /bin/rm -f $(BUILD) *.o core
			cd Quadratics; make clean
			cd Utilities; make clean

quadratics: 
	         cd Quadratics; make 
utils: 
	         cd Utilities; make 
