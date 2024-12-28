//
// Created by Bar Kalandarov on 16/01/2023.
//
#include "Mtmchkin.h"
int main () {

    Player* p1 = new Ninja("Bar");
    std::cout << p1->getCoinsAmount() << endl;

    Player* p2 = p1;
    p2->pay(2);
    std::cout << p1->getCoinsAmount();
}