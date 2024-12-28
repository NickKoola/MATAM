//
// Created by Bar Kalandarov on 05/01/2023.
//

#include "Mana.h"
#include "../Players/Healer.h"

Mana::Mana() : Card(MANA_CARD_NAME) {}

void Mana::applyEncounter(Player &player) const {
    if (dynamic_cast<Healer*>(&player)) {
        player.heal(MANA_HEAL_AMOUNT);
    }
    printManaMessage(dynamic_cast<Healer*>(&player));
}

Card *Mana::clone() const {
    return new Mana(*this);
}
