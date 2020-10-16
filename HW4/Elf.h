//
// Created by yusuf on 01.06.2020.
//

#ifndef ELF_H
#define ELF_H


#include "Creature.h"

namespace Yusuf {
    class Elf : public Creature{

    public:
        Elf();

        Elf(int strength, int hitpoint);

        int getDamage();

    private:
        string getSpecies();

    };

}


#endif //HW4_ELF_H
