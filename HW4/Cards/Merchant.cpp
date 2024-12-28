//
// Created by Bar Kalandarov on 04/01/2023.
//

#include "Merchant.h"

Merchant::Merchant() : Card(MERCHANT_CARD_NAME){}

void Merchant::applyEncounter(Player &player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoinsAmount());
    int choice = INVALID_CHOICE;
    std::string input;

    while (choice == INVALID_CHOICE) {
        getline(std::cin, input);
        try {
            choice = std::stoi(input);

            if (choice == HP_TYPE) {
                if (player.getCoinsAmount() >= HP_PRICE) {
                    player.pay(HP_PRICE);
                    player.heal(HP_AMOUNT);
                    printMerchantSummary(std::cout, player.getName(), HP_TYPE, HP_PRICE);
                } else {
                    printMerchantInsufficientCoins(std::cout);
                }
            } else if (choice == FORCE_TYPE) {
                if (player.getCoinsAmount() >= FORCE_PRICE) {
                    player.pay(FORCE_PRICE);
                    player.buff(FORCE_AMOUNT);
                    printMerchantSummary(std::cout, player.getName(), FORCE_TYPE, FORCE_PRICE);
                } else {
                    printMerchantInsufficientCoins(std::cout);
                }
            } else if (choice == SKIP_CHOICE) {
                printMerchantSummary(std::cout, player.getName(), SKIP_CHOICE, 0);
            } else {
                printInvalidInput();
                choice = INVALID_CHOICE;
            }
        } catch (std::exception const &e) {
            printInvalidInput();
            choice = INVALID_CHOICE;
        }
    }

}

Card *Merchant::clone() const {
    return new Merchant(*this);
}


