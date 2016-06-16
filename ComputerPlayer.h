#ifndef _COMPUTERPLAYER_
#define _COMPUTERPLAYER_

#include <vector>
#include "Player.h"

class ComputerPlayer: public Player {
public:
    ComputerPlayer();
    // ComputerPlayer(Player);
    // void playTurn();
    bool isHuman();
private:
};

#endif
