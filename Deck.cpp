#include "Deck.h"
#include "shuffle.cpp"
using namespace std;

Deck::Deck() {
    for(int i = 0; i < SUIT_COUNT; i++) {
        for(int j = 0; j < RANK_COUNT; j++) {
            cards_.push_back( new Card( static_cast<Suit>(i), static_cast<Rank>(j) ) );
        }
    }
}

Deck::~Deck() {
    for(int i = 0; i < cards_.size(); i++) {
        delete cards_.at(i);
    }
}

ostream& operator<<(ostream& os, const Deck &d) {
    for(int i = 0; i < d.cards_.size(); i++) {
        cout << d.cards_.at(i); // Fix this later.
    }
}

vector<Hand*> Deck::dealCards(){
    vector<Hand*> hands = vector<Hand*>();
    for( int i=0;i<4;i++){
        vector<Card*> temp = vector<Card*>();
        for(int j=0;j<13;j++){
            temp.push_back(cards_.at(13*i+j));
        }
        hands.push_back(new Hand(temp));
    }
    return hands;
}