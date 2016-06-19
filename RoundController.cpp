#include <cmath>
#include "RoundController.h"

using namespace std;

RoundController::RoundController(vector<Player*> players, int seed) {
    Deck* new_deck = new Deck(seed);
    new_deck->shuffle();
    model_ = new RoundModel(players, new_deck);
}

RoundController::RoundController(vector<Player*> players, Deck* previous_deck, int seed) {
    previous_deck->shuffle();
    model_ = new RoundModel(players, previous_deck);
}

int RoundController::who7Spades() {
    vector<Player*> players = model_->getPlayers();
    for ( int i=0; i<players.size(); i++ ){
        vector<Card*> tempHand = players.at(i)->getCards();
        for( int j=0; j<tempHand.size() ; j++){
            if(tempHand.at(j)->getRank() == SEVEN && tempHand.at(j)->getSuit() == SPADE){
                return i+1;
            }
        }
    }
}

RoundController::~RoundController(){
    delete model_;
}

int RoundController::getRoundScore(Player* p) {
    int roundScore = 0;
    vector<Card*> discards = p->getDiscards();
    for (int i = 0; i < discards.size(); i++) {
        roundScore += discards.at(i)->getRank()+1;
    }
    return roundScore;
}

void RoundController::updatePlayerScores() {
    vector<Player*> players = model_->getPlayers();
    for (int i = 0; i < players.size(); ++i) {
        int current_score = players.at(i)->getScore();
        int round_score = getRoundScore(players.at(i));
        players.at(i)->setScore(current_score + round_score);
    }
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
            if(played.at(j)->getSuit()==hand.at(i)->getSuit() && abs(played.at(j)->getRank() - hand.at(i)->getRank())<=1 ){
                ret.push_back(hand.at(i));
                break;
            }
            else if(hand.at(i)->getRank()==SEVEN){
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

Command RoundController::playTurn(Player* player) {
    ComputerPlayer* playerTemp = static_cast<ComputerPlayer*>(player);
    return playerTemp->playTurn(this);
}

void RoundController::ragequit(int player_number) {
    Player* p = model_->getPlayer(player_number);
    ComputerPlayer* newPlayer = new ComputerPlayer(*p);
    model_->ragequit(player_number, newPlayer);
}