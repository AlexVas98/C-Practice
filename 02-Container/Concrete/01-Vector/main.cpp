#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>

#include "ContainerForInt.h"

using namespace std;

int main(int argc, char* argv[]) {
    int choice;

    ContainerForInt* ptr = nullptr;

    while (true) {
        cout << " -------------------------- " << endl;
        cout << "            Menu " << endl;
        cout << " -------------------------- " << endl;

        if (ptr == nullptr) {
            cout << "    1. Create a container " << endl;
        }

        if (ptr != nullptr) {
            cout << "    2. Destroy a container " << endl;
            cout << "    3. Add a value in the container " << endl;
            cout << "    4. Get a value from the container the container and print it " << endl;
            cout << "    5. Print the values of the box " << endl;
            cout << "    6. Print the values of the box sorted " << endl;
            cout << "    7. Count the values of the box " << endl;
            cout << "    8. Check if box contains a specific value " << endl;
        }

        cout << "    9. Exit program" << endl;
        cout << endl;

        cout << " - Enter your choice:";
        cin >> choice;

        if (choice == 1 && ptr == nullptr) {
            ptr = new ContainerForInt();
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

                ptr->add(value);
            }

            if (choice == 4) {
                int position;
                cout << "Please give the position:";
                cin >> position;

                int value;

                value = ptr->get(position);

                cout << "Value at position " << position << " is: " << value << endl;
            }

            if (choice == 5) {
                ptr->print();
            }

            if (choice == 6) {
                ptr->printSorted();
            }

            if (choice == 7) {
                unsigned int c = ptr->count();

                cout << " Count is : " << c << endl;
            }

            if (choice == 8) {
                int value;
                cout << "Please give the value:";
                cin >> value;

                bool found = ptr->contains(value);

                if (found) {
                    cout << "Value was found in the container " << endl;
                } else {
                    cout << "Value was not found " << endl;
                }
            }
        }

        if (choice == 9) {
            break;
        }
    }
    return 0;
}