#pragma once

#include <iostream>

using namespace std;

class BoxForIntTraits {
public:
    virtual void print() const = 0;
    virtual void put(int data) = 0;
    virtual int get() const = 0;
};