#pragma once

#include <set>
#include <string>

#include "OrderBookTraits.h"

class OrderBook : public OrderBookTraits {
private:
    set<Order> orders;

public:
    OrderBook() {
    }

    virtual ~OrderBook() {
    }

    virtual void add(Order order) {
        orders.insert(order);
    }

    virtual void remove(Order order) {
        set<Order>::iterator p = orders.find(order);
        if (p != orders.end()) {
            orders.erase(p);
        }
    }

    virtual void print() const {
        for (const Order& o : orders) {
            o.print();
        }
    }

    virtual void printByCompany(string company_code) const {
        for (const Order& o : orders) {
            if (o.getCompanyCode() == company_code) {
                o.print();
            }
        }
    }

    virtual void printByOrderCode(string company_code, string order_code) const {
        for (const Order& o : orders) {
            if (o.getCompanyCode() == company_code && o.getOrderCode() == order_code) {
                o.print();
            }
        }
    }
};
