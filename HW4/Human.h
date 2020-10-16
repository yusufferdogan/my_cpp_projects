//
// Created by yusuf on 01.06.2020.
//

#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>

#include "Creature.h"
namespace Yusuf{
    class Human : public Creature {
    public:
        Human(int strength, int hitpoint);

        Human();

        int getDamage();

        string getSpecies();
    };


}

#endif //HW4_HUMAN_H
