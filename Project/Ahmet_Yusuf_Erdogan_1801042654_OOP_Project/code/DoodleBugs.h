//
// Ahmet Yusuf Erdoğan 1801042654
//

#ifndef PROJECT_DOODLEBUGS_H
#define PROJECT_DOODLEBUGS_H


#include "Organism.h"


class DoodleBugs : public Organism {
public:
    DoodleBugs(World *theWorld, int x, int y);

    //returns the type of the organism
    OrganismType getType() const;

    /*
     * This function is also used for eating ants .
     * Firstly an ant search an ant .
     * If there is an ant around the doodllebug ,
     * it eats if not exist doodlebug makes a random move .
     * */

    void Move() ;

    /*
     * If doodlebug watis enough to breed it searchs for an empty cell.
     * If it find an empty cell it breeds
     * if it could’nt find it waits for next step.
     * */
    void Breed() ;

    bool CanMove();

    /*
     * shows the doodlebug is dead or not.
     * Poison death or starve may cause death.
     * Couldnt eating an ant STEP_COUNT_WITH_HUNGER steps and
     * STEP_COUNT_WITH_POISON steps after eating poisonous ant
     * is the reasons of death
     *
     */

    bool Starve();

    bool in_Border(int x, int y);

    bool isDead();
private:

    // This variable shows steps that could’nt eat ant
    int HungryStepCount;

    //This variable shows steps that could’nt breed
    int WaitTillBreedCount;

    //This variable shows that how many step pasted after became poisioned
    int PoisonedStepCount;


};


#endif //PROJECT_DOODLEBUGS_H
