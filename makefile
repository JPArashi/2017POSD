HW_NAME = hw7
HEADER_FILE = atom.h variable.h struct.h number.h term.h \
		      list.h scanner.h parser.h global.h node.h  \
			  iterator.h
OBJECT_FILE = term.o struct.o list.o node.o
UNIT_TEST_FILE = utIterator.h


all: $(HW_NAME)

${HW_NAME}: main.o
ifeq (${OS}, Windows_NT)
	g++ -o $(HW_NAME) main.o $(OBJECT_FILE) -lgtest
else
	g++ -o $(HW_NAME) main.o $(OBJECT_FILE) -lgtest -lpthread
endif

main.o: main.cpp $(HEADER_FILE) $(UNIT_TEST_FILE) $(OBJECT_FILE)
	g++ -std=gnu++0x -c main.cpp

term.o: term.h term.cpp iterator.h
	g++ -std=gnu++0x -c term.cpp

struct.o: struct.h struct.cpp iterator.h
	g++ -std=gnu++0x -c struct.cpp

list.o: list.h list.cpp iterator.h
	g++ -std=gnu++0x -c list.cpp

node.o: node.h node.cpp iterator.h
	g++ -std=gnu++0x -c node.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o $(HW_NAME)
endif