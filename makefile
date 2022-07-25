HOUSE: main.o introduction.o gameroom.o visuals.o casinowar.o
	g++ main.o introduction.o gameroom.o visuals.o casinowar.o -o HOUSE
	clear

main.o: main.cpp
	g++ -c main.cpp

introduction.o: introduction.cpp
	g++ -c introduction.cpp

gameroom.o: gameroom.cpp
	g++ -c gameroom.cpp

visuals.o: visuals.cpp
	g++ -c visuals.cpp

casinowar.o: casinowar.cpp
	g++ -c casinowar.cpp

clean:
	rm *.o HOUSE
	clear