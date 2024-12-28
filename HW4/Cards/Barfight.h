//
// Created by Bar Kalandarov on 05/01/2023.
//

#ifndef EX4_MAIN_BARFIGHT_H
#define EX4_MAIN_BARFIGHT_H
#include "Card.h"
const std::string BARFIGHT_CARD_NAME = "Barfight";
const int BARFIGHT_DAMAGE = 10;

class Barfight : public Card {
public:
    Barfight();
    /*
     * Decreases the player's HP by 10, except Warriors players.
     * */
    void applyEncounter(Player &player) const override;
    Card* clone() const override;
};

#endif //EX4_MAIN_BARFIGHT_H
