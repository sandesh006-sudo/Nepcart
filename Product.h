#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Product
{
private:
    int id;
    string name;
    string category;
    double price;
    int quantity;
public:

    // default constructor
    Product(){
        id = 0;
        name = "";
        category = "";
        price = 0;
        quantity = 0;
    }
    Product(int i, string n, string c, double p, int q){
        setId(i);
        setName(n);
        setCategory(c);
        setPrice(p);
        setQuantity(q);
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

    string getName() const
    {
        return name;
    }

    string getCategory() const
    {
        return category;
    }

    double getPrice() const
    {
        return price;
    }

    int getQuantity() const
    {
        return quantity;
    }


    // ========= Setters =========
    void setId(int i){id=i;}

    void setName(string n){
        name=n;
    }

    void setPrice(double p){
        if(p<0){
            cout<<"Price can't be negative! Set to 0.\n";
            price=0;
        }
        else
            price=p;
    }

    void setQuantity(int q){
        if(q<0){
            cout<<"Quantity can't be negative! Set to 0.\n";
            quantity=0;
        }
        else 
            quantity=q;
    }

    void setCategory(string c){category=c;}

    
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
