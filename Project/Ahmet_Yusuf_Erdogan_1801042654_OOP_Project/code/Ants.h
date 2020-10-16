//
// Ahmet Yusuf Erdoğan 1801042654
//

#ifndef PROJECT_ANTS_H
#define PROJECT_ANTS_H


#include "Organism.h"
class Ants : public Organism{
public:
    //constructing the ant to given coordinates
    Ants(World *theWorld, int x, int y);

    OrganismType getType() const;

    //moving the ant
    void Move() ;

    //moving the ant
    void Breed() ;

    void RandomlyMakeAntPoisonous();

    // does have empty cell around
    bool CanMove();

    bool in_Border(int xx, int yy);

    bool isDead();

    // if it breeds it becomes 0 if not breed is increments
    int WaitTillBreedCount;
};
#endif //PROJECT_ANTS_H
