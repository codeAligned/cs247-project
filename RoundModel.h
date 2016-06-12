#ifndef _ROUNDCONTROLLER_
#define _ROUNDCONTROLLER_

#include <vector>
#include "RoundModel.h"
#include "Player.h"

class RoundModel {
public:
    RoundModel();
    ~RoundModel();
private:
    std::vector<Player> players_;
    std::vector<Card> played_cards_;
    std::vector<Card> deck_;
};

#endif