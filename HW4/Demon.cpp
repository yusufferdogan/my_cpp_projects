//
// Created by yusuf on 01.06.2020.
//

#include "Demon.h"
#include <iostream>

namespace Yusuf {
     int Demon::getDamage() {
         int damage = Creature::getDamage();
         flag = false;
         if (rand()%100 < 50 ){
             damage += 50;
             flag = true;
         }

         return damage;
     }

    Demon::Demon( int strength, int hitpoint) : Creature(strength, hitpoint) {}

    Demon::Demon() {}

    string Demon::getSpecies() {}
}

