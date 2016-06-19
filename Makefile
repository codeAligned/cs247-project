CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -MMD #builds dependency list in .d files
OBJECTS = Card.o Command.o Hand.o Player.o HumanPlayer.o ComputerPlayer.o Deck.o RoundModel.o \
RoundController.o RoundView.o Game.o main.cpp
DEPENDS = ${OBJECTS:.o=.d} # substitute ".o" with ".d"
EXEC=straights

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean:
	rm -fr ${DEPENDS} ${OBJECTS} ${EXEC}

-include {DEPENDS} # reads the .d files and reruns dependencies
