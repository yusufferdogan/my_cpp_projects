//
// Ahmet Yusuf Erdoğan 1801042654
//

#include <cstdlib>
#include <iostream>
#include "PoisonousAnt.h"
// constructor of poisonous ant
PoisonousAnt::PoisonousAnt(World *theWorld, int x, int y) : Ants(theWorld, x, y) {
    type = POISONOUSANT;
    WaitTillBreedCount = 0;
    setIsPoisonous(true);
    setIsPoisoned(false);
    moved = false;
}
// breed function of poisonous ant
void PoisonousAnt::Breed() {
    // if if waits enough
    if(WaitTillBreedCount > STEP_COUNT_TO_WAIT_BREED_POISONOUS_ANT){
        // if it has empty cell around
        if (!CanMove()){
            // breeds to empty cell
            if(world->getCell(x,y+1) == nullptr && in_Border(x,y+1)){
                new PoisonousAnt(this->world, x, y+1);
                WaitTillBreedCount = 0;
            }
            else if(world->getCell(x,y-1) == nullptr && in_Border(x,y-1)){
                new PoisonousAnt(this->world, x, y-1);
                WaitTillBreedCount = 0;
            }
            else if(world->getCell(x+1,y) == nullptr && in_Border(x+1,y)){
                new PoisonousAnt(this->world, x+1, y);
                WaitTillBreedCount = 0;
            }
            else if(world->getCell(x-1,y) == nullptr && in_Border(x-1,y)){
                new PoisonousAnt(this->world, x-1, y);
                WaitTillBreedCount = 0;
            }
        }
        // if it has not empty cell around
        else {
            int d = rand()%4;
            // takes randomly one position
            // and not cares what exist there fights and kills it and breeds there
            switch (d){
                case UP:
                    if(world->getCell(x,y-1) != nullptr && in_Border(x,y-1) ) {
                        new PoisonousAnt(this->world, x, y-1);
                        WaitTillBreedCount = 0;
                    }
                    break;
                case DOWN:
                    if(world->getCell(x,y+1) != nullptr && in_Border(x,y+1) ) {
                        new PoisonousAnt(this->world, x, y+1);
                        WaitTillBreedCount = 0;
                    }
                    break;
                case RIGHT:
                    if(world->getCell(x+1,y) != nullptr && in_Border(x+1,y) ) {
                        new PoisonousAnt(this->world, x+1, y);
                        WaitTillBreedCount = 0;
                    }
                    break;
                case LEFT:
                    if(world->getCell(x-1,y) != nullptr && in_Border(x-1,y) ) {
                        new PoisonousAnt(this->world, x-1, y);
                        WaitTillBreedCount = 0;
                    }
                    break;
            }
        }

    }
}
bool PoisonousAnt::in_Border(int x, int y)
{
    return (x >= 0) && (x < WORLD_SIZE) && (y >= 0) && (y < WORLD_SIZE);
}
void PoisonousAnt::Move() {

    Direction direction = DirectionDecision();
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

    WaitTillBreedCount++;

}
OrganismType PoisonousAnt::getType() const {
    return POISONOUSANT;
}
