#pragma once

#include <iostream>
#include <string>

using namespace std;

class Record {
public:
    string firstname;
    string lastname;
    long int phone;

    Record(string firstname, string lastname, long int phone) : firstname(firstname), lastname(lastname), phone(phone) {
    }

    Record() {
    }

    void print() const {
        cout << firstname << " " << lastname << " " << phone << endl;
    }
};

class AgendaTraits {
public:
    virtual ~AgendaTraits() {
    }

    virtual void put(Record record) = 0;

    virtual void operator+=(Record record) = 0;

    virtual void put(string firstname, string lastname, long int phone) = 0;

    virtual void remove(string firstname, string lastname, long int phone) = 0;

    virtual void printByFirstname(string firstname) const = 0;

    virtual void printByLastname(string lastname) const = 0;

    virtual void printByPhone(long int phone) const = 0;

    virtual void print() const = 0;

    virtual void printOrderedByFirstname() const = 0;

    virtual void printOrderedByLastname() const = 0;

    virtual void printOrderedByPhone() const = 0;
};
