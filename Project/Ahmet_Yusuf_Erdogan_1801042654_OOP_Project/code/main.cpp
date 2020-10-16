//Ahmet Yusuf Erdoğan 1801042654
#include <iostream>
#include "Organism.h"
#include "Ants.h"
#include "DoodleBugs.h"


using namespace std;
int main() {
    srand(time(NULL));

    World myWorld;

    myWorld.CreateWorld();

    myWorld.print();

    int i = 0;
    cout << "Step: " << i++ << endl;

    while (getchar()) {
        myWorld.simulateOneStep();
        myWorld.print();
        cout << "Step: " << i++ << endl;

    }
    return 0;
}
