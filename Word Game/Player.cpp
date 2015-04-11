// Player.cpp

#include <iostream>
#include "Player.h"
#include "Random.h"
#include <string>
using namespace std;

Player::Player()
{
	mName         = "Default";
	mClassName    = "Default";
	mCharRace     = "Default";
	mGold         = 0;
	mAccuracy     = 0;
	mHitPoints    = 0;
	mMaxHitPoints = 0;
	mExpPoints    = 0;
	mNextLevelExp = 0;
	mLevel        = 0;
	mArmor        = 0;
	mWeapon.mName = "Default Weapon Name";
	mWeapon.mDamageRange.mLow   = 0;
	mWeapon.mDamageRange.mHigh  = 0;
	mSpell.mName  = "Default Spell Name";
	mSpell.mDamageRange.mLow    = 0;
	mSpell.mDamageRange.mHigh   = 0;
	mSpell.mMagicPointsRequired = 0;
}

bool Player::isDead()
{
	return mHitPoints <= 0;
}

int Player::getArmor()
{
	return mArmor;
}

void Player::takeDamage(int damage)
{
	mHitPoints -= damage;
}

void Player::createRace()
{
    cout << endl;
    cout << "CHARACTER RACE GENERATION" << endl;
    cout << "=========================" << endl;

    //Race Selection
    cout << endl << "Please Select a Race..." << endl;
    cout << "This will effect the stats you get when you level up." << endl;
    cout << "So choose wisely." << endl;
    cout << "1)Human 2)Dwarf 3)Elf : ";
    char selection = 'y';
    //Race selection
    int raceNum = 1;
    cin >> raceNum;

    switch(raceNum)
    {
    case 1:
        cout << "The Human Race is average, so it doesn't lack in any stats" << endl;
        cout << "Do you still want to be a Human? (y)es/(n)o : ";
        cin >> selection;

        if (selection == 'y' || selection == 'Y')
        {
            mCharRace = "Human";
            mAccuracy += 2;
            mHitPoints += 2;
            mMaxHitPoints += 2;
            mArmor += 2;
            mMaxMagicPoints += 2;
            mMagicPoints = mMaxMagicPoints;
            break;
        }
        else
        {
            cout << "Please Select a Race..." << endl;
            cout << "1)Human 2)Dwarf 3)Elf : ";
            cin >> raceNum;
        }
    case 2:
        cout << "The Dwarf Race excels in Health and armor, but lacks in accuracy and magic." << endl;
        cout << "Do you still want to be a Dwarf? (y)es/(n)o : ";
        cin >> selection;

        if (selection == 'y' || selection == 'Y')
        {
            mCharRace = "Dwarf";
            mAccuracy -= 2;
            mHitPoints += 6;
            mMaxHitPoints += 6;
            mArmor += 6;
            mMaxMagicPoints -= 2;
            mMagicPoints = mMaxMagicPoints;
            break;
        }
        else
        {
            cout << "Please Select a Race..." << endl;
            cout << "1)Human 2)Dwarf 3)Elf : ";
            cin >> raceNum;
        }
    default:
        cout << "The Elf Race excels in accuracy and magic, but lacks in health and armor." << endl;
        cout << "Do you still want to be a Elf? (y)es/(n)o : ";
        cin >> selection;

        if (selection == 'y' || selection == 'Y')
        {
            mCharRace = "Elf";
            mAccuracy += 6;
            mHitPoints -= 2;
            mMaxHitPoints -= 2;
            mArmor -= 2;
            mMaxMagicPoints += 6;
            mMagicPoints = mMaxMagicPoints;
            break;
        }
        else
        {
            cout << "Please Select a Race..." << endl;
            cout << "1)Human 2)Dwarf 3)Elf : ";
            cin >> raceNum;
        }



    }
}

