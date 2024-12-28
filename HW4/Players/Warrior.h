//
// Created by Bar Kalandarov on 04/01/2023.
//

#ifndef EX4_MAIN_WARRIOR_H
#define EX4_MAIN_WARRIOR_H
#include "Player.h"
const std::string WARRIOR_TYPE = "Warrior";

class Warrior : public Player {
public:
    explicit Warrior(std::string name);
    int getAttackStrength() const override;
    std::string getType() const override;
    Player* clone() const override;
};
#endif //EX4_MAIN_WARRIOR_H
