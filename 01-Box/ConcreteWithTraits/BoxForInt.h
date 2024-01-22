#pragma once

#include <iostream>

#include "BoxForIntTraits"

using namespace std;

class BoxForInt : public BoxForIntTraits {
private:
    int data;        
public:
    BoxForInt() : data(0) {

    }

    ~BoxForInt() {
        
    }

    void print() const {
        cout << data << endl;
    }

    void put(int data) {
        this->data = data;
    }

    int get() const {
        return data;
    }
};
