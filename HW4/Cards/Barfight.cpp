//
// Created by Bar Kalandarov on 05/01/2023.
//

#include "Barfight.h"
#include "../Players/Warrior.h"

Barfight::Barfight() : Card(BARFIGHT_CARD_NAME) {}

void Barfight::applyEncounter(Player &player) const {
    if (dynamic_cast<Warrior*>(&player) == nullptr) {
        player.damage(BARFIGHT_DAMAGE);
    }
    printBarfightMessage(dynamic_cast<Warrior*>(&player));
}

Card *Barfight::clone() const {
    return new Barfight(*this);
}


