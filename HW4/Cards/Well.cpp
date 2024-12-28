//
// Created by Bar Kalandarov on 04/01/2023.
//

#include "Well.h"
#include "../Players/Ninja.h"

Well::Well() : Card(WELL_CARD_NAME){}

void Well::applyEncounter(Player &player) const {
    if (dynamic_cast<Ninja*>(&player) == nullptr) {
        player.damage(WELL_DAMAGE_AMOUNT);
    }
    printWellMessage(dynamic_cast<Ninja*>(&player));
}

Card *Well::clone() const {
    return new Well(*this);
}


