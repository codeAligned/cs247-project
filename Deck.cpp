#include "Deck.h"
using namespace std;

Deck::Deck() {
    for(int i = 0; i < SUIT_COUNT; i++) {
        for(int j = 0; j < RANK_COUNT; j++) {
            cards_.push_back( Card( static_cast<Suit>(i), static_cast<Rank>(j) ) );
        }
    }
}

ostream& operator<<(ostream& os, const Deck &d) {
    for(int i = 0; i < d.cards_.size(); i++) {
        cout << d.cards_.at(i); // Fix this later.
    }
}