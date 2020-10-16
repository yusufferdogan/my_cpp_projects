//
// Created by yusuf on 01.06.2020.
//

#ifndef DEMON_H
#define DEMON_H


#include "Creature.h"
#include <iostream>


namespace Yusuf {

    class Demon : public Creature {
    public:
        int getDamage();

        Demon(int strength, int hitpoint);

        Demon();

        bool flag;
    private:
        string getSpecies();

    };


}


#endif //HW4_DEMON_H
