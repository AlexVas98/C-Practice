#pragma once

#include <string>

using namespace std;

template <typename T>
class MatrixTraits {
public:
    virtual T get(int row, int col) const = 0;

    virtual void put(int row, int col, T value) = 0;

    virtual void clear() = 0;

    virtual void print() const = 0;

    virtual unsigned int size() const = 0;

    virtual unsigned int getWidth() const = 0;

    virtual unsigned int getHeight() const = 0;

    virtual bool equals(MatrixTraits<T>& other) const = 0;

    virtual void copyFrom(MatrixTraits<T>& other) = 0;
};
