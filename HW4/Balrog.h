//
// Created by yusuf on 01.06.2020.
//

#ifndef HW4_BALROG_H
#define HW4_BALROG_H


#include "Demon.h"
#include <iostream>

namespace Yusuf{
    class Balrog : public Demon{
    public:
        Balrog( int strength, int hitpoint);

        Balrog();

        int getDamage();

    private:
        string getSpecies();

    };

}


#endif //HW4_BALROG_H
