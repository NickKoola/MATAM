//
// Created by Bar Kalandarov on 05/01/2023.
//

#ifndef EX4_MAIN_DRAGON_H
#define EX4_MAIN_DRAGON_H

#include "BattleCard.h"
const std::string DRAGON_CARD_NAME = "Dragon";
const int DRAGON_FORCE = 25;
const int DRAGON_LOOT = 1000;
const int DRAGON_DAMAGE = 100;
const int DRAGON_FORCE_DAMAGE = 0;

class Dragon : public BattleCard {
public:
    Dragon();
    Card* clone() const override;
};

#endif //EX4_MAIN_DRAGON_H
