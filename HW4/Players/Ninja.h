//
// Created by Bar Kalandarov on 03/01/2023.
//

#ifndef EX4_MAIN_NINJA_H
#define EX4_MAIN_NINJA_H
#include "Player.h"
const std::string NINJA_TYPE = "Ninja";

class Ninja : public Player {
public:
    explicit Ninja(std::string name);
    void addCoins(int coinsRecieved) override;
    std::string getType() const override;
    Player* clone() const override;
};
#endif //EX4_MAIN_NINJA_H
