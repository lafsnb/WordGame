// spell.cpp

#include "Spell.h"

Spell::Spell(const std::string& name, int highDamage,
                int lowDamage, int magicPoints, )
{
    mname = name;
    mMagicPointsRequired = magicPoints;
    mDamageRange = (lowDamage, highDamage);

}

