//
// Created by yusuf on 01.06.2020.
//

#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include <iostream>

#include "Demon.h"

namespace Yusuf {

    class Cyberdemon : public Demon{
    public:
        Cyberdemon();

        Cyberdemon(int strength, int hitpoint);

        int getDamage();

    private:
        string getSpecies();

    };



}




#endif //HW4_CYBERDEMON_H
