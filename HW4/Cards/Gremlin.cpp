//
// Created by Bar Kalandarov on 04/01/2023.
//

#include "Gremlin.h"

Gremlin::Gremlin() : BattleCard(GREMLIN_FORCE, GREMLIN_LOOT, GREMLIN_DAMAGE, GREMLIN_CARD_NAME, GREMLIN_FORCE_DAMAGE) {}

Card *Gremlin::clone() const {
    return new Gremlin(*this);
}


