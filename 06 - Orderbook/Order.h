#pragma once

#include <iostream>
#include <string>

#include "Order.h"

using namespace std;

class Order {
private:
    string code; // e.g. VA1230

public:
    Order(string code) : code(code) {
    }

    virtual ~Order() {
    }

    void print() const {
        cout << code << endl;
    }

    string getCompanyCode() const { // e.g. VA
        return code.substr(0, 2);
    }

    string getOrderCode() const {
        return code.substr(2); // e.g. 1230
    }

    // VA0001 VA1011 VA1230 MX1100 XD1238 MX2389 AC3784 AB7693

    bool operator<(const Order& other) const {
        string c1 = this->getCompanyCode();
        string n1 = this->getOrderCode();
        string c2 = other.getCompanyCode();
        string n2 = other.getOrderCode();

        if (c1 == "VA" && c2 != "VA") {
            return true;
        }

        if (c1 != "VA" && c2 == "VA") {
            return false;
        }

        if (n1 < n2) {
            return true;
        } else {
            return false;
        }
    }
};
