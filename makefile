HW_NAME = hw5
HEADER_FILE = atom.h variable.h struct.h number.h term.h \
		      list.h scanner.h parser.h global.h
UNIT_TEST_FILE = utParser.h

all: $(HW_NAME)

${HW_NAME}: main.o
ifeq (${OS}, Windows_NT)
	g++ -o $(HW_NAME) main.o -lgtest
else
	g++ -o $(HW_NAME) main.o -lgtest -lpthread
endif

main.o: main.cpp $(HEADER_FILE) $(UNIT_TEST_FILE)
	g++ -std=gnu++0x -c main.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o $(HW_NAME)
endif