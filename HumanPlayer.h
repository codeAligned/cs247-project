#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_

#include <vector>
#include "Player.h"

class HumanPlayer: public Player {
public:
    // HumanPlayer(Player);
    HumanPlayer();
    // void playTurn();
    virtual bool isHuman();
private:

};

#endif
