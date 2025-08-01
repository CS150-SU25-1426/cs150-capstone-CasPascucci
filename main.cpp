#include "SpoolList.h"
#include "FilamentSpool.h"
#include "ExtendedFilamentSpool.h"
#include <iostream>
#include <iomanip>
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
	string vendor;
	string purchaseDate;
	bool isOpen;
	string extendedChoice;

	cout << std::fixed << std::setprecision(2); // Set precision for floating-point output

	// Main menu loop

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
			cout << "Enter an extended spool? (Includes vendor, purchase date, and open status) (y/n): ";
			cin >> extendedChoice;
			cin.ignore(); // Ignore the newline character after the choice
			if (extendedChoice == "y" || extendedChoice == "Y") {
				cout << "Enter Vendor: ";
				std::getline(cin, vendor);
				cout << "Enter Purchase Date (YYYY-MM-DD): ";
				std::getline(cin, purchaseDate);
				cout << "Is the spool open? (1 for Yes, 0 for No): ";
				cin >> isOpen;
				cin.ignore(); // Ignore the newline character after the choice
				ExtendedFilamentSpool* extendedSpool = new ExtendedFilamentSpool(id, material, color, diameterMM, totalGrams, remainingGrams, costPerKg, vendor, purchaseDate, isOpen);
				inventory.addSpool(extendedSpool);
			} else {
				FilamentSpool* spool = new FilamentSpool(id, material, color, diameterMM, totalGrams, remainingGrams, costPerKg);
				inventory.addSpool(spool);
			}
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