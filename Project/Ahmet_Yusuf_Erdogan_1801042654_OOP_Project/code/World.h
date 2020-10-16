//
// Ahmet Yusuf Erdoğan 1801042654
//

#ifndef PROJECT_WORLD_H
#define PROJECT_WORLD_H

const int WORLD_SIZE = 20;

const int INITAL_ANT_NUMBER = 100;

const int INITIAL_DOODLEBUG_COUNT = 5;

//how many count after doodlebug going to die from poison
const int STEP_COUNT_WITH_POISON = 2;

//how many count after doodlebug going to die
const int STEP_COUNT_WITH_HUNGER = 3;

//percantage of the becoming poisionus
const int CHANCE_OF_BECOMING_POISONOUS = 2;

const int STEP_COUNT_TO_WAIT_BREED_ANT = 3;

const int STEP_COUNT_TO_WAIT_BREED_DOODLE_BUG = 3;

const int STEP_COUNT_TO_WAIT_BREED_POISONOUS_ANT = 4;

enum OrganismType{DOODLEBUG = 0,ANT = 1,POISONOUSANT = 2};

enum Direction{RIGHT = 0,LEFT,UP,DOWN};

class Organism;
#include "Organism.h"

class World {
public:
    Organism *area[WORLD_SIZE][WORLD_SIZE];

    void setCell(Organism* organism ,int x,int y);

    Organism* getCell(int x,int y);

    void initCells();

    void CreateOrganism(OrganismType type, int x, int y);

    void CreateWorld();

    void Clear(int x, int y);

    void ClearOrganism();

    void BreedOrganisms();

    void print() const;

    void simulateOneStep();

    void resetOrganisms();

    ~World();

    void MoveANT();

    void MoveDOODLEBUG();

    void MovePOISONOUSANT();
};




#endif //PROJECT_WORLD_H
