//
// Created by Bar Kalandarov on 04/01/2023.
//

#ifndef EX4_MAIN_WELL_H
#define EX4_MAIN_WELL_H

#include "Card.h"
const std::string WELL_CARD_NAME = "Well";
const int WELL_DAMAGE_AMOUNT = 10;

class Well : public Card {
public:
    Well();

    /*
     * Decreases the given player HP by 10, expect for Ninjas.
     */
    void applyEncounter(Player &player) const override;

    Card* clone() const override;
};

#endif //EX4_MAIN_WELL_H
