all: sort.o main.o
	g++ -g -o main sort.cpp sort.h main.o

main: sort.o main.o
	g++ -g -o main sort.cpp sort.h main.o

main.o: sort.cpp sort.h main.cpp
sort.o: sort.cpp sort.h

clean:
	rm -f sort.o main.o
