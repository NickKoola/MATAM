//
// Created by Bar Kalandarov on 04/01/2023.
//

#ifndef EX4_MAIN_BATTLECARD_H
#define EX4_MAIN_BATTLECARD_H
#include "Card.h"

class BattleCard : public Card {
    int m_force;
    int m_loot;
    int m_damage;
    int m_forceDamage;

public:
    BattleCard(int force, int loot, int damage, std::string name, int forceDamage);
    void applyEncounter(Player &player) const override;
    void toString(std::ostream &os) const override;
};

#endif //EX4_MAIN_BATTLECARD_H
