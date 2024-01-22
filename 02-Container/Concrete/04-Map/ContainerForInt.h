#pragma once

#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <vector>

using namespace std;

class ContainerForInt {
private:
    map<int, int> data;
    int index;

public:
    ContainerForInt() : index(0) {
    }

    void add(int value) {
        data[index] = value;
        index++;
    }

    int get(int position) {
        if ((unsigned int)position >= data.size()) {
            return 0;
        }

        return data[position];
    }

    void print() {
        for (map<int, int>::const_iterator p = data.begin(); p != data.end(); ++p) {
            cout << p->second << endl;
        }
    }

    void printSorted() const {
        multiset<int> temp;

        for (map<int, int>::const_iterator p = data.begin(); p != data.end(); ++p) {
            temp.insert(p->second);
        }

        for (int x : temp) {
            cout << x << endl;
        }
    }

    int count() const {
        return data.size();
    }

    bool contains(int key) {
        for (map<int, int>::const_iterator p = data.begin(); p != data.end(); ++p) {
            if (p->second == key) {
                return true;
            }
        }

        return false;
    }
};