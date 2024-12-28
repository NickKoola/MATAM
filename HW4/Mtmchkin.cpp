//
// Created by Bar Kalandarov on 05/01/2023.
//
#include "Mtmchkin.h"
#include <algorithm>


Mtmchkin::Mtmchkin(const std::string &fileName) {
    printStartGameMessage();
    std::ifstream* deckFile = openDeckFile(fileName);
    buildDeck(deckFile, m_deck);

    if (m_deck.size() < 5) {
        throw DeckFileInvalidSize();
    }

    m_numOfPlayersPlaying = receiveTeamSize();
    m_nextWinnerRanking = 1;
    m_nextLoserRanking = m_numOfPlayersPlaying;
    initPlayers(m_numOfPlayersPlaying, m_players);

    m_numOfRounds = 0;
    m_isGameOn = true;
}

bool Mtmchkin::isGameOver() const {
    return !m_isGameOn;
}

int Mtmchkin::getNumberOfRounds() const {
    return m_numOfRounds;
}

void Mtmchkin::playRound() {
    if (m_isGameOn) {
        m_numOfRounds++;
        printRoundStartMessage(m_numOfRounds);

        for (int index = 0; size_t(index) < m_players.size(); index++)
        {
            if (!((*m_players[index]).isKnockedOut() || (*m_players[index]).isWon())) {
                printTurnStartMessage((*m_players[index]).getName());
                unique_ptr<Card> currentCard (std::move(m_deck.front()));

                (*currentCard).applyEncounter(*m_players[index]);

                if ((*m_players[index]).isKnockedOut()) {
                    rotate(m_players.begin()+index, m_players.begin()+index+1, m_players.begin() + m_nextLoserRanking);
                    m_nextLoserRanking--;
                    m_numOfPlayersPlaying--;
                    index--;
                } else if ((*m_players[index]).isWon()) {
                    rotate(m_players.begin()+m_nextWinnerRanking-1, m_players.begin()+index, m_players.begin()+index+1);
                    m_nextWinnerRanking++;
                    m_numOfPlayersPlaying--;
                }

                m_deck.pop();
                m_deck.push(std::move(currentCard));
            }
        }

        if (m_numOfPlayersPlaying == 0) {
            printGameEndMessage();
            m_isGameOn = false;
        }
    }
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int ranking = 1;

    for (const auto & m_player : m_players) {
        printPlayerLeaderBoard(ranking, *m_player);
        ranking++;
    }

}

std::ifstream* Mtmchkin::openDeckFile(const std::string& filePath) {
    auto* deckFile = new ifstream (filePath);
    if (!(*deckFile).is_open()) {
        delete deckFile;
        throw DeckFileNotFound();
    }

    return deckFile;
}

void Mtmchkin::buildDeck(std::ifstream* deckFile, queue<unique_ptr<Card>>& deck) {
    int cardsCount = 1;
    std::string cardType;

    while (std::getline(*deckFile, cardType))
    {
        //cardType.erase(cardType.size() - 1);
        if (cardType == BARFIGHT_CARD_NAME) {
            deck.push(unique_ptr<Card>(new Barfight));
        } else if (cardType == DRAGON_CARD_NAME) {
            deck.push(unique_ptr<Card>(new Dragon));
        } else if (cardType == MANA_CARD_NAME) {
            deck.push(unique_ptr<Card>(new Mana));
        } else if (cardType == MERCHANT_CARD_NAME) {
            deck.push(unique_ptr<Card>(new Merchant));
        } else if (cardType == TREASURE_CARD_NAME) {
            deck.push(unique_ptr<Card>(new Treasure));
        } else if (cardType == WELL_CARD_NAME) {
            deck.push(unique_ptr<Card>(new Well));
        } else if (cardType == GREMLIN_CARD_NAME) {
            deck.push(unique_ptr<Card>(new Gremlin));
        } else if (cardType == WITCH_CARD_NAME) {
            deck.push(unique_ptr<Card>(new Witch));
        } else {
            delete deckFile;
            throw DeckFileFormatError(cardsCount);
        }

        cardsCount++;
    }

    delete deckFile;
}

int Mtmchkin::receiveTeamSize() {
    string sizeInput;
    int teamSize = 0;

    while (teamSize == 0) {
        printEnterTeamSizeMessage();
        getline(cin, sizeInput);
        try {
            teamSize = stoi(sizeInput);
            if (teamSize < TEAM_MIN_SIZE || teamSize > TEAM_MAX_SIZE) {
                printInvalidTeamSize();
                teamSize = 0;
            }
        } catch (std::invalid_argument const &e) {
            printInvalidTeamSize();
            teamSize = 0;
        }
    }

    return teamSize;
}

void Mtmchkin::initPlayers(int teamSize, vector<unique_ptr<Player>> &playerVector) {
    string fullInput;
    string playerName;
    string playerJob;
    int inputIndex;
    bool inputSucceed = false;

    for (int i = 0; i < teamSize; i++) {
        inputSucceed = false;
        printInsertPlayerMessage();
        while (!inputSucceed) {
            inputIndex = PLAYER_INPUT_NAME_INDEX;
            getline(cin, fullInput);
            istringstream inputStream(fullInput);
            string currentInput;

            while (getline(inputStream, currentInput, ' ') && inputIndex != -1) {
                if (inputIndex == PLAYER_INPUT_NAME_INDEX) { //Name of player
                    playerName = currentInput;
                    inputIndex++;

                    if (!isValidName(playerName)) {
                        printInvalidName();
                        inputIndex = -1;
                    }
                } else if (inputIndex == PLAYER_INPUT_CLASS_INDEX) { //Player Job
                    playerJob = currentInput;
                    inputSucceed = insertPlayer(playerName, playerJob, playerVector);
                    if (!inputSucceed) {
                        printInvalidClass();
                    }
                }
            }
        }
    }
}

bool Mtmchkin::isValidName(const string &name) {
    for (char c: name) {
        if (!isalpha(c)) {
            return false;
        }
    }

    return name.length() <= PLAYER_NAME_MAX_LEN;
}

bool Mtmchkin::insertPlayer(const string& playerName, const string &playerJob, vector<unique_ptr<Player>> &playerVector) {
    if (playerJob == NINJA_TYPE) {
        playerVector.push_back(unique_ptr<Player>(new Ninja(playerName)));
        return true;
    } else if (playerJob == WARRIOR_TYPE) {
        playerVector.push_back(unique_ptr<Player>(new Warrior(playerName)));
        return true;
    } else if (playerJob == HEALER_TYPE) {
        playerVector.push_back(unique_ptr<Player>(new Healer(playerName)));
        return true;
    }

    return false;
}


