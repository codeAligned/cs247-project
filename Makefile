CXX = g++
CXXFLAGS = -std=c++11 -Wall -O  -g `pkg-config gtkmm-2.4 --cflags --libs` -MMD #builds dependency list in .d files
OBJECTS = Card.o Deck.o deck_window.o Command.o Hand.o Player.o HumanPlayer.o ComputerPlayer.o RoundModel.o \
RoundController.o RoundView.o Game.o main.cpp
DEPENDS = ${OBJECTS:.o=.d} # substitute ".o" with ".d"
EXEC=straights

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean:
	rm -fr ${DEPENDS} ${OBJECTS} ${EXEC}

-include {DEPENDS} # reads the .d files and reruns dependencies
