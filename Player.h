#ifndef _PLAYER_
#define _PLAYER_

#include <vector>
#include "Card.h"
#include "Hand.h"
//#include "RoundController.h"

class Player {
public:
    Player();
    Player(Hand*);
   ~Player();
    virtual bool isHuman() const = 0;
    std::vector<Card*> getDiscards();
    std::vector<Card*> getCards();
    std::vector<Card*> getClubs();
    std::vector<Card*> getDiamonds();
    std::vector<Card*> getHearts();
    std::vector<Card*> getSpades();
    void discardCards(Card);
    void playCard(Card);
    void setHand(Hand*);
    //TODO virtual void playTurn(RoundController*);
//    void playTurn(RoundController*);
protected:
    std::vector<Card*> filterBySuit(Suit);
    Hand* hand_;
    int gameScore_;
};


#endif