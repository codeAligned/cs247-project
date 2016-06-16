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
    std::vector<Card*> getClubs();
    std::vector<Card*> getDiamonds();
    std::vector<Card*> getHearts();
    std::vector<Card*> getSpades();
    void discardCards(Card);
    void playCard(Card);
    void setHand(Hand*);
    //virtual void playTurn();
private:
    std::vector<Card*> filterBySuit(Suit);
    Hand* hand_;
    int gameScore_;
};


#endif