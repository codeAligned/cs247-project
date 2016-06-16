#ifndef _DECK_
#define _DECK_

#include <iostream>
#include <vector>
#include "Card.h"
#include "Hand.h"

class Deck {
public:
    Deck();
    ~Deck();
    void shuffle();
    friend std::ostream& operator<<(std::ostream&, const Deck &);
    std::vector<Hand*> dealCards();
private:
    std::vector<Card*> cards_;
};

#endif