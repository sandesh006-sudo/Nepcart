#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "CartItem.h"

using namespace std;

class Order
{
private:
    int orderId;
    string username;
    vector<CartItem> items;
    double total;

public:
    // ================= DEFAULT CONSTRUCTOR =================

    Order()
    {
        orderId = 0;
        username = "";
        total = 0;
    }

    // ================= PARAMETERIZED CONSTRUCTOR =================

    Order(
        int id,
        string u,
        vector<CartItem> i)
    {
        orderId = id;
        username = u;
        items = i;

        calculateTotal();
    }

    // ================= CALCULATE TOTAL =================

    void calculateTotal()
    {
        total = 0;

        for (const CartItem &item : items)
        {
            total += item.getSubtotal();
        }
    }

    // ================= GETTERS =================

    int getOrderId() const
    {
        return orderId;
    }

    string getUsername() const
    {
        return username;
    }

    vector<CartItem> getItems() const
    {
        return items;
    }

    double getTotal() const
    {
        return total;
    }

    // ================= DISPLAY =================

    void display() const
    {
        cout << "\n========== ORDER ==========\n";

        cout << "Order ID: " << orderId << endl;
        cout << "Username: " << username << endl;

        cout << "\nItems:\n";

        for (const CartItem &item : items)
        {
            item.display();

            cout << "--------------------------\n";
        }

        cout << "Total: $" << total << endl;
    }
};