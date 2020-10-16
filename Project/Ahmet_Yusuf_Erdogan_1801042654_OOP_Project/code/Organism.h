//
// Ahmet Yusuf Erdoğan 1801042654
//

#ifndef PROJECT_ORGANISM_H
#define PROJECT_ORGANISM_H

#include "World.h"
class World;


class Organism {
protected:
    // constructor
    Organism(World* theWorld,int x, int y);

    //coordinates
    int x;
    int y;

    //type of the organism
    OrganismType type;
    //world pointer to access all elements of area
    World* world;


    //shows organism is poisonous or not
    bool isPoisonous;

    //shows organism is poisoned or not
    bool isPoisoned;

    //shows organism is moved or not
    bool moved;

    //shows organism is dead or not
    bool dead;

public:
    //getter of x
    int getX() const;

    //setter of x
    void setX(int x);

    //getter of y
    int  getY() const;

    //setter of y
    void setY(int y);

    //getter of type
    void setType(OrganismType type);

    //getter of x
    bool getisPoisonous() const;

    //setter of isPoisoned
    void setIsPoisonous(bool isPoisonous);

    //getter of isPoisoned
    bool getisPoisoned() const;

    //setter of isPoisoned
    void setIsPoisoned(bool isPoisoned);

    //getter of type
    virtual OrganismType getType() const = 0;

    //getter of moved
    bool virtual isMoved();

    //getter of dead
    bool virtual isDead()=0;

    // setter of moved
    void setMoved(bool moved);

    // moves the organism
    virtual void Move() = 0;

    //breeds organism
    virtual void Breed() = 0;

    //destructor
    virtual ~Organism() { }

    //choosing correct direction
    Direction DirectionDecision();

    //function that shows current coordinates is in area or not
    virtual bool in_Border(int x, int y);
};


#endif //PROJECT_ORGANISM_H
