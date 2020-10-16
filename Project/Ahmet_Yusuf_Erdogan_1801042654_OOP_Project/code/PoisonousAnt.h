//
// Ahmet Yusuf Erdoğan 1801042654
//

#ifndef PROJECT_POISONOUSANT_H
#define PROJECT_POISONOUSANT_H


#include "Ants.h"

class PoisonousAnt : public  Ants{

    OrganismType getType() const;

    bool in_Border(int x, int y);

    void Move();

    void Breed();

public:
    PoisonousAnt(World *theWorld, int x, int y);
};


#endif //PROJECT_POISONOUSANT_H
