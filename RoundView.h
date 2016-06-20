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
    void printDeck(Deck*) const;
    void printNewRound(int) const;
    void printPlayerScore(std::vector<Card*>, int, int, int) const;
    void printPlayMessage(int, Card) const;
    void printDiscardMessage(int, Card) const;
    void printRageQuitMessage(int) const;
    void printIllegalPlay() const;
    void printBadDiscard() const;
    void printHumanInfo(std::vector<Card*>, std::vector<Card*>, std::vector<Card*>,
                        std::vector<Card*>, std::vector<Card*>, std::vector<Card*>) const;
private:
    void printCardList(std::vector<Card*>) const;
    void printCardRank(std::vector<Card*>) const;
};

#endif