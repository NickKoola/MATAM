//
// Created by Bar Kalandarov on 04/01/2023.
//
#include <iostream>
#include "../Mtmchkin.h"
const int MAX_ROUNDS = 100;
const std::string DECK_PATH = "deck.txt";


int main () {
    try {
        Mtmchkin game(DECK_PATH);
        while (!game.isGameOver() && game.getNumberOfRounds() < MAX_ROUNDS) {
            game.playRound();
        }

        game.printLeaderBoard();
    } catch(const std::exception& e) {
        cout << e.what();
        return 0;
    }
}
