./bin/shell.out: ./src/stringSplitter.o ./src/shell.o ./src/main.o
	g++ -o ./bin/shell.out ./src/stringSplitter.o ./src/shell.o ./src/main.o

./src/stringSplitter.o:
	g++ -c -w ./src/stringSplitter.hpp ./src/shell.hpp ./src/main.hpp ./src/stringSplitter.cpp
	mv stringSplitter.o ./src/

./src/shell.o:
	g++ -c -w ./src/stringSplitter.hpp ./src/shell.hpp ./src/main.hpp ./src/shell.cpp
	mv shell.o ./src/

./src/main.o:
	g++ -c -w ./src/stringSplitter.hpp ./src/shell.hpp ./src/main.hpp ./src/main.cpp
	mv main.o ./src/

clean:
	rm -rf ./bin/shell.out ./src/*.gch ./src/*.o

execute: ./bin/shell.out
	./bin/shell.out
