#pragma once

#include "AgendaTraits.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>

using namespace std;

class FirstnameComparator {
public:
    bool operator()(const Record& left, const Record& right) const {
        if (right.firstname > left.firstname) {
            return true;
        } else {
            return false;
        }
    }
};

class LastNameComparator {
public:
    bool operator()(const Record& left, const Record& right) const {
        if (right.lastname > left.lastname) {
            return true;
        } else {
            return false;
        }
    }
};

class PhoneComparator {
public:
    bool operator()(const Record& left, const Record& right) const {
        if (right.phone > left.phone) {
            return true;
        } else {
            return false;
        }
    }
};

class Agenda : public Record {
private:
    vector<Record> r;

public:
    Agenda() {
    }

    virtual ~Agenda() {
    }

    void put(Record record) {
        r.push_back(record);
    }

    void put(string firstname, string lastname, long int phone) {
        Record record(firstname, lastname, phone);
        put(record);
    }

    void operator+=(Record record) {
        put(record);
    }

    void remove(string firstname, string lastname, long int phone) {
        for (vector<Record>::iterator p = r.begin(); p != r.end();) {
            if (firstname == p->firstname && lastname == p->lastname && phone == p->phone) {
                p = r.erase(p);
                break;
            } else {
                ++p;
            }
        }
    }

    void printByFirstname(string firstname) const {
        for (vector<Record>::const_iterator p = r.begin(); p != r.end(); ++p) {
            if (p->firstname == firstname) {
                cout << p->firstname << ' ' << p->lastname << ' ' << p->phone << endl;
            }
        }
    }

    void printByLastname(string lastname) const {
        for (vector<Record>::const_iterator p = r.begin(); p != r.end(); ++p) {
            if (p->lastname == lastname) {
                cout << p->lastname << ' ' << p->firstname << ' ' << p->phone << endl;
            }
        }
    }

    void printByPhone(long int phone) const {
        for (vector<Record>::const_iterator p = r.begin(); p != r.end(); ++p) {
            if (p->phone == phone) {
                cout << p->phone << ' ' << p->lastname << ' ' << p->firstname << endl;
            }
        }
    }

    void print() const {
        for (vector<Record>::const_iterator p = r.begin(); p != r.end(); ++p) {
            cout << p->firstname << ' ' << p->lastname << ' ' << p->phone << endl;
        }
    }

    void printOrderedByFirstname() const {
        multiset<Record, FirstnameComparator> copy;

        for (unsigned int i = 0; i < r.size(); i++) {
            copy.insert(r[i]);
        }
        for (multiset<Record, FirstnameComparator>::const_iterator p = copy.begin(); p != copy.end(); ++p) {
            cout << p->firstname << ' ' << p->lastname << ' ' << p->phone << endl;
        }
    }

    void printOrderedByLastname() const {
        multiset<Record, LastNameComparator> copy;
        for (unsigned int i = 0; i < r.size(); i++) {
            copy.insert(r[i]);
        }
        for (multiset<Record, LastNameComparator>::const_iterator p = copy.begin(); p != copy.end(); ++p) {
            cout << p->lastname << ' ' << p->firstname << ' ' << p->phone << endl;
        }
    }

    void printOrderedByPhone() const {
        multiset<Record, PhoneComparator> copy;
        for (unsigned int i = 0; i < r.size(); i++) {
            copy.insert(r[i]);
        }
        for (multiset<Record, PhoneComparator>::const_iterator p = copy.begin(); p != copy.end(); ++p) {
            cout << p->phone << ' ' << p->firstname << ' ' << p->lastname << endl;
        }
    }
};
