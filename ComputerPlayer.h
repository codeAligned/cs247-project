#ifndef _COMPUTERPLAYER_
#define _COMPUTERPLAYER_

class RoundController;
class Player;
#include <vector>
//#include "Player.h"

class ComputerPlayer: public Player {
public:
    ComputerPlayer();
    // ComputerPlayer(Player);
    void playTurn(RoundController*);
    bool isHuman() const;
private:
};

#endif
