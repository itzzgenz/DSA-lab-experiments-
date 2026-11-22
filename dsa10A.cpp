
#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

void insert(int key) {
    int index = key % SIZE;
    int start = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;

        if (index == start) {
            cout << "Hash Table Full\n";
            return;
        }
    }

    hashTable[index] = key;
    cout << "Inserted Successfully\n";
}

void display() {
    cout << "\nHash Table:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";

        if (hashTable[i] == -1)
            cout << "Empty";
        else
            cout << hashTable[i];

        cout << endl;
    }
}

int main() {
    int choice, key;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    do {
        cout << "\n1.Insert\n2.Display\n3.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                insert(key);
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
