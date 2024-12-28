//
// Created by Bar Kalandarov on 04/01/2023.
//

#ifndef EX4_MAIN_MERCHANT_H
#define EX4_MAIN_MERCHANT_H
#include "Card.h"
const std::string MERCHANT_CARD_NAME = "Merchant";
const int INVALID_CHOICE = -1;
const int SKIP_CHOICE = 0;
const int HP_TYPE = 1;
const int HP_PRICE = 5;
const int HP_AMOUNT = 1;

const int FORCE_TYPE = 2;
const int FORCE_PRICE = 10;
const int FORCE_AMOUNT = 1;


class Merchant : public Card {
public:
    Merchant();
    /*
     * Allows the player to buy HP bonus or force bonus.
     * */
    void applyEncounter(Player &player) const override;
    Card* clone() const override;
};

#endif //EX4_MAIN_MERCHANT_H
