//
// Ahmet Yusuf Erdoğan 1801042654
//

#include <iostream>
#include "World.h"
#include "Ants.h"
#include "DoodleBugs.h"
#include "Organism.h"
using namespace std;
// Destructor that cleans the area array
World::~World() {
    for (int i = 0; i < WORLD_SIZE; i++) {
        for (int j = 0; j < WORLD_SIZE; j++) {
            if (area[i][j] != nullptr) {
                delete area[i][j];
            }
        }
    }
}
// setting the cell with given coordinates to the spesific organism
void World::setCell(Organism *organism, int x, int y) {
    if ((x >= 0) && (x < WORLD_SIZE) && (y >= 0) && (y < WORLD_SIZE)) {
        area[x][y] = organism;
    }
}
// getter of the cell with given coordinates
Organism *World::getCell(int x, int y) {
    if(area[x][y] != nullptr && ((x >= 0) && (x < WORLD_SIZE) && (y >= 0) && (y < WORLD_SIZE)))
        return area[x][y];
    else
        return nullptr;
}
//clears cell with given coordinates
void World::Clear(int x,int y){
    area[x][y] = nullptr;
}
// sets all cels to null
void World::initCells() {
    for (int i = 0; i < WORLD_SIZE; ++i) {
        for (int j = 0; j < WORLD_SIZE; ++j) {
            area[i][j] = nullptr;
        }
    }
}
// creates the cell with given coordinates with spesific organism
void World::CreateOrganism(OrganismType type,int x,int y) {
    if (type == ANT){
        if(area[x][y] == nullptr)
            new Ants(this,x,y);
    }
    if (type == DOODLEBUG){
        if(area[x][y] == nullptr)
            new DoodleBugs(this,x,y);
    }
}
// create all world and puts organisms randoomly
void World::CreateWorld() {
    initCells();
    int orgCount1 = 0;
    int orgCount2 = 0;

    int x,y;

    while (orgCount1 < INITAL_ANT_NUMBER)
    {
        x = rand() % WORLD_SIZE;
        y = rand() % WORLD_SIZE;
        if (area[x][y] == nullptr) {
            orgCount1++;

            CreateOrganism(ANT, x, y);
        }
    }
    while (orgCount2 < INITIAL_DOODLEBUG_COUNT)
    {
        x = rand() % WORLD_SIZE;
        y = rand() % WORLD_SIZE;
        if (area[x][y] == nullptr) {
            orgCount2++;
            CreateOrganism(DOODLEBUG, x, y);
        }
    }


}
//print function
void World::print() const {
    int numAnts = 0;
    int numBugs = 0;
    int numPoisonousAnts = 0;
    cout << endl << endl;
    cout << "    ";
    for (int i = 0; i < WORLD_SIZE; ++i){
        if(i > 9)
            cout << i << " ";
        else
            cout << i << "  ";
    }
    cout << endl;
    cout << "   ";
    for (int i = 0; i < WORLD_SIZE; ++i)
    {
        cout << "---";
    }
    cout << "-" << endl;
    for(int i = 0;i < WORLD_SIZE ;i++){
        if(i > 9)
            cout << i << " ";
        else
            cout << i << "  ";
        for(int j = 0;j < WORLD_SIZE ;j++){
            if(area[i][j] == nullptr){//blank
                cout << "| .";
            }
            else {
                if (area[i][j]->getType() == ANT)
                {
                    cout << "| O" ;
                    numAnts++;

                }
                else if (area[i][j]->getType() == DOODLEBUG){
                    cout << "| X" ;
                    numBugs++;
                }
                if(area[i][j]->getType() == POISONOUSANT){
                    cout << "| C";
                    numPoisonousAnts++;
                }

            }
            if(j == WORLD_SIZE-1){
                cout << "|" <<endl;
                cout << "   ";
                cout << "-";
                for (int i = 0; i < WORLD_SIZE; ++i)
                {
                    cout << "---";
                }
                cout<< endl;
            }
        }
    }
    cout << "\n\n\n\n\n";
    cout << "Ants: " << numAnts << " Bugs: " << numBugs << " Poisonous Ants: " << numPoisonousAnts << endl;
}
void World::simulateOneStep() {
    // The main routine that simulates one turn in the world:
    // 1. move bugs
    // 2. move ants
    // 3. make bugs starve (which happends under a certain condition)
    // 4. make the organisms breed (again which happens under a certain
    // condition).

    // Reset all organisms to not moved
    resetOrganisms();
    // Move the Doodlebugs
    MoveDOODLEBUG();

    // Move the ants
    MoveANT();

    // Move the  poisonous ants
    MovePOISONOUSANT();

    // Make the bugs starve
    ClearOrganism();

    //Make them breed
    BreedOrganisms();
}
// Move the Doodlebugs
void World::MoveDOODLEBUG() {
    for(int i = 0; i < WORLD_SIZE; i++)
    {
        for(int j = 0; j < WORLD_SIZE; j++)
        {
            if(area[i][j] != nullptr)
            {
                if(area[i][j]->getType() == DOODLEBUG && !(area[i][j]->isMoved()))
                {
                    area[i][j]->Move();
                }
            }
        }
    }
}
// Move the ants
void World::MoveANT() {
    for(int i = 0; i < WORLD_SIZE; i++)
    {
        for(int j = 0; j < WORLD_SIZE; j++)
        {
            if(area[i][j] != nullptr)
            {
                if(area[i][j]->getType() == ANT && !(area[i][j]->isMoved()))
                {
                    area[i][j]->Move();
                }
            }
        }
    }
}
// Move the  poisonous ants
void World::MovePOISONOUSANT() {
    for(int i = 0; i < WORLD_SIZE; i++)
    {
        for(int j = 0; j < WORLD_SIZE; j++)
        {
            if(area[i][j] != nullptr)
            {
                if(area[i][j]->getType() == POISONOUSANT && !(area[i][j]->isMoved()))
                {
                    area[i][j]->Move();
                }
            }
        }
    }
}
// deleting dead organisms
void World::ClearOrganism() {
    for (int i = 0; i < WORLD_SIZE; i++) {
        for (int j = 0; j < WORLD_SIZE; j++) {
            if ((area[i][j] != nullptr) && area[i][j]->isDead()) {
                delete area[i][j];
                Clear(i,j);
            }
        }
    }
}
// breeding organisms that waited for spesific time
void World::BreedOrganisms() {
    for(int i = 0; i < WORLD_SIZE; i++)
    {
        for(int j = 0; j < WORLD_SIZE; j++)
        {
            if(area[i][j] != nullptr)
            {
                area[i][j]->Breed();
            }
        }
    }
}
//reseting all organisms to not moved
void World::resetOrganisms() {
    for(int i = 0; i < WORLD_SIZE; i++)
    {
        for (int j = 0; j < WORLD_SIZE; j++)
        {
            if(area[i][j] != nullptr)
            {
                area[i][j]->setMoved(false);
            }
        }
    }
}
