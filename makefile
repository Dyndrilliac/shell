shell.exe: stringSplitter.o shell.o main.o
	g++ -o shell.exe stringSplitter.o shell.o main.o

stringSplitter.o:
	g++ -c -w stringSplitter.hpp shell.hpp main.hpp stringSplitter.cpp

shell.o:
	g++ -c -w stringSplitter.hpp shell.hpp main.hpp shell.cpp

main.o:
	g++ -c -w stringSplitter.hpp shell.hpp main.hpp main.cpp

clean:
	rm -rf *.exe *.gch *.o

execute: shell.exe
	./shell.exe