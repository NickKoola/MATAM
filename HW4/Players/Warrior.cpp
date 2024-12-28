//
// Created by Bar Kalandarov on 04/01/2023.
//

#include "Warrior.h"


int Warrior::getAttackStrength() const {
    return m_force*2 + getLevel();
}

Warrior::Warrior(const std::string name) : Player(name) {}

std::string Warrior::getType() const {
    return WARRIOR_TYPE;
}

Player *Warrior::clone() const {
    return new Warrior(*this);
}
