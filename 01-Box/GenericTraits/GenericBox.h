#pragma once

#include <iostream>

using namespace std;

template <typename T>
class GenericBox : public GenericBoxTraits<T> {
private:
    T data;        
public:
    GenericBox() : data(0) {

    }

    ~GenericBox() {
        
    }

    void print() const {
        cout << data << endl;
    }

    void put(T data) {
        this->data = data;
    }

    T get() const {
        return data;
    }
};
