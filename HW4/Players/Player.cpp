#include "Player.h"
#include "../utilities.h"

using  std::string;

Player::Player(string name, int maxHP, int force)
{
    if(maxHP <= 0) {
        m_maxHP = DEFAULT_MAX_HP;
    }
    else {
        m_maxHP = maxHP;
    }

    if(force < 0){
        m_force = DEFAULT_FORCE;
    }
    else {
        m_force = force;
    }

    m_name = name;
    m_level = STARTING_LEVEL;
    m_hp = m_maxHP;
    m_coins = STARTING_COINS;
}


void Player::levelUp() {
    if(m_level < MAX_LEVEL){
        ++m_level;
    }
}

int Player::getLevel() const {
    return m_level;
}

void Player::buff(int buffAmount) {
    /*
    if(buffAmount > 0) {
        m_force += buffAmount;
    }*/

    m_force += buffAmount;

    if (m_force < 0) {
        m_force = 0;
    }
}

void Player::heal(int healAmount) {
    if(healAmount > 0) {
        if(m_hp + healAmount > m_maxHP) {
            m_hp = m_maxHP;
        }
        else {
            m_hp += healAmount;
        }
    }
}

void Player::damage(int damageRecieved) {
    if(damageRecieved > 0) {
        if(damageRecieved > m_hp) {
            m_hp = 0;
        }
        else {
            m_hp -= damageRecieved;
        }
    }
}

bool Player::isKnockedOut() const {
    return (m_hp <= 0);
}

void Player::addCoins(int coinsRecieved) {
    if(coinsRecieved > 0) {
        m_coins += coinsRecieved;
    }
}

bool Player::pay(int price) {
    if(price >= 0) {
        if(m_coins >= price) {
            m_coins -= price;
            return true;
        }
        return false;
    }
    return true;
}

int Player::getAttackStrength() const {
    return (m_force + m_level);
}

std::string Player::getName() const {
    return m_name;
}

int Player::getCoinsAmount() const {
    return m_coins;
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    printPlayerDetails(os, player.m_name, player.getType(), player.m_level,player.m_force, player.m_hp, player.m_coins);
    return os;
}

bool Player::isWon() const {
    return m_level == MAX_LEVEL;
}
