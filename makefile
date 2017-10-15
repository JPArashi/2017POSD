HW_NAME = hw3

all: $(HW_NAME)

${HW_NAME}: mainUTAll.o
ifeq (${OS}, Windows_NT)
	g++ -o $(HW_NAME) mainUTAll.o -lgtest
else
	g++ -o $(HW_NAME) mainUTAll.o -lgtest -lpthread
endif

mainUTAll.o: mainUTAll.cpp atom.h variable.h number.h term.h utVariable.h utStruct.h struct.h
	g++ -std=gnu++0x -c mainUTAll.cpp
	more utVariable.h

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o $(HW_NAME)
endif