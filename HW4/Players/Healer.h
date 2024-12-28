//
// Created by Bar Kalandarov on 03/01/2023.
//

#ifndef EX4_MAIN_HEALER_H
#define EX4_MAIN_HEALER_H
#include "Player.h"

const std::string HEALER_TYPE = "Healer";

class Healer : public Player {
public:
    explicit Healer(std::string name);
    void heal(int healAmount) override;
    std::string getType() const override;
    Player* clone() const override;

};
#endif //EX4_MAIN_HEALER_H
