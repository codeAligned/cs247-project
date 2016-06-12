//
// Created by sam on 2016-06-12.
//

#ifndef _COMPUTERPLAYER_
#define _COMPUTERPLAYER_

#include <vector>
#include "Player.h"

class ComputerPlayer: public Player {
public:
    ComputerPlayer(Player);
    void playTurn();
    bool isHuman();
private:
};

#endif
