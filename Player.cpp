#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {}

Player::Player(Hand* h) {
    hand_ = h;
}

Player::~Player() {
    delete hand_;
}

void Player::playCard(Card c){
    hand_->play(c);
}

void Player::discardCards(Card c){
    cout<<"Discarding "<<c<<endl;
    hand_->discard(c);
}

vector<Card*> Player::getDiscards() {
    return hand_->getDiscards();
}

vector<Card*> Player::getCards() {
    return hand_->getCards();
}

vector<Card*> Player::getClubs() {
    return filterBySuit(static_cast<Suit>(0));
}
vector<Card*> Player::getDiamonds() {
    return filterBySuit(static_cast<Suit>(1));
}
vector<Card*> Player::getHearts() {
    return filterBySuit(static_cast<Suit>(2));
}
vector<Card*> Player::getSpades() {
    return filterBySuit(static_cast<Suit>(3));
}

vector<Card*> Player::filterBySuit(Suit suit){
    vector<Card*> temp = hand_->getCards();
    vector<Card*> ret = vector<Card*>();
    for(int i = 0; i<temp.size(); i++ ){
        if(temp.at(i)->getSuit() == suit){
            ret.push_back(temp.at(i));
        }
    }
    return ret;
}

void Player::setHand(Hand* hand){
    hand_ = hand;
}

Command Player::playTurn(RoundController* controller){
    throw "Parent has no specified behaviour";
}