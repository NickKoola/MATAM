#include "Card.h"

Card::Card(std::string name) {
    m_name = name;
}

void Card::toString(std::ostream &os) const {
    printCardDetails(os, m_name);

}

std::ostream &operator<<(std::ostream &os, const Card &card) {
    card.toString(os);
    printEndOfCardDetails(os);
    return os;
}

Card::~Card() = default;



