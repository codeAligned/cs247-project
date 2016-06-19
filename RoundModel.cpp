#include "RoundModel.h"
using namespace std;
RoundModel::RoundModel(std::vector<Player*> players, Deck* new_deck) {
    deck_ = new_deck;

    vector<Hand*> hands = new_deck->dealCards();
//    cout<<hands.size();
    for(int i=0;i<hands.size();i++){
        players.at(i)->setHand(hands.at(i));
    }
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

vector<Player*> RoundModel::getPlayers(){
    return players_;
}

Player* RoundModel::getPlayer(int playerID){
    return players_.at(playerID-1);
}

Deck* RoundModel::getDeck() const{
    return deck_;
}

void RoundModel::playCard(Card c) {
    //TODO should use copy constructor
    Card* newCard = new Card(c.getSuit(),c.getRank());
    played_cards_.push_back(newCard);
}

vector<Card*> RoundModel::getPlayedCards() const{
    return played_cards_;
}

void RoundModel::ragequit(int playerID, Player* newPlayer) {
    playerID--;
    Player* temp = players_.at(playerID);
    players_.at(playerID) = newPlayer;
    delete temp;
}