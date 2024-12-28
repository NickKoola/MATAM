//
// Created by Bar Kalandarov on 05/01/2023.
//

#ifndef EX4_MAIN_WITCH_H
#define EX4_MAIN_WITCH_H
#include "BattleCard.h"

const std::string WITCH_CARD_NAME = "Witch";
const int WITCH_FORCE = 11;
const int WITCH_LOOT = 2;
const int WITCH_DAMAGE = 10;
const int WITCH_FORCE_DAMAGE = 1;

class Witch : public BattleCard {
public:
    Witch();
    Card* clone() const override;
};
#endif //EX4_MAIN_WITCH_H
