#ifndef _ROUNDMODEL_
#define _ROUNDMODEL_

#include <vector>
#include "Player.h"
#include "Deck.h"

class RoundModel {
public:
    RoundModel(std::vector<Player*>, Deck*);
    ~RoundModel();
private:
    std::vector<Player*> players_;
    std::vector<Card*> played_cards_;
    Deck* deck_;
};

#endif