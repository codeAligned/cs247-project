#ifndef _ROUNDVIEW_
#define _ROUNDVIEW_

#include <vector>
#include <iostream>
#include "RoundController.h"
#include "Command.h"

class RoundView {
public:
    RoundView(std::vector<Player*>, int seed =0);
    void startRound();
    ~RoundView();
    void printDeck();
private:
    RoundController* controller_;
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