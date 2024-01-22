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
    list<int> data;

public:
    void add(int value) {
        data.push_back(value);
    }

    int get(int position) {
        if ((unsigned int)position >= data.size()) {
            return 0;
        }

        list<int>::const_iterator p = data.begin();

        for (int i = 0; i < position; i++) {
            ++p;
        }
        return *p;
    }

    void print() {
        for (list<int>::const_iterator p = data.begin(); p != data.end(); ++p) {
            cout << *p << endl;
        }
    }

    void printSorted() const {
        multiset<int> copy;
        for (list<int>::const_iterator p = data.begin(); p != data.end(); ++p) {
            copy.insert(*p);
        }

        for (auto x : copy) {
            cout << x << endl;
        }
    }

    int count() const {
        return data.size();
    }

    bool contains(int key) {
        for (list<int>::const_iterator p = data.begin(); p != data.end(); ++p) {
            if (*p == key) {
                return true;
            }
        }

        return false;
    }
};