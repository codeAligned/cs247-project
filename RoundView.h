#ifndef _ROUNDVIEW_
#define _ROUNDVIEW_

#include <vector>
#include <iostream>
#include "RoundController.h"
#include "Command.h"

class RoundView {
public:
    RoundView(std::vector<Player*>);
    ~RoundView();
    void printDeck();
    void startTurns(int);
private:
    RoundController* controller_;
    void printClubs(Player*);
    void printDiamonds(Player*);
    void printHearts(Player*);
    void printSpades(Player*);
    void printHand(Player*);
    Command getCommand(int*);
    void executeCommand(Command,int*);
    void turnLoop(int);
};

#endif