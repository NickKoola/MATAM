//
// Created by Bar Kalandarov on 04/01/2023.
//

#include "BattleCard.h"
#include "Dragon.h"

BattleCard::BattleCard(int force, int loot, int damage, std::string name, int forceDamage) : Card(name) {
    m_force = force;
    m_loot = loot;
    m_damage = damage;
    m_forceDamage = forceDamage;
}

void BattleCard::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= m_force) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), m_name);
    }
    else {
        player.damage(m_damage);
        player.buff(-m_forceDamage);
        printLossBattle(player.getName(), m_name);
    }
}

void BattleCard::toString(std::ostream &os) const {
    printCardDetails(os, m_name);
    printMonsterDetails(os, m_force, m_damage, m_loot, m_name == DRAGON_CARD_NAME);
}




