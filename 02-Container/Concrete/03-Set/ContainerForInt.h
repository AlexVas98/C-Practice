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
    set<int> data;

public:
    void add(int value) {
        data.insert(value);
    }

    int get(int position) {
        if ((unsigned int)position >= data.size()) {
            return 0;
        }

        set<int>::const_iterator p = data.begin();

        for (int i = 0; i < position; i++) {
            ++p;
        }
        return *p;
    }

    void print() {
        for (set<int>::const_iterator p = data.begin(); p != data.end(); ++p) {
            cout << *p << endl;
        }
    }

    void printSorted() const {
        for (set<int>::const_iterator p = data.begin(); p != data.end(); ++p) {
            cout << *p << endl;
        }
    }

    int count() const {
        return data.size();
    }

    bool contains(int key) {
        set<int>::const_iterator p = data.find(key);

        return p != data.end();
    }
};