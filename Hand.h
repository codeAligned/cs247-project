#ifndef _HAND_
#define _HAND_

#include <vector>
#include "Card.h"
#include "Player.h"

class Hand {
public:
    void play();
private:
    vector<Card> hand_;
    vector<Card> discards_;
};

#endif