void Player::createClass()
{
	cout << "CHARACTER CLASS GENERATION" << endl;
	cout << "==========================" << endl;

	// Input character's name.
	cout << "Enter your character's name: ";
	getline(cin, mName);

	// Character selection.
	cout << "Please select a character class number..."<< endl;
	cout << "1)Fighter 2)Wizard 3)Cleric 4)Thief : ";

	int characterNum = 1;
	cin >> characterNum;

	switch( characterNum )
	{
	case 1:  // Fighter
		mClassName      = "Fighter";
		mGold           = 0;
		mAccuracy       = 10;
		mHitPoints      = 25;
		mMaxHitPoints   = 25;
		mMagicPoints    = 4;
		mMaxMagicPoints = 4;
		mExpPoints      = 0;
		mNextLevelExp   = 1000;
		mLevel          = 1;
		mArmor          = 5;
		mWeapon.mName   = "Long Sword";
		mWeapon.mDamageRange.mLow   = 1;
		mWeapon.mDamageRange.mHigh  = 8;
		mSpell.mName    = "Beserker";
		mSpell.mDamageRange.mLow    = 7;
		mSpell.mDamageRange.mHigh   = 10;
		mSpell.mMagicPointsRequired = 8;
		break;
	case 2:  // Wizard
		mClassName      = "Wizard";
		mGold           = 0;
		mAccuracy       = 5;
		mHitPoints      = 15;
		mMaxHitPoints   = 15;
		mMagicPoints    = 15;
		mMaxMagicPoints = 15;
		mExpPoints      = 0;
		mNextLevelExp   = 1000;
		mLevel          = 1;
		mArmor          = 2;
		mWeapon.mName   = "Staff";
		mWeapon.mDamageRange.mLow  = 1;
		mWeapon.mDamageRange.mHigh = 4;
		mSpell.mName    = "Fireball";
		mSpell.mDamageRange.mLow    = 6;
		mSpell.mDamageRange.mHigh   = 10;
		mSpell.mMagicPointsRequired = 9;
		break;
	case 3:  // Cleric
		mClassName      = "Cleric";
		mGold           = 0;
		mAccuracy       = 8;
		mHitPoints      = 18;
		mMaxHitPoints   = 18;
		mMagicPoints    = 10;
		mMaxMagicPoints = 10;
		mExpPoints      = 0;
		mNextLevelExp   = 1000;
		mLevel          = 1;
		mArmor          = 3;
		mWeapon.mName   = "Flail";
		mWeapon.mDamageRange.mLow  = 1;
		mWeapon.mDamageRange.mHigh = 6;
		mSpell.mName    = "Damage";
		mSpell.mDamageRange.mLow    = 6;
		mSpell.mDamageRange.mHigh   = 8;
		mSpell.mMagicPointsRequired = 4;
		break;
	default: // Thief
		mClassName      = "Thief";
		mGold           = 10;
		mAccuracy       = 7;
		mHitPoints      = 16;
		mMaxHitPoints   = 16;
		mMagicPoints    = 6;
		mMaxMagicPoints = 6;
		mExpPoints      = 0;
		mNextLevelExp   = 1000;
		mLevel          = 1;
		mArmor          = 4;
		mWeapon.mName   = "Short Sword";
		mWeapon.mDamageRange.mLow  = 1;
		mWeapon.mDamageRange.mHigh = 6;
		mSpell.mName    = "Backstab";
		mSpell.mDamageRange.mLow    = 8;
		mSpell.mDamageRange.mHigh   = 10;
		mSpell.mMagicPointsRequired = 5;
		break;
	}
}

bool Player::attack(Monster& monster)
{
	// Combat is turned based: display an options menu.  You can,
	// of course, extend this to let the player use an item,
	// cast a spell, and so on.
	int selection = 1;
	int choice = 1;
	cout << "1) Attack, 2)Cast Spell, 3) Run: ";
	cin >> selection;
	cout << endl;

	switch( selection )
	{
	case 1:
		cout << "You attack an " << monster.getName()
			<< " with a " << mWeapon.mName << endl;

		if( Random(0, 20) < mAccuracy )
		{
			int damage = Random(mWeapon.mDamageRange);

			int totalDamage = damage - monster.getArmor();

			if( totalDamage <= 0 )
			{
				cout << "Your attack failed to penetrate "
					<< "the armor." << endl;
			}
			else
			{
				cout << "You attack for " << totalDamage
					<< " damage!" << endl;

				// Subtract from monster's hitpoints.
				monster.takeDamage(totalDamage);
			}
		}
		else
		{
			cout << "You miss!" << endl;
		}
		cout << endl;
		break;
    case 2:
        if (mMagicPoints >= mSpell.mMagicPointsRequired)
        {
            mMagicPoints -= mSpell.mMagicPointsRequired;

            cout << "You attack an " << monster.getName()
                << " with a " << mSpell.mName << endl;
            if (Random(0, 1) < mMaxMagicPoints)
            {
                int damage = Random(mSpell.mDamageRange);

                cout << "Your spell does " << damage
                    << " damage!" << endl;
                if (mClassName == "Thief")
                {
                    cout << "You also took 2 gold from the "
                        << monster.getName() << "!" << endl;
                    mGold += 2;
                }


                monster.takeDamage(damage);
            }
            else
            {
                cout << "You miss!" << endl;
            }
        }
        else
        {
            cout << "That spell costs " << mSpell.mMagicPointsRequired
                << " magicpoints, and you only have " << mMagicPoints
                << " magicpoints." << endl;
            cout << "1)Attack 2)Cast Spell 3)Run: ";
            cin >> selection;
        }

        break;

	case 3:
		// 33 % chance of being able to run.
		int roll = Random(1, 3);

		if( roll == 1 )
		{
			cout << "You run away!" << endl;
			return true;//<--Return out of the function.
		}
		else
		{
			cout << "You could not escape!" << endl;
			break;
		}
	}

	return false;
}

