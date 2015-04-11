// store.cpp

#include <iostream>
#include "Store.h"

using namespace std;

int selection = 0;
void Store::shop()
{

    cout << endl;

    cout << "Welcome to the weapons and armor shop!" << endl;
    cout << "=====================================" << endl << endl;

    cout << "1)Weapons 2)Armor 3)Leave Shop";
    cin selection;
    switch(selection)
    {
    case 1:
        weaponShop();
        break;
    case 2:
        armorShop();
        break;
    default:
        break;
    }

}


void Store::weaponShop()
{
    cout << "Weapons" << endl;
    cout << "=======" << endl << endl;

    cout << "Long Sword: 500 gold" << endl;
    cout << "    - 10-12 damage" << endl;
    cout << "    - +2 accuracy" << endl << endl;

    cout << "Healing Staff: 500 gold" << endl;
    cout << "    - Wizards and Clerics only " << endl;
    cout << "    - 5-6 damage" << endl;
    cout << "    - +5 magicpoints" << endl;
    cout << "    - Every time you attack with a spell" << endl
        <<  "       heal 5 health." << endl << endl;

}

void Store::armorShop()
{

}

