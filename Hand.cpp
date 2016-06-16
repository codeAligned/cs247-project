#include "Hand.h"
using namespace std;

void Hand::play(Card) {}
void Hand::discard(Card) {}

vector<Card*> Hand::getDiscards() {
    return discards_;
}

vector<Card*> Hand::getCards() {
    return cards_;
}