#include "SpoolList.h"
#include "FilamentSpool.h"
#include <iostream>
using std::cout;
using std::cin;
using std::string;


int main() {
    SpoolList inventory;
    int choice = 0;
    string id;
    string material;
    string color;
    double diameterMM;
    double totalGrams;
    double remainingGrams;
    double costPerKg;

	do {
		cout << "************************************************************************\n";
		cout << "**                                                                    **\n";
		cout << "**                          WELCOME TO THE                            **\n";
		cout << "**                          3D PRINTER SHOP                           **\n";
		cout << "**                                                                    **\n";
		cout << "************************************************************************\n";
		cout << "** Please make a choice from the following options:                   **\n";
		cout << "** 1)  Add a new Filament to Inventory                                **\n";
		cout << "** 2)  Remove a Filament from Inventory                               **\n";
		cout << "** 3)  Display all Filaments in Inventory                             **\n";
		cout << "** 4)  Exit                                                           **\n";
		cout << "************************************************************************\n";
		cout << ">> ";
		cin >> choice;
    
		cin.ignore(); // To ignore the \n after choice (preventing brand from being "\n")
        string hold;

		switch (choice)
		{
		case 1:
		{

			cout << "Enter ID: ";
			std::getline(cin, id);
			cout << "Enter Material: ";
			std::getline(cin, material);
			cout << "Enter Color: ";
			std::getline(cin,color);
			cout << "Enter Diameter: ";
			cin >> diameterMM;
			cout << "Enter Total Grams: ";
			cin >> totalGrams;
			cout << "Enter Remaining Grams: ";
			cin >> remainingGrams;
			cout << "Enter Cost per Kg: ";
			cin >> costPerKg;

			FilamentSpool spool(id, material, color, diameterMM, totalGrams, remainingGrams, costPerKg);
			inventory.addSpool(spool);

			cout << std::endl;
			break;
		}
		case 2:
			cout << inventory << std::endl;
			cout << "\nWhich ID# would you like to remove? (or -1 to cancel) >> ";
			std::getline(cin, id);
			if (inventory.removeSpool(id)) {
		        	cout << "~~~Spool #" << id << " removed successfully~~~\n\n";
			} else {
			        cout << "~~~Spool #" << id << " not found\n\n";
			}
			
			break;
		case 3:
			cout << inventory;
            cout << "\nPress Enter to Continue\n";
			getline(cin, hold);
			break;
		case 4:
			cout << "Thanks for coming!\n";
			break;
		}

	} while (choice != 4);

    return 0;
}















// FilamentSpool spool1("spool1", "PLA", "Red", 1.75, 1000, 500, 20.0);
//     FilamentSpool spool2("spool2", "ABS", "Blue", 1.75, 1000, 1000, 25.0);
//     FilamentSpool spool3("spool3", "PETG", "Green", 1.75, 1000, 750, 30.0);