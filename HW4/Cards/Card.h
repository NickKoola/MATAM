//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"


class Card {
protected:
    std::string m_name;
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    explicit Card(std::string name);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card();
    Card& operator=(const Card& other) = default;

    virtual Card* clone() const = 0;

    /*
     * @return
     *      a string representation of the card.
     * */

    virtual void toString(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};


#endif //EX2_Card_H
