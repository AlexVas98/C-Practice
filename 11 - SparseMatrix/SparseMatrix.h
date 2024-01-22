#pragma once

#include "SparseMatrixTraits.h"
#include <iostream>
#include <map>

using namespace std;

template <typename T>
class SparseMatrix : public SparseMatrixTraits<T> {
private:
    map<Coordinates, T> data;

public:
    SparseMatrix() {
    }

    virtual ~SparseMatrix() {
    }

    virtual void clear() {
        data.clear();
    }

    virtual void print() {
        for (typename map<Coordinates, T>::const_iterator p = data.begin(); p != data.end(); ++p) {
            const Coordinates& key = p.first;
            const T& value = p.second;
            cout << key.row << " " << key.col << ": " << value << endl;
        }
    }

    SparseMatrix(const SparseMatrix& other) {
        for (typename map<Coordinates, T>::const_iterator p = other.data.begin(); p != other.data.end(); ++p) {
            const Coordinates& key = p.first;
            const T& value = p.second;
            this->data[key] = value;
        }
    }

    virtual const T& operator()(Coordinates pos) const {
        typename map<Coordinates, T>::const_iterator p = data.find(pos);

        if (p == data.end() {
            return getNullElement<T>();
        }

        return p->second;
    }

    virtual T& operator()(Coordinates pos) {
        typename map<Coordinates, T>::const_iterator p = data.find(pos);

        if (p == data.end() {
             this->data[key] = T();
             return this->data[key];
        }

        return p->second;
    }

    virtual bool operator==(const SparseMatrix<T>& right) {
        if (right.data.size() != data.size()) {
			return false;
        }

    }
};