#include "Player.h"

Player::Player() {}
Player::~Player() {}

std::vector<Card*> Player::getDiscards() {
    return hand_.getDiscards();
}

std::vector<Card*> Player::getCards() {
    return hand_.getCards();
}

bool Player::isHuman() {
    throw "wtf";
}