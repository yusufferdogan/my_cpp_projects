output: 	main.o Creature.o Human.o Elf.o Demon.o Cyberdemon.o Balrog.o
	g++ main.o Creature.o Human.o Elf.o Demon.o Cyberdemon.o Balrog.o -o output
main.o:	main.cpp
	g++ -c 	main.cpp
Creature.o:	Creature.cpp Creature.h
	g++ -c	Creature.cpp
Human.o:	Human.cpp Human.h
	g++ -c	Human.cpp
Demon.o:	Demon.cpp Demon.h
	g++ -c	Demon.cpp
Balrog.o:	Balrog.cpp Balrog.h
	g++ -c	Balrog.cpp
Cyberdemon.o:	Cyberdemon.cpp Cyberdemon.h
	g++ -c	Cyberdemon.cpp
Elf.o:	Elf.cpp Elf.h
	g++ -c	Elf.cpp
clean:
	rm *.o output
