#include "Game.h"

using namespace std;

Game::Game() {
    createPlayers();
    round_view_ = new RoundView(players_);
}

void Game::createPlayers() {
    for (int i = 1; i <= NUM_PLAYERS; i++) {
        char playerType;
        cout << "Is player " << i << " a human(h) or a computer(c)?" << endl << ">";
        cin >> playerType;
        if (playerType == 'c') {
            players_.push_back( new ComputerPlayer() );
        }
        else if (playerType == 'h'){
            players_.push_back( new HumanPlayer() );
        }
        else {
            throw "Response not c or h";
        }
    }
}

Game::~Game() {
    for(int i= 0; i < players_.size(); i++){
        delete players_.at(i);
    }
    delete round_view_;
}

void Game::checkGameOver() {
    //iterate over players, check score over 80 for any. If so, game over.
}