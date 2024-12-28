//
// Created by Bar Kalandarov on 05/01/2023.
//

#ifndef EX4_MAIN_MANA_H
#define EX4_MAIN_MANA_H
#include "Card.h"
const std::string MANA_CARD_NAME = "Mana";
const int MANA_HEAL_AMOUNT = 10;
class Mana : public Card {
public:
    Mana();
    /*
     * If the player's job is Healer, then increase his life by 10;
     * */
    void applyEncounter(Player &player) const override;
    Card* clone() const override;
};

#endif //EX4_MAIN_MANA_H
