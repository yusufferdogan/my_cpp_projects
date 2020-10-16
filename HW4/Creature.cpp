//
// Created by yusuf on 01.06.2020.
//
#include <iostream>
#include "Creature.h"
using namespace std;

namespace Yusuf{
    Creature::Creature() : Type(0), Strength(10), Hitpoint(10){}

    Creature::Creature(int strength, int hitpoint) :  Strength(strength), Hitpoint(hitpoint) {}

    string Creature::getSpecies()
    {
        /*switch (Type)
        {
            case 0: return "Human";
            case 1: return "Cyberdemon";
            case 2: return "Balrog";
            case 3: return "Elf";
        }
        return "unknown";*/
    }

    int Creature::getDamage() {
        int damage;

        damage = (rand() % Strength) + 1;

        return damage;

    }

    void Creature::setType(int type) {
        Type = type;
    }

    void Creature::setStrength(int strength) {
        Strength = strength;
    }

    void Creature::setHitpoint(int hitpoint) {
        Hitpoint = hitpoint;
    }

    int Creature::getType() const {
        return Type;
    }

    int Creature::getStrength() const {
        return Strength;
    }

    int Creature::getHitpoint() const {
        return Hitpoint;
    }


}
