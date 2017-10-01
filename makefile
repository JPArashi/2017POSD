HW_NAME = hw2

all: $(HW_NAME)

${HW_NAME}: mainTerm.o atom.o variable.o number.o
ifeq (${OS}, Windows_NT)
	g++ -o $(HW_NAME) mainTerm.o atom.o variable.o number.o -lgtest
else
	g++ -o $(HW_NAME) mainTerm.o atom.o variable.o number.o -lgtest -lpthread
endif
	
mainTerm.o: mainTerm.cpp atom.h variable.h number.h utTerm.h
	g++ -std=c++11 -c mainTerm.cpp
	g++ -std=c++11 -c atom.cpp
	g++ -std=c++11 -c variable.cpp
	g++ -std=c++11 -c number.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o $(HW_NAME)
endif