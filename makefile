HOUSE: main.o introduction.o gameroom.o visuals.o casinowar.o horserace.o revive.o
	g++ main.o introduction.o gameroom.o visuals.o casinowar.o horserace.o revive.o -o HOUSE
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

horserace.o: horserace.cpp
	g++ -c horserace.cpp

revive.o: revive.cpp
	g++ -c revive.cpp

clean:
	rm *.o HOUSE
	clear