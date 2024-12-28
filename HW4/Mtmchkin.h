#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <string>
#include <queue>
#include <vector>
#include <memory>
#include "Cards/Card.h"
#include <fstream>
#include "Cards/Witch.h"
#include "Cards/Gremlin.h"
#include "Cards/Dragon.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Mana.h"
#include "Cards/Barfight.h"
#include "Players/Player.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
#include "Players/Healer.h"
#include "Exception.h"

using namespace std;
const int PLAYER_NAME_MAX_LEN = 15;
const int TEAM_MIN_SIZE = 2;
const int TEAM_MAX_SIZE = 6;
const int DECK_MIN_SIZE = 5;
const int PLAYER_INPUT_NAME_INDEX = 0;
const int PLAYER_INPUT_CLASS_INDEX = 1;

class Mtmchkin{
    queue<unique_ptr<Card>> m_deck;
    vector<unique_ptr<Player>> m_players;
    int m_numOfRounds;
    int m_numOfPlayersPlaying;
    bool m_isGameOn;
    int m_nextWinnerRanking;
    int m_nextLoserRanking;

    static std::ifstream* openDeckFile(const std::string& filePath);
    static void buildDeck(std::ifstream* deckFile, queue<unique_ptr<Card>>& deck);
    static int receiveTeamSize();
    static bool isValidName(const std::string& name);
    static void initPlayers(int teamSize, vector<unique_ptr<Player>>& playerVector);
    static bool insertPlayer(const std::string& playerName, const std::string& playerJob, vector<unique_ptr<Player>>& playerVector);
public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number ofx rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    Mtmchkin(const Mtmchkin&) = delete;
    Mtmchkin& operator=(const Mtmchkin& other) = delete;
};





#endif /* MTMCHKIN_H_ */
