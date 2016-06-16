#ifndef _DECK_
#define _DECK_

#include <iostream>
#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();
    friend std::ostream& operator<<(std::ostream&, const Deck &);
private:
    std::vector<Card> cards_;
};

#endif