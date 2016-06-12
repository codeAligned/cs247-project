//
// Created by sam on 2016-06-12.
//

#ifndef _PLAYER_
#define _PLAYER_

#include <vector>
#include "Card.h"

class Player {
public:
    Player();
    ~Player();
    std::vector<Card> getDiscard();
    virtual bool isHuman();
    std::vector<Card> getCards();
    void discardCard(Card);
    void playCard(Card);
    virtual void playTurn();
private:
    Hand hand_;
    int gameScore_;

};


#endif
