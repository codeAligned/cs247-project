#include "Hand.h"
#include <iostream>
using namespace std;

Hand::Hand(){

}
Hand::Hand(Hand& hand){
    cards_ = hand.cards_;
    discards_ = hand.discards_;
}

Hand::~Hand(){
//   for(int i =0;i<cards_.size();i++){
//       delete cards_.at(i);
//   }
//    for(int i =0;i<discards_.size();i++){
//        delete discards_.at(i);
//    }
}
int findLocation(Card c,vector<Card*> list){
    for(int i=0;i<list.size();i++){
        if(list.at(i)->getSuit() == c.getSuit() && list.at(i)->getRank() == c.getRank()){
            return i;
        }
    }
    throw "Card not found";
}

Hand::Hand(vector<Card*> h){
    cards_ = h;
}
void Hand::play(Card c) {
    int loc = findLocation(c,cards_);
    cards_.erase(cards_.begin() + loc);

}
void Hand::discard(Card c) {
    int loc = findLocation(c,cards_);
    discards_.push_back(cards_.at(loc));
    cards_.erase(cards_.begin() + loc);
}

vector<Card*> Hand::getDiscards() {
    return discards_;
}

vector<Card*> Hand::getCards() {
    return cards_;
}