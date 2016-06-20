#ifndef _ROUNDVIEW_
#define _ROUNDVIEW_

#include <cstdlib>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Command.h"
#include "Deck.h"

class RoundView {
public:
    RoundView(int);
    void printDeck(Deck*);
    void printNewRound(int);
    Command getCommand();
    void printPlayerScore(std::vector<Card*>, int, int, int);
    void printPlayMessage(int, Card);
    void printDiscardMessage(int, Card);
    void printIllegalPlay();
    void printBadDiscard();
    void printHumanInfo(std::vector<Card*>, std::vector<Card*>, std::vector<Card*>,
                        std::vector<Card*>, std::vector<Card*>, std::vector<Card*>);
private:
    void printCardList(std::vector<Card*>);
    void printCardRank(std::vector<Card*>);
};

#endif