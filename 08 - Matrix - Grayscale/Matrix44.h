#pragma once

#include <string>

using namespace std;

#include "MatrixTraits.h"

template <typename T>
class Matrix : public MatrixTraits<T> {
private:
    T data[4][4];
    unsigned int width;
    unsigned int height;

public:
    Matrix() : width(4), height(4) {
        clear();
    }

    virtual ~Matrix() {
    }

    virtual void clear() {
        for (unsigned int i = 0; i < getHeight(); i++) {
            for (unsigned int j = 0; j < getWidth(); j++) {
                data[i][j] = 0;
            }
        }
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

    virtual void print() const {
        for (unsigned int i = 0; i < getHeight(); i++) {
            for (unsigned int j = 0; j < getWidth(); j++) {
                cout << data[i][j];
            }
            cout << endl;
        }
    }

    virtual T get(int row, int col) const {
        return data[row][col];
    }

    virtual void put(int row, int col, T value) {
        data[row][col] = value;
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