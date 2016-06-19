#ifndef _ROUNDVIEW_
#define _ROUNDVIEW_

#include <vector>
#include <iostream>
#include "RoundController.h"
#include "Command.h"

class RoundView {
public:
    RoundView(std::vector<Player*>, int seed =0);
    ~RoundView();
    void printDeck();
    void startTurns(int &);
private:
    RoundController* controller_;
    void printClubs(Player*);
    void printDiamonds(Player*);
    void printHearts(Player*);
    void printSpades(Player*);
    void printDiscards(Player*);
    void printScores(int &);
    void printHand(Player*);
    void printLegalPlays(Player*);
    Command getCommand();
    void executeCommand(Command, int &);
    void turnLoop(int &);
    void startRoundLoop(int &);
};

#endif