#pragma once

#include <iterator>
#include <map>
#include <string>

using namespace std;

#include "MatrixTraits.h"

template <typename T>
class Coordinates {
public:
    int row, col;

    Coordinates() : row(0), col(0) {
    }

    Coordinates(int row, int col) : row(row), col(col) {
    }

    bool operator<(const Coordinates& other) {
        if (this->x < other.x) {
            return true;
        }
        if (this->x > other.x) {
            return false;
        }
        if (this->y < other.y) {
            return true;
        } else {
            return false;
        }
    }
};

template <typename T>
class Matrix : public MatrixTraits<T> {
private:
    map<Coordinates, T> data;
    unsigned int width;
    unsigned int height;

public:
    Matrix(unsigned int width, unsigned int height) : width(width), height(height) {
    }

    virtual ~Matrix() {
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

    virtual void clear() {
        data.clear();
    }

    virtual T get(int row, int col) const {
        typename map<Coordinates, T>::iterator p;
        // Coordinates key = Coordinates(row, col);
        Coordinates key(row, col);

        p = data.find(key);

        if (p != data.end()) {
            return p->second;
        } else {
            return T();
        }
    }

    virtual void put(int row, int col, T value) {
        data[Coordinates(row, col)] = value;
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