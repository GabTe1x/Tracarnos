CPP := g++ -Wall -std=c++11

BIN		:= bin
SRC		:= src
HPP		:= src/hpp 

LIBRAIRIES	:= -lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE	:= main

MKDIR_P = mkdir -p

.PHONY: directories

all: directories $(BIN)/$(EXECUTABLE)

directories: ${BIN}

${BIN}:
	${MKDIR_P} ${BIN}

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/cpp/*.cpp
	$(CPP) -I$(HPP) $^ -o $@ $(LIBRAIRIES)

clean:
	-rm $(BIN)/*