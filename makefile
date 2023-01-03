CPP := g++ -Wall -std=c++11

VIEW	:= src/view/
MODEL	:= src/model/
CTRL	:= src/controleur/
HPP		:= src/include/

LIBRAIRIES	:= -lsfml-graphics -lsfml-window -lsfml-system

CCO= $(CPP) -c $<
OBJECTS= Test.o App.o GameDominos.o ManageurEtat.o EndGame.o Menu.o ParamDominos.o SpriteDominos.o Controleur.o ControleurTrax.o TuileTrax.o PlateauTrax.o ControleurCarca.o TuileCarca.o PlateauCarca.o Terrain.o Dominos.o Joueur.o PlateauDominos.o# liste des objets intermédiaires

all : $(OBJECTS)
	$(CPP) -o tracarnos $(OBJECTS) $(LIBRAIRIES)
	./tracarnos

Test.o : $(VIEW)Test.cpp $(HPP)App.hpp
	$(CCO)

App.o : $(VIEW)App.cpp $(HPP)App.hpp
	$(CCO)

GameDominos.o : $(VIEW)GameDominos.cpp $(HPP)GameDominos.hpp
	$(CCO)

ManageurEtat.o : $(VIEW)ManageurEtat.cpp $(HPP)ManageurEtat.hpp
	$(CCO)

EndGame.o : $(VIEW)EndGame.cpp $(HPP)EndGame.hpp
	$(CCO)

Menu.o : $(VIEW)Menu.cpp $(HPP)Menu.hpp
	$(CCO)

ParamDominos.o : $(VIEW)ParamDominos.cpp $(HPP)ParamDominos.hpp
	$(CCO)

SpriteDominos.o : $(VIEW)SpriteDominos.cpp $(HPP)SpriteDominos.hpp
	$(CCO)

Controleur.o : $(CTRL)Controleur.cpp $(HPP)Controleur.hpp
	$(CCO)

ControleurTrax.o : $(CTRL)ControleurTrax.cpp $(HPP)ControleurTrax.hpp
	$(CCO)

ControleurCarca.o : $(CTRL)ControleurCarca.cpp $(HPP)ControleurCarca.hpp
	$(CCO)

Dominos.o : $(MODEL)Dominos.cpp $(HPP)Dominos.hpp
	$(CCO)

Joueur.o : $(MODEL)Joueur.cpp $(HPP)Joueur.hpp
	$(CCO)

PlateauDominos.o : $(MODEL)PlateauDominos.cpp $(HPP)PlateauDominos.hpp
	$(CCO)

TuileTrax.o : $(MODEL)TuileTrax.cpp $(HPP)TuileTrax.hpp
	$(CCO)

PlateauTrax.o : $(MODEL)PlateauTrax.cpp $(HPP)PlateauTrax.hpp
	$(CCO)

TuileCarca.o : $(MODEL)TuileCarca.cpp $(HPP)TuileCarca.hpp
	$(CCO)

PlateauCarca.o : $(MODEL)PlateauCarca.cpp $(HPP)PlateauCarca.hpp
	$(CCO)

Terrain.o : $(MODEL)Terrain.cpp $(HPP)Terrain.hpp
	$(CCO)


clean:
	rm -f *.o tracarnos