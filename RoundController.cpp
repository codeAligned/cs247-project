#include "RoundController.h"
using namespace std;

RoundController::RoundController(vector<Player*> players) {
    Deck* new_deck = new Deck();
    new_deck->shuffle();
    model_ = new RoundModel(players, new_deck);
}

int RoundController::who7Spades() {
    vector<Player*> players = model_->getPlayers();
    for ( int i=0; i<players.size(); i++ ){
        vector<Card*> tempHand = players.at(i)->getCards();
        for( int j=0; j<tempHand.size() ; j++){
            if(tempHand.at(j)->getRank() == static_cast<Rank>(6) && tempHand.at(j)->getSuit() == static_cast<Suit>(3)){
                return i+1;
            }
        }
    }

    return -1;
    // implement this
}

RoundController::~RoundController(){
    delete model_;
}

Player* RoundController::getPlayer(int playerID){
    return model_->getPlayer(playerID);
}

Deck* RoundController::getDeck() const{
    return model_->getDeck();
}