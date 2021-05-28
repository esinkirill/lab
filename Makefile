all: inter.o soldier.o main.o laba

soldier.o: soldier.cpp
	g++ -c -o soldier.o soldier.cpp

inter.o: inter.cpp
	g++ -c -o inter.o inter.cpp

main.o: main.cpp
	g++ -c -o main.o main.cpp

laba: soldier.o inter.o main.o
	g++ soldier.o inter.o main.o -o laba
