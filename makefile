CPP=g++ --std=c++11 -Wall
CCO=$(CPP) -c $<
OBJ= Test.o Joueur.o Plateau.o Dominos.o
HPP=src/hpp/
C=src/cpp/

all : $(OBJ)
	$(CPP) -o go $(OBJ)
	./go

Joueur.o : $(C)Joueur.cpp $(HPP)Joueur.hpp
	$(CCO)

Plateau.o : $(C)Plateau.cpp $(HPP)Plateau.hpp
	$(CCO)

Dominos.o : $(C)Dominos.cpp $(HPP)Dominos.hpp
	$(CCO)

Test.o : $(C)Test.cpp
	$(CCO)

clean :
	rm -f *.o go