#pragma once

#include <iostream>

using namespace std;

template <typename T>
class GenericBoxTraits {
public:
    virtual void print() = 0;
    virtual void put(T data) = 0;
    virtual T get() const = 0;
};