void Player::levelUp()
{
	if( mExpPoints >= mNextLevelExp )
	{
		cout << "You gained a level!" << endl;

		// Increment level.
		mLevel++;

		// Set experience points required for next level.
		mNextLevelExp = mLevel * mLevel * 1000;
        if (mCharRace == "Human")
        {
            // Increase stats randomly.
            mAccuracy       += Random(2, 3);
            mMaxHitPoints   += Random(3, 6);
            mArmor          += Random(1, 3);
            mMaxMagicPoints += Random(2, 3);
        }
        else if (mCharRace == "Dwarf")
        {
            mAccuracy       += Random(1, 2);
            mMaxHitPoints   += Random(6, 9);
            mArmor          += Random(1, 3);
            mMaxMagicPoints += Random(1, 2);
        }
        else if (mCharRace == "Elf")
        {
            mAccuracy       += Random(4, 6);
            mMaxHitPoints   += Random(2, 3);
            mArmor          += Random(1, 3);
            mMaxMagicPoints += Random(3, 5);
        }

        mHitPoints = mMaxHitPoints;
        mMagicPoints = mMaxMagicPoints;
		// Give player full hitpoints when they level up.
		//mLevel = mMaxHitPoints;
	}
}

void Player::rest()
{
	cout << "Resting..." << endl;


	mHitPoints = mMaxHitPoints;
	mMagicPoints = mMaxMagicPoints;

	// TODO: Modify function so that random enemy encounters
	// are possible when resting.
}

void Player::viewStats()
{
	cout << "PLAYER STATS" << endl;
	cout << "============" << endl;
	cout << endl;

	cout << "Name                 = " << mName         << endl;
	cout << "Race                 = " << mCharRace     << endl;
	cout << "Class                = " << mClassName    << endl;
	cout << "Accuracy             = " << mAccuracy     << endl;
	cout << "Hitpoints            = " << mHitPoints    << endl;
	cout << "MaxHitpoints         = " << mMaxHitPoints << endl;
	cout << "MagicPoints          = " << mMagicPoints  << endl;
	cout << "MaxMagicPoints       = " << mMaxMagicPoints << endl;
	cout << "XP                   = " << mExpPoints    << endl;
	cout << "XP for Next Lvl      = " << mNextLevelExp << endl;
	cout << "Gold                 = " << mGold         << endl;
	cout << "Level                = " << mLevel        << endl;
	cout << "Armor                = " << mArmor        << endl;
	cout << "Weapon Name          = " << mWeapon.mName << endl;
	cout << "Weapon Damage        = " << mWeapon.mDamageRange.mLow << "-" <<
		mWeapon.mDamageRange.mHigh << endl;
    cout << "Spell Name           = " << mSpell.mName << endl;
    cout << "Spell Damage         = " << mSpell.mDamageRange.mLow << "-" <<
        mSpell.mDamageRange.mHigh << endl;
    cout << "Magicpoints Required = " << mSpell.mMagicPointsRequired << endl;

	cout << endl;
	cout << "END PLAYER STATS" << endl;
	cout << "================" << endl;
	cout << endl;
}

void Player::victory(int xp, int gold)
{
	cout << "You won the battle!" << endl;
	cout << "You win " << xp
		<< " experience points, and " << gold << " gold!" << endl << endl;

	mExpPoints += xp;
	mGold += gold;
}

void Player::gameover()
{
	cout << "You died in battle..." << endl;
	cout << endl;
	cout << "================================" << endl;
	cout << "GAME OVER!" << endl;
	cout << "================================" << endl;
	cout << "Press 'q' to quit: ";
	char q = 'q';
	cin >> q;
	cout << endl;
}

void Player::displayHitPoints()
{
	cout << mName << "'s hitpoints = " << mHitPoints << endl;
}
void Player::displayMagicPoints()
{
    cout << mName << "'s magicpoints = " << mMagicPoints << endl;
}
