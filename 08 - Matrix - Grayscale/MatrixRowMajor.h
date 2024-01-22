#pragma once

#include <string>

using namespace std;

#include "MatrixTraits.h"

template <typename T>
class Matrix : public MatrixTraits<T> {
private:
    T* data;
    unsigned int width;
    unsigned int height;

public:
    Matrix(unsigned int width, unsigned int height) : width(width), height(height) {
        data = new T[width * height]();
    }

    virtual ~Matrix() {
        delete[] data;
    }

    virtual unsigned int size() const {
        return width * height;
    }

    virtual unsigned int getWidth() const {
        return width;
    }

    virtual unsigned int getHeight() const {
        return height;
    }

    virtual T get(int row, int col) const {
        int index = col + row * width;
        return data[index];
    }

    virtual void put(int row, int col, T value) {
        int index = col + row * width;
        data[index] = value;
    }

    virtual void clear() {
        for (unsigned int i = 0; i < getHeight() * getWidth(); i++) {
            data[i] = 0;
        }
    }

    virtual void print() const {
        for (unsigned int i = 0; i < getHeight(); i++) {
            for (unsigned int j = 0; j < getWidth(); j++) {
                cout << get(i, j);
            }
            cout << endl;
        }
    }

    virtual bool equals(MatrixTraits<T>& other) const {
        if (this->getHeight() != other.getHeight() || this->getWidth() != other.getWidth()) {
            return false;
        }

        for (unsigned int i = 0; i < getHeight(); i++) {
            for (unsigned int j = 0; j < getWidth(); j++) {
                if (this->get(i, j) != other.get(i, j)) {
                    return false;
                }
            }
        }

        return true;
    }

    virtual void copyFrom(MatrixTraits<T>& other) {
        if (this->getHeight() != other.getHeight() || this->getWidth() != other.getWidth()) {
            return;
        }

        for (unsigned int i = 0; i < getHeight(); i++) {
            for (unsigned int j = 0; j < getWidth(); j++) {
                T value = other.get(i, j);
                this->put(i, j, value);
            }
        }
    }
};