all: sort.o main.o zsort.o
	g++ -g -o main sort.cpp sort.h main.o zsort.h zsort.o

main: sort.o main.o zsort.o
	g++ -g -o main sort.cpp sort.h main.o zsort.h zsort.o

main.o: sort.cpp sort.h main.cpp
sort.o: sort.cpp sort.h
zsort.o: zsort.cpp zsort.h
clean:
	rm -f sort.o main.o
