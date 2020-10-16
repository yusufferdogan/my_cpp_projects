#include <iostream>
#include "Creature.h"
#include "Demon.h"
#include "Balrog.h"
#include "Cyberdemon.h"
#include "Elf.h"
#include "Human.h"
using namespace Yusuf;
using namespace std;
int main() {


    srand(time(0));

    Creature defaultCreature; // eğer bunu oluştutuurdan götünü sikerim ananımın amıan koyar0üıaüfeadhfıü0eadshgfü*09ewgh80
    Human h1;
    Elf e1;
    Cyberdemon c1;
    Balrog b1;

    Human h(20, 30);
    Elf e(40, 50);
    Cyberdemon c(60, 70);
    Balrog b(80, 90);

int damage = 0 ;

    /*for (int i = 0; i < 10; i++){
        cout << "--------------------------------\n";
        //cout << "Human attacks for " << damage;
        damage = defaultCreature.getDamage();
        //cout << "\nTotal damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;*/

    for (int i = 0; i < 10; i++){
        cout << "--------------------------------\n";
        damage = h.getDamage();
        //cout << "\nTotal damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    for (int i = 0; i < 10; i++){
        cout << "--------------------------------\n";
        damage = e.getDamage();
        //cout << "\nTotal damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    for (int i = 0; i < 10; i++){
        cout << "--------------------------------\n";

        damage = c.getDamage();
        //out << "\nTotal damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    for (int i = 0; i < 10; i++){
        cout << "--------------------------------\n";

        damage = b.getDamage();
        //cout << "\nTotal damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;
}