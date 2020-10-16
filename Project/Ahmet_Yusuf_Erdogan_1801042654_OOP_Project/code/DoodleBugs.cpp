//
// Ahmet Yusuf Erdoğan 1801042654
//

#include <cstdlib>
#include "DoodleBugs.h"
#include "World.h"
#include <iostream>
// Consstructor of doodlebug
DoodleBugs::DoodleBugs(World *theWorld, int x, int y) : Organism(theWorld, x, y) {
    WaitTillBreedCount = 0;
    HungryStepCount = 0;
    type = DOODLEBUG;
    isPoisonous = false;
    isPoisoned = false;
    moved = false;
}

OrganismType DoodleBugs::getType() const {
    return DOODLEBUG;
}
// move function for doodlebug
void DoodleBugs::Move() {

    // if right side is empty and in border of area
    if(world->getCell(x,y+1) != nullptr){
        // if right side is a ant
        if(world->getCell(x,y+1)->getType() == ANT || world->getCell(x,y+1)->getType() == POISONOUSANT)
        {
            // become poisoned
            if(world->getCell(x,y+1)->getType() == POISONOUSANT){

                setIsPoisoned(true);
                std::cout << x << " " << y+1 << "\tATE to POISONOUS ANT\n";
            }
            else{
                std::cout << x << " " << y << "\tATE to RIGHT\n";
            }
            /*
            *   deletes the RIGHT cell
            *   sets RIGHT cell to this cell
            *   clears RIGHT cell
            *   decrements the coordinate y
            *   set moved to true
            */
            delete world->getCell(x, y + 1);
            world->setCell(world->getCell(x, y),x,y+1);
            world->Clear(x,y);
            y ++;
            moved = true;
            HungryStepCount = 0;
        }
    }
    else if(world->getCell(x,y-1) != nullptr){
        if( world->getCell(x,y-1)->getType() == ANT || world->getCell(x,y-1)->getType() == POISONOUSANT){
            if(world->getCell(x,y-1)->getType() == POISONOUSANT){
                std::cout << x << " " << y-1 << "\tATE to POISONOUS ANT\n";
                setIsPoisoned(true);
            }
            else{
                std::cout << x << " " << y << "\tATE to LEFT\n";
            }
            delete world->getCell(x, y - 1);
            //world->getCell(x, y)
            world->setCell(this,x,y-1);
            world->Clear(x,y);
            y --;
            moved = true;
            HungryStepCount = 0;
            /*
             *   deletes the LEFT cell
             *   sets LEFT cell to this cell
             *   clears LEFT cell
             *   decrements the coordinate y
             *   set moved to true
             */
        }
    }
    else if(world->getCell(x+1,y) != nullptr){
        if(  world->getCell(x+1,y)->getType() == ANT  || world->getCell(x+1,y)->getType() == POISONOUSANT){
            if(world->getCell(x+1,y)->getType() == POISONOUSANT){
                std::cout << x+1 << " " << y << "\tATE to POISONOUS ANT\n";
                setIsPoisoned(true);
            }
            else{
                std::cout << x << " " << y << "\tATE to DOWN\n";
            }
            delete world->getCell(x + 1, y);
            world->setCell(this,x+1,y);
            world->Clear(x,y);
            x++;
            moved = true;
            HungryStepCount = 0;
            /*
             *   deletes the DOWN cell
             *   sets DOWN cell to this cell
             *   clears DOWN cell
             *   decrements the coordinate y
             *   set moved to true
             */
        }
    }
    else if(world->getCell(x-1,y) != nullptr){
        if( world->getCell(x-1,y)->getType() == ANT  || world->getCell(x-1,y)->getType() == POISONOUSANT ){
            if(world->getCell(x-1,y)->getType() == POISONOUSANT){
                std::cout << x-1 << " " << y << "\tATE to POISONOUS ANT\n";
                setIsPoisoned(true);
            }
            else{
                std::cout << x << " " << y << "\tATE to UP\n";
            }
            delete world->getCell(x - 1, y);
            world->setCell(this,x-1,y);
            world->Clear(x,y);
            x--;
            moved = true;
            HungryStepCount = 0;
            /*
             *   deletes the UP cell
             *   sets UP cell to this cell
             *   clears UP cell
             *   decrements the coordinate y
             *   set moved to true
             */
        }
    }
    else {
        HungryStepCount++;
    }

    if(getisPoisoned()){
        PoisonedStepCount++;
    }
    WaitTillBreedCount++;

    if (!moved){
        Direction direction;
        // if there is no ant around it just moves randomly
        direction = DirectionDecision();
        switch (direction){
            case LEFT:
                if(world->getCell(x,y-1) == nullptr && in_Border(x,y-1) ) {
                    world->setCell(this,x,y-1);
                    world->Clear(x,y);
                    moved = true;
                    y--;
                    std::cout << x << " " << y << "\tMOVED to LEFT\n";
                }
                break;
            case RIGHT:
                if(world->getCell(x,y+1) == nullptr && in_Border(x,y+1) ) {
                    world->setCell(this,x,y+1);
                    world->Clear(x,y);
                    moved = true;
                    y++;
                    std::cout << x << " " << y << "\tMOVED to RIGHT\n";
                }
                break;
            case DOWN:
                if(world->getCell(x+1,y) == nullptr && in_Border(x+1,y) ) {
                    world->setCell(this,x+1,y);
                    world->Clear(x,y);
                    moved = true;
                    x++;
                    std::cout << x << " " << y << "\tMOVED to DOWN \n";
                }
                break;
            case UP:
                if(world->getCell(x-1,y) == nullptr && in_Border(x-1,y) ) {
                    world->setCell(this,x-1,y);
                    world->Clear(x,y);
                    moved = true;
                    x--;
                    std::cout << x << " " << y << "\tMOVED to UP\n";
                }
                break;
        }

    }
}

