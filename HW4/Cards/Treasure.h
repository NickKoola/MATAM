//
// Created by Bar Kalandarov on 04/01/2023.
//

#ifndef EX4_MAIN_TREASURE_H
#define EX4_MAIN_TREASURE_H

#include "Card.h"
const std::string TREASURE_CARD_NAME = "Treasure";
const int TREASURE_COINS_AMOUNT = 10;

class Treasure : public Card {
public:
    Treasure();
    /*
     * Gives the given player 10 coins.
     */
    void applyEncounter(Player &player) const override;
    Card* clone() const override;
};
#endif //EX4_MAIN_TREASURE_H
