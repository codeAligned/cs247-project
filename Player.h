#ifndef _PLAYER_
#define _PLAYER_

#include <vector>
#include "Card.h"
#include "Hand.h"
#include "Command.h"

class RoundController;

class Player {
public:
    Player();
    Player(Hand*);
   ~Player();
    virtual bool isHuman() const = 0;
    void deleteHand();
    std::vector<Card*> getDiscards();
    std::vector<Card*> getCards();
    std::vector<Card*> getClubs();
    std::vector<Card*> getDiamonds();
    std::vector<Card*> getHearts();
    std::vector<Card*> getSpades();
    void discardCards(Card);
    void playCard(Card);
    void setHand(Hand*);
    void setScore(int);
    Hand* getHand() const;
    int getScore() const;
    //TODO virtual void playTurn(RoundController*);
    virtual Command playTurn(RoundController*);
protected:
    std::vector<Card*> filterBySuit(Suit);
    Hand* hand_;
    int gameScore_;
};


#endif