void DoodleBugs::Breed() {
    // if it waits enough it breeds
    if(WaitTillBreedCount > STEP_COUNT_TO_WAIT_BREED_DOODLE_BUG){
        //cell empty and in border
        if(world->getCell(x,y+1) == nullptr){
            if( in_Border(x,y+1) ){
                new DoodleBugs(this->world, x, y+1);
                WaitTillBreedCount = 0;
                std::cout << x << " " << y << "\tBREED to RIGHT\n";
            }
        }
        //cell empty and in border
        else if(world->getCell(x,y-1) == nullptr){
            if( in_Border(x,y-1) ){
                new DoodleBugs(this->world, x, y-1);
                WaitTillBreedCount = 0;
                std::cout << x << " " << y << "\tBREED to LEFT\n";
            }
        }
        //cell empty and in border
        else if(world->getCell(x+1,y) == nullptr){
            if( in_Border(x+1,y)){
                new DoodleBugs(this->world, x+1, y);
                WaitTillBreedCount = 0;
                std::cout << x << " " << y << "\tBREED to DOWN\n";
            }
        }
        //cell empty and in border
        else if(world->getCell(x-1,y) == nullptr){
            if( in_Border(x-1,y) ){
                new DoodleBugs(this->world, x-1, y);
                std::cout << x << " " << y << "\tBREED to UP\n";
                WaitTillBreedCount = 0;
            }
        }
    }
}
bool DoodleBugs::in_Border(int x, int y)
{
    return (x >= 0) && (x < WORLD_SIZE) && (y >= 0) && (y < WORLD_SIZE);
}

bool DoodleBugs::CanMove() {
    return in_Border(x,y+1) ||  in_Border(x,y-1)  ||  in_Border(x+1,y) || in_Border(x-1,y);
}

bool DoodleBugs::Starve() {
    return HungryStepCount >= STEP_COUNT_WITH_HUNGER;
}

bool DoodleBugs::isDead() {
    if (PoisonedStepCount >= STEP_COUNT_WITH_POISON)
        std::cout << x << " " << y <<  "\tDIED because of POISON\n";
    if(Starve())
        std::cout << x << " " << y <<  "\tDIED because of STARVE\n";
    return Starve() || PoisonedStepCount >= 2;
}
