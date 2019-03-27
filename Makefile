###
### @author - Adil Chaudhry <chaudhra@oregonstate.edu>
### @description - Makefile for Project 4 
###

CFLAGS = -std=c++11 -ggdb3 -Wall

Project4: main.o Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o Menu.o Tournament.o inputValidation.o
	g++ $(CFLAGS) main.o Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o Menu.o Tournament.o inputValidation.o -o Project4

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp
	
Character.o: Character.cpp Character.h
	g++ $(CFLAGS) -c Character.cpp
	
Barbarian.o: Barbarian.cpp Barbarian.h
	g++ $(CFLAGS) -c Barbarian.cpp
	
Vampire.o: Vampire.cpp Vampire.h
	g++ $(CFLAGS) -c Vampire.cpp
	
BlueMen.o: BlueMen.cpp BlueMen.h
	g++ $(CFLAGS) -c BlueMen.cpp
	
Medusa.o: Medusa.cpp Medusa.h
	g++ $(CFLAGS) -c Medusa.cpp
	
HarryPotter.o: HarryPotter.cpp HarryPotter.h
	g++ $(CFLAGS) -c HarryPotter.cpp
	
Menu.o: Menu.cpp Menu.h
	g++ $(CFLAGS) -c Menu.cpp
	
inputValidation.o: inputValidation.cpp inputValidation.h
	g++ $(CFLAGS) -c inputValidation.cpp

Tournament.o: Tournament.cpp Tournament.h
	g++ $(CFLAGS) -c Tournament.cpp
	
clean:
	rm *.o Project4