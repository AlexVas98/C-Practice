#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "GenericBox.h"

using namespace std;

int main(int argc, char* argv[]) {
    int choice;

    // BoxForInt* ptr = nullptr; 
    
    GenericBox<int>* ptr = nullptr;

    while (true) {
        cout << " -------------------------- " << endl;
        cout << "            Menu " << endl;
        cout << " -------------------------- " << endl;

        if (ptr == nullptr) {
            cout << "    1. Create a box " << endl;
        }

        if (ptr != nullptr) {
            cout << "    2. Destroy a box " << endl;
            cout << "    3. Put a value in the box " << endl;
            cout << "    4. Get a value in the box and print it " << endl;
            cout << "    5. Print the value of the box " << endl;
        }

        cout << "    9. Exit program" << endl;
        cout << endl;

        cout << " - Enter your choice:";
        cin >> choice;

        if (choice == 1 && ptr == nullptr) {
            ptr = new GenericBox<int>();
        }

        if (choice == 2 && ptr != nullptr) {
            delete ptr;
            ptr = nullptr;
        }

        if (ptr != nullptr) {
            if (choice == 3) {
                int value;
                cout << "Please give the value:";
                cin >> value;

                ptr->put(value);
            }

            if (choice == 4) {
                int value;

                value = ptr->get();

                cout << "Value is: " << value << endl;
            }

            if (choice == 5) {
                ptr->print();
            }
        }

        if (choice == 9) {
            break;
        }
    }
    return 0;
}