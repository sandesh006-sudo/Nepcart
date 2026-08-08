#pragma once

#include <iostream>
#include <vector>

#include "CartItem.h"
#include "utilities.h"

using namespace std;

class Cart
{
private:
    vector<CartItem> items;

public:
    // ================= ADD ITEM =================

    void addItem(Product product, int quantity)
    {
        if (quantity <= 0)
        {
            cout << "Invalid quantity!\n";
            return;
        }

        // Check if product is already in cart
        for (CartItem &item : items)
        {
            if (item.getProduct().getId() == product.getId())
            {
                item.setQuantity(
                    item.getQuantity() + quantity);

                cout << "Product quantity updated in cart!\n";
                return;
            }
        }

        items.push_back(
            CartItem(product, quantity));

        cout << "Product added to cart!\n";
    }

    // ================= REMOVE ITEM =================

    void removeItem(int productId)
    {
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].getProduct().getId() == productId)
            {
                items.erase(items.begin() + i);

                cout << "Product removed from cart!\n";
                return;
            }
        }

        cout << "Product not found in cart!\n";
    }

    // ================= DISPLAY CART =================

    void displayCart() const
    {
        if (items.empty())
        {
            cout << "Cart is empty.\n";
            return;
        }

        cout << "\n========== CART ==========\n";

        for (const CartItem &item : items)
        {
            item.display();

            cout << "--------------------------\n";
        }

        cout << "Total: $" << getTotal() << endl;
    }

    // ================= GET TOTAL =================

    double getTotal() const
    {
        double total = 0;

        for (const CartItem &item : items)
        {
            total += item.getSubtotal();
        }

        return total;
    }

    // ================= EMPTY =================

    bool isEmpty() const
    {
        return items.empty();
    }

    // ================= CLEAR =================

    void clear()
    {
        items.clear();
    }

    // ================= GET ITEMS =================

    vector<CartItem> getItems() const
    {
        return items;
    }
};
