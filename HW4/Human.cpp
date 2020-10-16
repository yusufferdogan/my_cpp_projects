//
// Created by yusuf on 01.06.2020.
//

#include "Human.h"
#include <iostream>

namespace Yusuf {
    Human::Human() : Creature(10, 10){
        setType(0);
    }

    Human::Human( int strength, int damage) : Creature(strength, damage) {
        setType(0);
    }

    int Human::getDamage() {

        int damage = Creature::getDamage();

        cout << getSpecies() << " attacks for " <<
             damage << " points!" << endl;

        cout << "Total damage = " << damage << endl;

        return damage ;

    }

    string Human::getSpecies() {
        //return Creature::getSpecies();
//        if(getType() == 0){
            return "Human";
//        }
    }

}

