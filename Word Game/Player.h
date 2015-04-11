// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"
#include "Monster.h"
#include "Spell.h"
#include <string>

class Player
{
public:
	// Constructor.
	Player();

	// Methods
	bool isDead();

	int  getArmor();

	void takeDamage(int damage);
    void createRace();
	void createClass();
	bool attack(Monster& monster);
	void levelUp();
	void rest();
	void viewStats();
	void victory(int xp, int gold);
	void gameover();
	void displayHitPoints();
	void displayMagicPoints();

private:
	// Data members.
	std::string mName;
	std::string mClassName;
	std::string mCharRace;
	int         mMagicPoints;
	int         mMaxMagicPoints;
	int         mGold;
	int         mAccuracy;
	int         mHitPoints;
	int         mMaxHitPoints;
	int         mExpPoints;
	int         mNextLevelExp;
	int         mLevel;
	int         mArmor;
	Weapon      mWeapon;
	Spell       mSpell;
};

#endif //PLAYER_H
