// Rimworld resources to products calculator

#include<vector>
#include<iostream>
#include <map>
#include<string>
#include "ConsoleApplication1.h"

using namespace std;



// NEEDED: KEYS (WOOD, STEEL, PLASTEEL, CHEMFUEL, CLOTH)
// Values (Tables, guns, marine armor, explosive shells, shirts)
// User must be able to choose what material to use, amount, and calculate the amount of products made.

// keys: 

// values: 

// map<string, Resources>


class resources {
    public:

    int wood;
    int steel;
    int plasteel;
    int chemfuel;
    int cloth;

};


class item {

    public:
    string name;
    resources cost;

};

vector<item> built_items; // put finished products here


int table = 0;
int gun = 0;
int armor = 0;
int shells = 0;
int clothes = 0;

// compare with global resources
resources* storedResources;



// build a check function
bool checkResources (item * i){

    // make a boolean to represent if you can build item

    bool canBuild = false;

    // compares checkResources "i" with storedResources

    if (i->cost.wood < storedResources->wood) {
        cout << "Enough wood for anything wooden" << '\n';
        canBuild = true;
        return canBuild;
    };
    if (i->cost.steel < storedResources->steel) {
        cout << "Enough steel for weapons" << '\n';
        canBuild = true;
        return canBuild;
    };
    if (i->cost.plasteel < storedResources->plasteel) {
        cout << "Enough plasteel for armor" << '\n';
        canBuild = true;
        return canBuild;
    };
    if (i->cost.chemfuel < storedResources->chemfuel) {
        cout << "Enough chemfuel for anything explosive" << '\n';
        canBuild = true;
        return canBuild;
    };
    if (i->cost.cloth < storedResources->cloth) {
        cout << "Enough cloth for clothing" << '\n';
        canBuild = true;
        return canBuild;
    };
 
    return canBuild;
}

void build_item (item * i) { // put resources here and check if there's availible resources

    if (checkResources(i)) { // subtract cost of i in storedResources
        cout << "Can build stuff!" << '\n'; 
        // then add product to built items
        
        storedResources->wood = storedResources->wood - i->cost.wood;  // subtracts stored wood with cost of wood for item i
        storedResources->steel = storedResources->steel - i->cost.steel;
        storedResources->plasteel = storedResources->plasteel - i->cost.plasteel;
        storedResources->chemfuel = storedResources->chemfuel - i->cost.chemfuel;
        storedResources->cloth = storedResources->cloth - i->cost.cloth;
        // with individual resources subtracted, add item to vector built_items

        built_items.push_back(*i);

    };
    
};

void printResults() {

    cout << "Built items vector: " << '\n';

    for (item i : built_items) {
        // for loop hands you each element of the vector one at a time
        // and stores it in i

        cout << "item = " << i.name << '\n';
    };

    //cout << "Tables: " << table << '\n';
    //cout << "Guns: " << gun << '\n';
    //cout << "Marine Armor: " << armor << '\n';
    //cout << "Mortar Shells: " << shells << '\n';
    //cout << "Dusters: " << clothes << '\n';

};


string userInput;
char replay('y');


void chooseChoice() {

    cout << "Welcome to the RimWorld manufactured item calculator!" << '\n';

    int woodInput = 0;
    int steelInput = 0;
    int plasteelInput = 0;
    int chemfuelInput = 0;
    int clothInput = 0;

    int userInput = 0;


    do {

        cout << "Choose a material to process (1)Wood, (2)Steel, (3)Plasteel, (4)Chemfuel, (5)Cloth" << '\n';
        
        cin >> userInput;

        switch (userInput) {

        case 1: cout << "Enter the amount of wood: "; cin >> woodInput; break;

        case 2: cout << "Enter the amount of steel: "; cin >> steelInput; break;

        case 3: cout << "Enter the amount of plasteel: "; cin >> plasteelInput; break;

        case 4: cout << "Enter the amount of chemfuel: "; cin >> chemfuelInput; break;

        case 5: cout << "Enter the amount of cloth: "; cin >> clothInput; break;

        }

        cout << "Would you like to repeat? Y/N" << '\n';
        cin >> replay;

    } while (replay == 'Y' || replay == 'y');

    cout << "The total resourses are:" << '\n';
    cout << "Wood: " << woodInput << '\n';
    cout << "Steel: " << steelInput << '\n';
    cout << "Plasteel: " << plasteelInput << '\n';
    cout << "Chemfuel: " << chemfuelInput << '\n';
    cout << "Cloth: " << clothInput << '\n';

    storedResources = new resources();
    storedResources->wood = woodInput;
    storedResources->steel = steelInput;
    storedResources->plasteel = plasteelInput;
    storedResources->chemfuel = chemfuelInput;
    storedResources->cloth = clothInput;

    //HARD CODED PROGRAMMING BELOW

    //int woodOutput = woodInput / 28;
    //int steelOutput = steelInput / 60;
    //int plasteelOutput = plasteelInput / 100;
  //  int chemfuelOutput = chemfuelInput / 15;
//    int clothOutput = clothInput / 80;

   // cout << "With these resources, you can make..." << '\n';
 //   cout << woodOutput << " table(s)." << '\n';
 //   cout << steelOutput << " bolt-action rifle(s)." << '\n';
 //   cout << plasteelOutput << " marine armor(s)." << '\n';
 //   cout << chemfuelOutput << " mortar shell(s)." << '\n';
 //   cout << clothOutput << " duster(s)" << '\n';

}

int main() {
	printf("Loading program...\n");

    chooseChoice();

    

    item* table = new item();
    table->name = "table";
    resources* tres = new resources();
    tres->wood = 28;
    table->cost = *tres;
    build_item(table);

    item* gun = new item();
    gun->name = "gun";
    resources* gres = new resources();
    gres->steel = 60;
    gun->cost = *gres;
    build_item(gun);

    item* armor = new item();
    armor->name = "armor";
    resources* ares = new resources();
    ares->plasteel = 100;
    armor->cost = *ares;
    build_item(armor);

    item* shells = new item();
    shells->name = "shells";
    resources* sres = new resources();
    sres->chemfuel = 15;
    shells->cost = *sres;
    build_item(shells);

    item* clothes = new item();
    clothes->name = "clothes";
    resources* cres = new resources();
    cres->cloth = 80;
    clothes->cost = *cres;
    build_item(clothes);

    printResults();

}

