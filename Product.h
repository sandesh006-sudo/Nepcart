#pragma once
#include <iostream>
#include <string>

using namespace std;

class product
{
private:
    int id;
    string name;
    string category;
    double price;
    int quantity;

public:

    // default constructor
    product()
    {
        id = 0;
        name = "";
        category = "";
        price = 0;
        quantity = 0;
    }

    // [arameterized constructor
    product(int i, string n, string c, double p, int q)
    {
        id = i;
        name = n;
        category = c;
        price = p;
        quantity = q;
    }

    // display product
    void display() const
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Category: " << category << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
    }

    // getter function haru
    //constant member function to not to modify object data
    int getId() const
    {
        return id;
    }

    string getname() const
    {
        return name;
    }

    string getcategory() const
    {
        return category;
    }

    double getprice() const
    {
        return price;
    }

    int getquantity() const
    {
        return quantity;
    }

    // vayeko amount reduce garxa
    bool reducestock(int amount)
    {
    /*example quantity 3 xa amount ma 2 aaxa so quantity 3-2=1*/
        if (amount > 0 && amount <= quantity)
        {
            quantity =quantity-amount;
            
            return true;
        }

        return false;
    }
};
