//
// Created by Bar Kalandarov on 03/01/2023.
//

#include "Ninja.h"

void Ninja::addCoins(int coinsRecieved) {
    Player::addCoins(coinsRecieved*2);
}

Ninja::Ninja(std::string name) : Player(name) {}

std::string Ninja::getType() const {
    return NINJA_TYPE;
}

Player *Ninja::clone() const {
    return new Ninja(*this);
}
