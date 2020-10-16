//
// Ahmet Yusuf Erdoğan 1801042654
//

#include <cstdlib>
#include "Organism.h"

using namespace std;
//getter of x
int Organism::getX() const {
    return x;
}
//setter of x
void Organism::setX(int x) {
    Organism::x = x;
}
//getter of y
int Organism::getY() const {
    return y;
}
//setter of y
void Organism::setY(int y) {
    Organism::y = y;
}
// constructor
Organism::Organism(World* theWorld, int x, int y) : world(theWorld), x(x),y(y) {
    theWorld->setCell(this,x,y);
    dead = false;
}
//setter of type
void Organism::setType(OrganismType Type) {
    type = Type;
}
//getter of type
OrganismType Organism::getType() const {
    return ANT;
}
//setter of isPoisoned
bool Organism::getisPoisoned() const {
    return isPoisoned;
}
//setter of isPoisonous
void Organism::setIsPoisonous(bool isPoisonous) {
    Organism::isPoisonous = isPoisonous;
}
//setter of isPoisoned
void Organism::setIsPoisoned(bool isPoisoned) {
    Organism::isPoisoned = isPoisoned;
}
//getter of isPoisonous
bool Organism::getisPoisonous() const {
    return isPoisonous;
}
//getter of moved
bool Organism::isMoved() {
    return moved;
}
//setter of moved
void Organism::setMoved(bool moved) {
    Organism::moved = moved;
}
//choosing correct direction
Direction Organism::DirectionDecision(){
    Direction dir[] = {LEFT,RIGHT,UP,DOWN};
    int d;
    bool flag = false;
    do{
        d = rand()%4;
        if (dir[d] == LEFT && in_Border(x,y-1))
            flag = true;
        else if (dir[d] == RIGHT && in_Border(x,y+1))
            flag = true;
        else if (dir[d] == UP && in_Border(x-1,y))
            flag = true;
        else if (dir[d] == DOWN && in_Border(x+1,y))
            flag = true;
    }while(!flag);
    return dir[d];
}
//function that shows current coordinates is in area or not
bool Organism::in_Border(int x, int y)
{
    return (x >= 0) && (x < WORLD_SIZE) && (y >= 0) && (y < WORLD_SIZE);
}
