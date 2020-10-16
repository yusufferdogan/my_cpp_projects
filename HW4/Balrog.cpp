//
// Created by yusuf on 01.06.2020.
//

#include "Balrog.h"
#include <iostream>

namespace Yusuf {
    int Balrog::getDamage() {

        int damage = Demon::getDamage();

        if (flag){
            cout << getSpecies() << " attacks for " <<
                 damage-50 << " points!" << endl;
            cout << "Demonic attack inflicts 50 additional damage points!\n";
        }
        else {
            cout << getSpecies() << " attacks for " <<
                 damage << " points!" << endl;
        }

        int dmg = (rand() % getStrength()) + 1;

        cout << "Balrog speed attack inflicts "
             << dmg
             << " additional damage points!\n";

        damage += dmg;

        cout << "Total damage = " << damage << endl;

        return damage;
    }

    Balrog::Balrog( int strength, int hitpoint) : Demon( strength, hitpoint) {
        setType(2);
    }

    Balrog::Balrog() : Demon( 10, 10){
        setType(2);
    }

    string Balrog::getSpecies() {
        //return Creature::getSpecies();
        return "Balrog";


    }

}

