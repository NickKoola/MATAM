//
// Created by Bar Kalandarov on 05/01/2023.
//

#include "Witch.h"

Witch::Witch() : BattleCard(WITCH_FORCE, WITCH_LOOT, WITCH_DAMAGE, WITCH_CARD_NAME, WITCH_FORCE_DAMAGE) {}

Card *Witch::clone() const {
    return new Witch(*this);
}
