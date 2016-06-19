#ifndef _ROUNDVIEW_
#define _ROUNDVIEW_

#include <vector>
#include <iostream>
#include "Player.h"
#include "Command.h"

class RoundView {
public:
    RoundView(int);
    ~RoundView();
    void printDeck();
private:
    void printClubs();
    void printDiamonds();
    void printHearts();
    void printSpades();
    void printDiscards(Player*);
    void printScores();
    void printHand(Player*);
    void printLegalPlays(Player*);
    Command getCommand();
    void executeCommand(Command, int &);
    void turnLoop(int &);
    void startTurns(int &);
    void startRoundLoop(int &);
};

#endif