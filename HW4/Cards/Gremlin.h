//
// Created by Bar Kalandarov on 04/01/2023.
//

#ifndef EX4_MAIN_GREMLIN_H
#define EX4_MAIN_GREMLIN_H
#include "BattleCard.h"
const std::string GREMLIN_CARD_NAME = "Gremlin";
const int GREMLIN_FORCE = 5;
const int GREMLIN_LOOT = 2;
const int GREMLIN_DAMAGE = 10;
const int GREMLIN_FORCE_DAMAGE = 0;

class Gremlin : public BattleCard {
public:
    Gremlin();
    Card* clone() const override;
};

#endif //EX4_MAIN_GREMLIN_H
