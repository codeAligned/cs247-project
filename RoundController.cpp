#include <cmath>
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

void RoundController::playCard(Player* p, Card c){
    model_->playCard(c);
    p->playCard(c);
}

void RoundController::discardCard(Player* p, Card c){
    p->discardCards(c);
}

vector<Card*> RoundController::calculateLegalPlay(Player* p) const{
    vector<Card*> played = model_->getPlayedCards();
    vector<Card*> hand = p->getCards();
    vector<Card*> ret = vector<Card*>();


    if(model_->getPlayedCards().size() == 0){
        for( int i=0;i<hand.size();i++ ){
            if(hand.at(i)->getSuit()== SPADE && hand.at(i)->getRank() == SEVEN){
                ret.push_back(hand.at(i));
                return ret;
            }
        }
    }

    for( int i=0;i<hand.size();i++ ){
        for( int j=0; j<played.size();j++){
            if(played.at(j)->getSuit()==hand.at(i)->getSuit() && abs(played.at(j)->getRank() - hand.at(i)->getRank())==1 ){
                ret.push_back(hand.at(i));
                break;
            }
        }
    }
    return ret;
}

bool RoundController::isLegalPlay(Player* p, Card c) const{
    vector<Card*> legal_plays = calculateLegalPlay(p);
    for (int i = 0; i < legal_plays.size(); i++) {
        if (c == *(legal_plays.at(i)) )
            return true;
    }
    return false;
}