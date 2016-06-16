#include "RoundController.h"
using namespace std;

RoundController::RoundController(vector<Player*> players) {
    Deck* new_deck = new Deck();
    new_deck->shuffle();
    model_ = new RoundModel(players, new_deck);
}

int RoundController::who7Spades() {
    return 1;
    // implement this
}

RoundController::~RoundController(){
    delete model_;
}