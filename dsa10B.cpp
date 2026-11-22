
#include <iostream>
using namespace std;

#define SIZE 10

int parking[SIZE];

void parkVehicle(int vehicle) {
    int slot = vehicle % SIZE;
    int start = slot;

    while (parking[slot] != -1) {
        slot = (slot + 1) % SIZE;

        if (slot == start) {
            cout << "Parking Full\n";
            return;
        }
    }

    parking[slot] = vehicle;
    cout << "Vehicle Parked at Slot " << slot << endl;
}

void display() {
    cout << "\nParking Slots:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << "Slot " << i << " : ";

        if (parking[i] == -1)
            cout << "Empty";
        else
            cout << parking[i];

        cout << endl;
    }
}

int main() {
    int choice, vehicle;

    for (int i = 0; i < SIZE; i++)
        parking[i] = -1;

    do {
        cout << "\n1.Park Vehicle\n2.Display Slots\n3.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Vehicle Number: ";
                cin >> vehicle;
                parkVehicle(vehicle);
                break;

            case 2:
                display();
                break;

            case 3:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid Choice\n";
        }
    } while (choice != 3);

    return 0;
}
