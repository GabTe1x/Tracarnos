CPP=g++ --std=c++11 -Wall
CCO=$(CPP) -c $<
OBJ= Test.o Joueur.o Plateau.o Tuile.o

all : $(OBJ)
	$(CPP) -o go $(OBJ)
	./go

Joueur.o : Joueur.cpp Joueur.hpp
	$(CCO)

Plateau.o : Plateau.cpp Plateau.hpp
	$(CCO)

Tuile.o : Tuile.cpp Tuile.hpp
	$(CCO)

Test.o : Test.cpp
	$(CCO)

clean :
	rm -f *.o go