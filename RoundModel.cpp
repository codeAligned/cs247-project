#include "RoundModel.h"

RoundModel::RoundModel(std::vector<Player*> players) {
    deck_ = Deck();
    players_ = players;
}

RoundModel::~RoundModel() {
    for(int i= 0; i < players_.size(); i++){
        delete players_.at(i);
    }
    for(int i= 0; i < played_cards_.size(); i++){
        delete played_cards_.at(i);
    }
}