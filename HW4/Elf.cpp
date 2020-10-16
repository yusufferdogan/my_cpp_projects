//
// Created by yusuf on 01.06.2020.
//

#include "Elf.h"
#include "Creature.h"
#include <iostream>
namespace Yusuf {

    Elf::Elf() : Creature(10,10)  {
        setType(3);
    }

    Elf::Elf( int strength, int hitpoint) : Creature( strength, hitpoint) {
        setType(3);
    }

    int Elf::getDamage(){

        int damage = Creature::getDamage();

        cout << getSpecies() << " attacks for " <<
             damage << " points!" << endl;

        if (rand()%100 < 10 ){
            cout
                    << "Magical attack inflicts "
                    <<  damage
                    << " additional damage points!\n";

            damage *= 2;
        }
        cout << "Total damage = " << damage << endl;
        return damage;
    }

    string Elf::getSpecies() {
//        return Creature::getSpecies();
//        if(getType() == 3){
            return "Elf";
//        }
    }
}

