#pragma once

#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <vector>

using namespace std;

template <typename T>
void bubbleSort(vector<T>& temp) {
    for (unsigned int i = 0; i < temp.size() - 1; i++) {
        for (unsigned int j = 0; j < (temp.size() - i - 1); j++) {
            if (temp[j] > temp[j + 1]) {
                T t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
}

class ContainerForInt {
private:
    vector<int> data;

public:
    void add(int value) {
        data.push_back(value);
    }

    int get(int position) {
        if (position >= 0 && (unsigned int)position < data.size()) {
            return data[position];
        } else {
            return 0;
        }
    }

    void print() {
        for (unsigned int i = 0; i < data.size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void printSorted() const {
        // (1) sort with our implemention (bubblesort) = O(n*n)
        {
            vector<int> copy;
            for (unsigned int i = 0; i < data.size(); i++) {
                copy.push_back(data[i]);
            }
            bubbleSort(copy);
            for (unsigned int i = 0; i < data.size(); i++) {
                cout << copy[i] << endl;
            }
        }

        // (2) by using function of STL = O(nlogn)
        {
            vector<int> copy;
            for (unsigned int i = 0; i < data.size(); i++) {
                copy.push_back(data[i]);
            }
            sort(copy.begin(), copy.end());
            for (unsigned int i = 0; i < data.size(); i++) {
                cout << copy[i] << endl;
            }
        }

        // (3) without any STL sorting function
        {
            multiset<int> copy;
            for (unsigned int i = 0; i < data.size(); i++) {
                copy.insert(data[i]);
            }

            for (auto x : copy) {
                cout << x << endl;
            }
        }
    }

    int count() const {
        return data.size();
    }

    bool contains(int key) {
        // (a1): traversal with local pointer (only for arrays)
        const int* ptr = &(data[0]);

        for (unsigned int i = 0; i < data.size(); i++) {
            if (*ptr == key) {
                return true;
            } else {
                ++ptr;
            }
        }

        // (a2): traversal with indexing (only for arrays)
        for (unsigned int i = 0; i < data.size(); i++) {
            if (data[i] == key) {
                return true;
            }
        }

        // (b1): with iterators (recommended - universal)
        for (vector<int>::const_iterator p = data.begin(); p != data.end(); ++p) {
            if (*p == key) {
                return true;
            }
        }
        // (b2): with iterators
        for (auto p = data.begin(); p != data.end(); ++p) {
            if (*p == key) {
                return true;
            }
        }

        // (b3): with iterators
        for (auto p : data) {
            if (p == key) {
                return true;
            }
        }

        return false;
    }
};