#include "Player.h"

Player::Player() {}

Player::Player(Hand* h) {
    hand_ = h;
}

Player::~Player() {}

std::vector<Card*> Player::getDiscards() {
    return hand_->getDiscards();
}

std::vector<Card*> Player::getCards() {
    return hand_->getCards();
}

void Player::setHand(Hand* hand){
    hand_ = hand;
}

bool Player::isHuman() {
    throw "undefined";
}