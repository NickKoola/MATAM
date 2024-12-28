#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "utilities.h"

const int DEFAULT_FORCE = 5;
const int DEFAULT_MAX_HP = 100;
const int STARTING_LEVEL = 1;
const int STARTING_COINS = 0;
const int MAX_LEVEL = 10;

class Player{
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_hp;
    int m_coins;

public:
    /*
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @param maxHP - The maximum health points of the player.
     * @param force - The force of the player.
     * @return
     *      A new instance of Player.
    */
    Player(std::string name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE); 

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player(const Player& other) = default;
    ~Player() = default; 
    Player& operator=(const Player& player) = default;

    /*
     * Prints the player info:
     *
     * @return
     *      void
    */
    void printInfo();

    /*
     * Increases the player's level by 1:
     *
     * @return
     *      void
     */
    void levelUp();

    /*
     * Gets the player's level:
     *
     * @return
     *      player's level
     */
    int getLevel() const;

    /*
     * Increases player's force by a given number.
     * Player's force doesn't change if received number is negative.
     *
     * @param buffAmount - The amount of force to add.
     *
     * @return
     *      void
     */
    void buff(int buffAmount);

    /*
     * Increases player's health by a given number.
     * If player's health goes beyond his maximum health, the health is set to the maximum health.
     * Player's health doesn't change if received number is negative.
     *
     * @param healAmount - The amount of health to add.
     *
     * @return
     *      void
     */
    void heal(int healAmount);

    /*
     * Decreases player's health by a given number.
     * If player's health goes beyond his 0, the health is set to 0.
     * Player's health doesn't change if received number is negative.
     *
     * @param damageRecieved - The amount of health to decrease.
     *
     * @return
     *      void
     */
    void damage(int damageRecieved);

    /*
     * Check if the player is knocked out:
     *
     * @return
     *          True if the player is knocked out
     *          False otherwise
     */
    bool isKnockedOut() const;

    /*
     * Increases player's coins amount by a given number.
     * Player's coins doesn't change if received number is negative.
     *
     * @param coinsRecieved - The amount of coins to add.
     *
     * @return
     *      void
     */
    void addCoins(int coinsRecieved);

    /*
     * Decreases the player's coins amount by a given number, if the player has enough coins.
     * Otherwise, doesn't change his coins amount.
     *
     * @param price - The amount of coins to decrease.
     *
     * @return
     *      True if player has enough coins
     *      False otherwise
     */
    bool pay(int price);

    /*
     * Gets the player's attack strength:
     *
     * @return
     *      player's attack strength
     */
    int getAttackStrength() const;


};

#endif