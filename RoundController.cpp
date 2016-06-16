#include "RoundController.h"
using namespace std;

RoundController::RoundController(vector<Player*> players) {
    model_ = new RoundModel(players);
}

RoundController::~RoundController(){
    delete model_;
}