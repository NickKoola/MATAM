#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) : m_player(playerName){
    m_deck = new Card[numOfCards];
    for (int i=0; i < numOfCards; i++) {
        m_deck[i] = cardsArray[i];
    }
    m_numOfCards = numOfCards;
    m_currCardIndex = 0;
    m_gameStatus = GameStatus::MidGame;
}

Mtmchkin::~Mtmchkin() {
    delete []m_deck;
}


Mtmchkin::Mtmchkin(const Mtmchkin& other): m_player(other.m_player) {
    this->m_numOfCards = other.m_numOfCards;
    this->m_gameStatus = other.m_gameStatus;
    this->m_currCardIndex = other.m_currCardIndex;

    m_deck = new Card[m_numOfCards];
    for (int i=0; i < m_numOfCards; i++) {
        m_deck[i] = other.m_deck[i];
    }
}

Mtmchkin &Mtmchkin::operator=(const Mtmchkin &other) {
    if (this == &other) {
        return *this;
    }

    delete this->m_deck;

    this->m_numOfCards = other.m_numOfCards;
    this->m_gameStatus = other.m_gameStatus;
    this->m_currCardIndex = other.m_currCardIndex;

    m_deck = new Card[m_numOfCards];
    for (int i=0; i < m_numOfCards; i++) {
        m_deck[i] = other.m_deck[i];
    }
    return *this;
}

void Mtmchkin::playNextCard() {
    m_deck[m_currCardIndex].printInfo();
    m_deck[m_currCardIndex].applyEncounter(m_player);
    m_player.printInfo();
    m_currCardIndex++;
    if(m_currCardIndex == m_numOfCards) {
        m_currCardIndex = FIRST_INDEX;
    }

    if(m_player.getLevel() == MAX_LEVEL) {
        m_gameStatus = GameStatus::Win;
    }
    if(m_player.isKnockedOut()) {
        m_gameStatus = GameStatus::Loss;
    }
}

bool Mtmchkin::isOver() const {
    return(m_gameStatus != GameStatus::MidGame);
}

GameStatus Mtmchkin::getGameStatus() const {
    return m_gameStatus;
}


