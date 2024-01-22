#pragma once

#include <iostream>

using namespace std;

class BoxForInt {
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
