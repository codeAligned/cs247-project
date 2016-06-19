#include "Game.h"

using namespace std;

Game::Game() {
    createPlayers();
    while (!gameOver()) {
        round_views_.push_back(new RoundView(players_));
    }
    displayWinner();
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
    for(int i= 0; i < players_.size(); ++i){
        delete players_.at(i);
    }
    for (int i = 0; i < round_views_.size(); ++i) {
        delete round_views_.at(i);
    }
}

//iterate over players, check score over 80 for any. If so, game over.
bool Game::gameOver() {
    for(int i= 0; i < players_.size(); ++i) {
        if (players_.at(i)->getScore() > 80) {
            return true;
        }
    }
    return false;
}

void Game::displayWinner() {
    int winner = 0;
    int min_score = players_.at(0)->getScore();
    for (int i = 0; i < players_.size(); ++i) {
        if (players_.at(i)->getScore() < min_score) {
            min_score = players_.at(i)->getScore();
            winner = i;
        }
    }
    cout << "Player " << winner+1 << " wins!" << endl;
}