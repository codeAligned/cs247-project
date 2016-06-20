#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_

#include <vector>
#include "Player.h"

class HumanPlayer: public Player {
public:
    HumanPlayer();
    bool isHuman() const;
private:

};

#endif
