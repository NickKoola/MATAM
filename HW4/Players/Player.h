#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>


const int DEFAULT_FORCE = 5;
const int DEFAULT_MAX_HP = 100;
const int STARTING_LEVEL = 1;
const int STARTING_COINS = 10;
const int MAX_LEVEL = 10;

class Player{
    std::string m_name;
    int m_level;
    int m_maxHP;
    int m_hp;
    int m_coins;
protected:
    int m_force;

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
    explicit Player(std::string name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player(const Player& other) = default;
    virtual ~Player() = default;
    Player& operator=(const Player& player) = default;

    //Copy Constructor
    virtual Player* clone() const = 0;

    /*
     * Gets the player's name.
     *
     * @return
     *      player's name
     *
     */
    std::string getName() const;

    /*
     * Gets the player's coins amount.
     *
     * @return
     *      player's coins amount
     *
     */
    int getCoinsAmount() const;

    /*
     * Check if the player has won - reached the maximum level.
     *
     * @return
     *      True - if won
     *      False, otherwise.
     *
     * */
    bool isWon() const;

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
    virtual void heal(int healAmount);

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
    virtual void addCoins(int coinsRecieved);

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
    virtual int getAttackStrength() const;

    /*
     * Gets the player's type (job).
     *
     * @return
     *      player's type
     *
     * */
    virtual std::string getType() const = 0;


    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

#endif