#ifndef _GAME_
#define _GAME_

#include <iostream>
#include "Deck.h"
#include "RoundController.h"

class Game {
public:
    Game(int seed = 0);
    ~Game();
    void displayWinner();
    bool gameOver();
private:
    void createPlayers();
    static const int NUM_PLAYERS=4;
    RoundController* round_controller_;
    std::vector<Player*> players_;
};

#endif
