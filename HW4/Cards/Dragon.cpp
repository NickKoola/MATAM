//
// Created by Bar Kalandarov on 05/01/2023.
//

#include "Dragon.h"

Dragon::Dragon() : BattleCard(DRAGON_FORCE, DRAGON_LOOT, DRAGON_DAMAGE, DRAGON_CARD_NAME, DRAGON_FORCE_DAMAGE) {}

Card *Dragon::clone() const {
    return new Dragon(*this);
}
