#pragma once

#include <iostream>
#include <set>

using namespace std;

#include "ListTraits.h"

template <typename T>
class List : public ListTraits<T>, public ListTraitsExtended<T> {
private:
    multiset<T> data;
    typename multiset<T>::iterator p;

public:
    List() {
    }

    virtual ~List() {
    }

    // -----------------------------------------------------
    //                       Test 1
    // -----------------------------------------------------
    virtual ListTraits<T>& insert(const T& item) {
        data.insert(item);
        return *this;
    }

    virtual unsigned int size() {
        return data.size();
    }

    virtual void print() {
        for (auto x : data) {
            cout << x << " ";
        }
        cout << endl;
    }

    // -----------------------------------------------------
    //                       Test 2
    // -----------------------------------------------------

    virtual void rewind() {
        if (data.size() > 0) {
            p = data.begin();
        }
    }

    virtual void advance() {
        if (p != data.end()) {
            ++p;
        }
    }

    virtual const T* getCurrentElement() const {
        if (p != data.end()) {
            const T* result = &(*p);
            return result;
        } else {
            return nullptr;
        }
    }

    // -----------------------------------------------------
    //                       Test 3
    // -----------------------------------------------------

    typename multiset<T>::iterator begin() {
        return data.begin();
    }

    typename multiset<T>::iterator end() {
        return data.end();
    }
};
