//
// Created by yusuf on 01.06.2020.
//

#include "Cyberdemon.h"
#include <iostream>

namespace Yusuf {

    int Cyberdemon::getDamage() {
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
        cout << "Total damage = " << damage << endl;

        return damage;
    }

    Cyberdemon::Cyberdemon( int strength, int hitpoint) : Demon( strength, hitpoint) {
        setType(1);
    }

    Cyberdemon::Cyberdemon() : Demon( 10, 10) {
        setType(1);
    }

    string Cyberdemon::getSpecies() {
        //return Creature::getSpecies();

        if(getType() == 1){
            return "Cyberdemon";
        }
    }
}

