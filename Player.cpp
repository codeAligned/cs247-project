#include "Player.h"

using namespace std;

Player::Player() {}

Player::Player(Hand* h) {
    hand_ = h;
}

Player::~Player() {
    delete hand_;
}

std::vector<Card*> Player::getDiscards() {
    return hand_->getDiscards();
}

std::vector<Card*> Player::getCards() {
    return hand_->getCards();
}

std::vector<Card*> Player::getClubs() {
    return filterBySuit(static_cast<Suit>(0));
}
std::vector<Card*> Player::getDiamonds() {
    return filterBySuit(static_cast<Suit>(1));
}
std::vector<Card*> Player::getHearts() {
    return filterBySuit(static_cast<Suit>(2));
}
std::vector<Card*> Player::getSpades() {
    return filterBySuit(static_cast<Suit>(3));
}

std::vector<Card*> Player::filterBySuit(Suit suit){
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

bool Player::isHuman() {
    throw "undefined";
}