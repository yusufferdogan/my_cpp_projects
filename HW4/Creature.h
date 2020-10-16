//
// Created by yusuf on 01.06.2020.
//

#ifndef CREATURE_H
#define CREATURE_H

#include <string>
using namespace std;

namespace Yusuf{

    class Creature {
    private:
        int Type;
        int Strength;
        int Hitpoint;
    public:
         string getSpecies();

        int getDamage();

        void setType(int type);

        void setStrength(int strength);

        void setHitpoint(int hitpoint);

        Creature();

        Creature(int strength, int hitpoint);

        int getType() const;

        int getStrength() const;

        int getHitpoint() const;


    };

}
#endif //HW4_CREATURE_H



