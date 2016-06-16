#include "RoundModel.h"

RoundModel::RoundModel(std::vector<Player*> players, Deck* new_deck) {
    deck_ = new_deck;
    players_ = players;
}

RoundModel::~RoundModel() {
    delete deck_;
    // for(int i= 0; i < players_.size(); i++){
    //     delete players_.at(i);
    // }
    for(int i= 0; i < played_cards_.size(); i++){
        delete played_cards_.at(i);
    }
}