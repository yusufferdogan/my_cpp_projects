//
// Ahmet Yusuf Erdoğan 1801042654
//

#include "Ants.h"
#include <cstdlib>
#include "Ants.h"
#include "Organism.h"
#include "PoisonousAnt.h"

//constructing the ant to given coordinates
Ants::Ants(World *theWorld, int x, int y) : Organism(theWorld, x, y) {
   type = ANT;
   WaitTillBreedCount = 0;
   setIsPoisonous(false);
   setIsPoisoned(false);
   moved = false;
}

OrganismType Ants::getType() const {
    return ANT;
}
//moving the ant
void Ants::Move() {
    RandomlyMakeAntPoisonous();// makes ant to poisonous ant
    Direction direction;
    if(!CanMove()) {
        direction = DirectionDecision();
        switch (direction) {
            case LEFT:
                // if left side is empty and in border of area
                if (world->getCell(x, y - 1) == nullptr && in_Border(x, y - 1)) {
                    // deletes the LEFT cell
                    delete world->getCell(x, y - 1);
                    //sets LEFT cell to this cell
                    world->setCell(this, x, y - 1);
                    //clears LEFT cell
                    world->Clear(x, y);
                    //decrements the coordinate y
                    y--;
                    // set moved to true
                    moved = true;
                }
                break;
            case RIGHT:
                if (world->getCell(x, y + 1) == nullptr && in_Border(x, y + 1)) {
                    // deletes the RIGHT cell
                    delete world->getCell(x, y + 1);
                    //sets RIGHT cell to this cell
                    world->setCell(this, x, y + 1);
                    //clears RIGHT cell
                    world->Clear(x, y);
                    //increments the coordinate y
                    y++;
                    // set moved to true
                    moved = true;
                }
                break;
            case DOWN:
                if (world->getCell(x + 1, y) == nullptr && in_Border(x + 1, y)) {
                    // deletes the DOWN cell
                    delete world->getCell(x + 1, y);
                    //sets DOWN cell to this cell
                    world->setCell(this, x + 1, y);
                    //clears DOWN cell
                    world->Clear(x, y);
                    //increments the coordinate x
                    x++;
                    // set moved to true
                    moved = true;
                }
                break;
            case UP:
                if (world->getCell(x - 1, y) == nullptr && in_Border(x - 1, y)) {
                    // deletes the UP cell
                    delete world->getCell(x - 1, y);
                    //sets UP cell to this cell
                    world->setCell(this, x - 1, y);
                    //clears UP cell
                    world->Clear(x, y);
                    //decrements the coordinate x
                    x--;
                    // set moved to true
                    moved = true;
                }
                break;
        }
    }
    WaitTillBreedCount++;

}

void Ants::Breed() {
    // if ant waits enough
    if(WaitTillBreedCount > STEP_COUNT_TO_WAIT_BREED_ANT){
        //if left cell empty and in border
        if(world->getCell(x,y+1) == nullptr){
            if( in_Border(x,y+1) ){
                //creates new ant
                new Ants(this->world, x, y+1);
                //sets counter to 0
                WaitTillBreedCount = 0;
            }
        }
        //if right cell empty and in border
        else if(world->getCell(x,y-1) == nullptr){
            if( in_Border(x,y-1) ){
                //creates new ant
                new Ants(this->world, x, y-1);
                //sets counter to 0
                WaitTillBreedCount = 0;
            }
        }
        //if down cell empty and in border
        else if(world->getCell(x+1,y) == nullptr){
            if( in_Border(x+1,y)){
                //creates new ant
                new Ants(this->world, x+1, y);
                //sets counter to 0
                WaitTillBreedCount = 0;
            }
        }
        //if right cell empty and in border
        else if(world->getCell(x-1,y) == nullptr){
            if( in_Border(x-1,y) ){
                //creates new ant
                new Ants(this->world, x-1, y);
                //sets counter to 0
                WaitTillBreedCount = 0;
            }
        }
    }
}
//shows coordinates is in border
bool Ants::in_Border(int x, int y)
{
    return (x >= 0) && (x < WORLD_SIZE) && (y >= 0) && (y < WORLD_SIZE);
}
// Randomly Makes Ant to Poisonous ant
void Ants::RandomlyMakeAntPoisonous() {
    int chance = rand()%100 ;
    // %5 for example
    if (chance <  CHANCE_OF_BECOMING_POISONOUS){
        //makes this ant to poisonous ant
        new PoisonousAnt(this->world, x, y);
    }
}
// does have empty cell around
bool Ants::CanMove() {
    return in_Border(x,y+1) ||  in_Border(x,y-1)  ||  in_Border(x+1,y) || in_Border(x-1,y);
}
// is dead
bool Ants::isDead(){
    return dead;
}
