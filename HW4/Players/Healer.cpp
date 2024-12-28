//
// Created by Bar Kalandarov on 03/01/2023.
//

#include "Healer.h"

void Healer::heal(int healAmount) {
    Player::heal(healAmount*2);

}

Healer::Healer(std::string name) : Player(name) {}

std::string Healer::getType() const {
    return HEALER_TYPE;
}

Player *Healer::clone() const {
    return new Healer(*this);
}
