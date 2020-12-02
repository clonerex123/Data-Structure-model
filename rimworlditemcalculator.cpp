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

    int wood;
    int steel;
    int plasteel;
    int chemfuel;
    int cloth;


};

class item {
    // not being used right now

    string name;
    resources cost;


};

void build_item(item i) { // put resources here and check if there's availible resources
    // if there is enough, subtract from stored resources and start building
    // then add product to built items

    woodInput;
    steelInput;
    plasteelInput;
    chemfuelInput;
    chemfuelInput;
    clothInput;



};

vector<item> built_items; // put finished products here
resources* storedResources;
resources* woodInput;
resources* steelInput;
resources* plasteelInput;
resources* chemfuelInput;
resources* clothInput;


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

}

