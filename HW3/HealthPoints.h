
#include <iostream>

const int DEFAULT_MAX_HP = 100;

class HealthPoints {
private:
    int m_maxHp;
    int m_hp;

public:
    HealthPoints(const int maxHp = DEFAULT_MAX_HP);

    HealthPoints(const HealthPoints& other) = default;
    ~HealthPoints() = default;
    HealthPoints& operator=(const HealthPoints& other) = default;//TODO: is it default?

    HealthPoints& operator+=(const int hpToAdd);
    HealthPoints operator+(const int hpToAdd) const;//TODO: return &?
    HealthPoints& operator-=(const int hpToSubtract);
    HealthPoints operator-(const int hpToSubtract) const;//TODO: return &?

    friend bool operator==(const HealthPoints& hp1, const HealthPoints& hp2);
    friend bool operator<(const HealthPoints& hp1, const HealthPoints& hp2);
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& hp);

    class InvalidArgument{};
};

HealthPoints operator+(const int hpToAdd, HealthPoints& object);
//bool operator==(const int hp1, const  HealthPoints& hp2);
bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator>(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2);
