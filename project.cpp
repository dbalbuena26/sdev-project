

#include <iostream>
#include "TicketMaster.h"

using namespace std;


int main() {

	int choice = 0;
	TicketMaster tm;

	do {
		while (true) {
			cout << "Please select an option:\n1: Display Seating Chart\n2: Request Tickets\n3: Print Sales Report\n4: Exit\n   ";
			cin >> choice;

			if (choice > 0 && choice < 5)
				break;
			else 
				cout << "Invalid entry. Please try again.\n\n";
		}

	
		switch (choice) {
			case 1: tm.displaySeats();
							break;
			case 2: tm.requestTicekts();
							break;
			case 3: tm.salesReport();
							break;
			case 4: cout << "Goodbye!\n";
							break;
		}
	} while (choice != 4);

	return 0;
}