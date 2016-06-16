#include "Hand.h"
using namespace std;

Hand::Hand(){

}

Hand::~Hand(){
    for(int i =0;i<cards_.size();i++){
        delete cards_.at(i);
    }
    for(int i =0;i<discards_.size();i++){
        delete discards_.at(i);
    }
}

Hand::Hand(vector<Card*> h){
    cards_ = h;
}
void Hand::play(Card) {}
void Hand::discard(Card) {}

vector<Card*> Hand::getDiscards() {
    return discards_;
}

vector<Card*> Hand::getCards() {
    return cards_;
}