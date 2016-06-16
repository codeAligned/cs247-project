#ifndef _PLAYER_
#define _PLAYER_

#include <vector>
#include "Card.h"
#include "Hand.h"

class Player {
public:
    Player();
    Player(Hand*);
   ~Player();
    virtual bool isHuman();
    std::vector<Card*> getDiscards();
    std::vector<Card*> getCards();
    void discardCards(Card);
    void playCard(Card);
    void setHand(Hand*);
    //virtual void playTurn();
private:
    Hand* hand_;
    int gameScore_;
};


#endif