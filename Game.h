#ifndef _GAME_
#define _GAME_

#include <iostream>
#include "Player.h"
#include "Deck.h"
#include "RoundView.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class Game {
public:
    Game();
    ~Game();
    void checkGameOver();
private:
    void createPlayers();
    static const int NUM_PLAYERS=4;
    RoundView* round_view_;
    std::vector<Player*> players_;
};

#endif
