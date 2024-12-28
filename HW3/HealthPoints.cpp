#include "HealthPoints.h"

HealthPoints::HealthPoints(const int maxHp): m_maxHp(maxHp), m_hp(maxHp)
{
    if(m_hp <= 0 )
    {
        throw InvalidArgument(); //TODO: HealthPoints::InvalidArgument()
    }
}

HealthPoints& HealthPoints::operator+=(const int hpToAdd)
{
    this->m_hp += hpToAdd;
    if(this->m_hp > m_maxHp)
    {
        this->m_hp = m_maxHp;
    }

    if(this->m_hp < 0) {
        this->m_hp = 0;
    }
    return *this;
}
HealthPoints HealthPoints::operator+(const int hpToAdd) const
{
    HealthPoints temp(*this);
    return temp += hpToAdd;
}


HealthPoints& HealthPoints::operator-=(const int hpToSubtract)
{
    this->m_hp -= hpToSubtract;
    if(this->m_hp < 0)
    {
        this->m_hp = 0;
    }

    if(this->m_hp > this->m_maxHp) {
        this->m_hp = this->m_maxHp;
    }

    return *this;
}

HealthPoints HealthPoints::operator-(const int hpToSubtract) const
{
    HealthPoints temp(*this);
    return temp -= hpToSubtract;
}

bool operator==(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return hp1.m_hp == hp2.m_hp;
}


bool operator<(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return hp1.m_hp < hp2.m_hp;
}


std::ostream& operator<<(std::ostream& os, const HealthPoints& hp)
{
    os << hp.m_hp << "(" << hp.m_maxHp << ")";
    return os;
}


HealthPoints operator+(const int hpToAdd, HealthPoints& object)
{
    HealthPoints temp(object);
    return (temp += hpToAdd);
}

/*
bool operator==(const int hp1, const  HealthPoints& hp2)
{
    return hp2 == hp1;
} // is HealthPoints == int needed?
*/

bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return !(hp1 == hp2);
}


bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return (hp1 < hp2) || (hp1 == hp2);
}

bool operator>(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return (hp2 < hp1);
}

bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2)
{
    return (hp2 <= hp1);
}
