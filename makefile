CPP=g++ --std=c++11 -Wall
CCO=$(CPP) -c $<
OBJ= Test.o Controleur.o Joueur.o PlateauDominos.o Dominos.o
HPP=src/hpp/
C=src/cpp/

all : $(OBJ)
	$(CPP) -o go $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system
	./go
Controleur.o : $(C)Controleur.cpp $(HPP)Controleur.hpp
	$(CCO)

Joueur.o : $(C)Joueur.cpp $(HPP)Joueur.hpp
	$(CCO)

PlateauDominos.o : $(C)PlateauDominos.cpp $(HPP)PlateauDominos.hpp
	$(CCO)

Dominos.o : $(C)Dominos.cpp $(HPP)Dominos.hpp
	$(CCO)

Test.o : $(C)Test.cpp
	$(CCO)

clean :
	rm -f *.o go