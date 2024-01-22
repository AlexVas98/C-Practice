#pragma once

#include "BallotBoxTraits.h"
#include <iterator>
#include <map>
#include <vector>

using namespace std;

template <typename T>
class BallotBox : public BallotBoxTraits<T> {
private:
    map<T, unsigned> data;

public:
    BallotBox() {
    }

    virtual ~BallotBox() {
    }

    virtual void place(const vector<T>& input) {
        for (vector<T>::const_iterator p = input.begin(); p != input.end(); ++p) {
            place(*p);
        }
    }

    virtual void operator+=(T item) {
        place(item);
    }

    virtual void clear() {
        data.clear();
    }

    virtual void place(T item) {
        typename map<T, unsigned>::iterator p = data.find(item);

        if (p != data.end()) {
            data[item]++;
        } else {
            data[item] = 1;
        }
    }

    virtual unsigned getFrequency(T item) const {
        typename map<T, unsigned>::iterator p = data.find(item);

        if (p != data.end()) {
            return data[item];
            // return p->second;
        } else {
            return 0;
        }
    }
};