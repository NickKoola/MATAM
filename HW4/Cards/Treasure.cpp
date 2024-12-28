//
// Created by Bar Kalandarov on 04/01/2023.
//

#include "Treasure.h"

void Treasure::applyEncounter(Player &player) const {
    player.addCoins(TREASURE_COINS_AMOUNT);
    printTreasureMessage();
}

Treasure::Treasure() : Card(TREASURE_CARD_NAME) {}

Card *Treasure::clone() const {
    return new Treasure(*this);
}
