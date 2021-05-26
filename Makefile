all: soldier.o main.o laba

soldier.o: soldier.cpp
	g++ -c -o soldier.o soldier.cpp

main.o: main.cpp
	g++ -c -o main.o main.cpp

laba: soldier.o main.o
	g++ main.o soldier.o -o laba