#pragma once

#include <iostream>
#include "Product.h"

using namespace std;

class CartItem
{
private:
    Product product;
    int quantity;

public:
    // Default constructor
    CartItem()
    {
        quantity = 0;
    }

    // Parameterized constructor
    CartItem(Product p, int q)
    {
        product = p;
        quantity = q;
    }

    // Getters
    Product getProduct() const
    {
        return product;
    }

    int getQuantity() const
    {
        return quantity;
    }

    double getSubtotal() const
    {
        return product.getPrice() * quantity;
    }

    // Setter
    void setQuantity(int q)
    {
        if (q >= 0)
            quantity = q;
    }

    void display() const
    {
        cout << "Product: " << product.getName() << endl;
        cout << "Price: $" << product.getPrice() << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Subtotal: $" << getSubtotal() << endl;
    }
};