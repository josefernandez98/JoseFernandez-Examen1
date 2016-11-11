Main:	Main.o Tablero.o
	g++ Main.o Tablero.o -o Main
Main.o:	Main.cpp Tablero.h
	g++ -c Main.cpp
Tablero.o: Tablero.h Tablero.cpp
	g++ -c Tablero.cpp
