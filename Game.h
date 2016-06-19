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
    void displayWinner();
    bool gameOver();
private:
    void createPlayers();
    static const int NUM_PLAYERS=4;
    std::vector<RoundView*> round_views_;
    std::vector<Player*> players_;
};

#endif
