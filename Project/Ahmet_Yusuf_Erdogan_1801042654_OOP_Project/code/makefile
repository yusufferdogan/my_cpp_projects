output: 	main.o Ants.o DoodleBugs.o Organism.o PoisonousAnt.o World.o
	g++ main.o Ants.o DoodleBugs.o Organism.o PoisonousAnt.o World.o -o output
main.o:	main.cpp
	g++ -c 	main.cpp
Ants.o:	Ants.cpp Ants.h
	g++ -c	Ants.cpp
Doodlebugs.o:	DoodleBugs.cpp DoodleBugs.h
	g++ -c	DoodleBugs.cpp
Organism.o:	Organism.cpp Organism.h
	g++ -c	Organism.cpp
PoisonousAnt.o:	PoisonousAnt.cpp PoisonousAnt.h
	g++ -c	PoisonousAnt.cpp
World.o:	World.cpp World.h
	g++ -c	World.cpp
clean:
	rm *.o output
