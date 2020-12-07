// Rimworld resources to products calculator

#include<vector>
#include<iostream>
#include <map>
#include<string>

using namespace std;



// NEEDED: KEYS (WOOD, STEEL, PLASTEEL, CHEMFUEL, CLOTH)
// Values (Tables, guns, marine armor, explosive shells, shirts)
// User must be able to choose what material to use, amount, and calculate the amount of products made.

// keys: 

// values: 

// map<string, Resources>


class resources {
    public:

    int wood = 100;
    int steel = 100;
    int plasteel = 100;
    int chemfuel = 100;
    int cloth = 100;



};



class item {

    public:
    string name;
    resources cost;



};

// build a check function
bool checkResources (item * i){


    // make a boolean to represent if you can build item

    bool canBuild = true;

    // compares checkResources "i" with storedResources

    if (i->cost.wood < storedResources->wood) {
        cout << "Enough wood for anything wooden" << '\n';
    };
    if (i->cost.steel < storedResources->steel) {
        cout << "Enough steel for weapons" << '\n';
    };
    if (i->cost.plasteel < storedResources->plasteel) {
        cout << "Enough plasteel for armor" << '\n';
    };
    if (i->cost.chemfuel < storedResources->chemfuel) {
        cout << "Enough chemfuel for anything explosive" << '\n';
    };
    if (i->cost.cloth < storedResources->cloth) {
        cout << "Enough cloth for clothing" << '\n';
    }; 

}

bool build_item (item * i) { // put resources here and check if there's availible resources



    if (checkResources(i)) { // subtract cost of i in storedResources
        cout << "Can build stuff!" << '\n'; 
    // then add product to built items
        


    };

    // if there is enough, subtract from stored resources and start building

    //woodInput;
    //steelInput;
    //plasteelInput;
    //chemfuelInput;
    //clothInput;


    
};

vector<item> built_items; // put finished products here
// compare with global resources
resources* storedResources;




void printResults() {

    cout << "Wood: " << '\n';
    cout << "Steel: " << '\n';
    cout << "Plasteel: " << '\n';
    cout << "Chemfuel: " << '\n';
    cout << "Cloth: " << '\n';


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

    //calculations
    int woodOutput = woodInput / 28;
    int steelOutput = steelInput / 60;
    int plasteelOutput = plasteelInput / 100;
    int chemfuelOutput = chemfuelInput / 15;
    int clothOutput = clothInput / 80;

    cout << "With these resources, you can make..." << '\n';
    cout << woodOutput << " table(s)." << '\n';
    cout << steelOutput << " bolt-action rifle(s)." << '\n';
    cout << plasteelOutput << " marine armor(s)." << '\n';
    cout << chemfuelOutput << " mortar shell(s)." << '\n';
    cout << clothOutput << " duster(s)" << '\n';


}


int main() {
	printf("Loading program...\n");
    chooseChoice();
    checkResources;
}

