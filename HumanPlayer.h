//
// Created by sam on 2016-06-12.
//

#ifndef _COMPUTERPLAYER_
#define _COMPUTERPLAYER_

#include <vector>
#include "Player.h"

class HumanPlayer: public Player {
public:
    HumanPlayer(Player);
    void playTurn();
    virtual bool isHuman();
private:

};

#endif
