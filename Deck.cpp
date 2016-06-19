#include <random>
#include "Deck.h"

using namespace std;

int seed = 0;

Deck::Deck() {
    for(int i = 0; i < SUIT_COUNT; i++) {
        for(int j = 0; j < RANK_COUNT; j++) {
            cards_.push_back( new Card( static_cast<Suit>(i), static_cast<Rank>(j) ) );
        }
    }
}

Deck::Deck(int seedIn) {
    for(int i = 0; i < SUIT_COUNT; i++) {
        for(int j = 0; j < RANK_COUNT; j++) {
            cards_.push_back( new Card( static_cast<Suit>(i), static_cast<Rank>(j) ) );
        }
    }
    seed = seedIn;
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

Card* Deck::at(int index){
    return cards_.at(index);
}

void Deck::shuffle(){
    static std::mt19937 rng(seed);

    int n = CARD_COUNT;

    while ( n > 1 ) {
        int k = (int) (rng() % n);
        --n;
        Card *c = cards_[n];
        cards_[n] = cards_[k];
        cards_[k] = c;
    }
}