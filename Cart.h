#pragma once
#include<iostream>
#include "CartItem.h"
#include "Product.h"
using namespace std;
class cart
{
    private:
    //Cart has-a CartItem
    cartitem items[10];
    int itemcount;
    public:
    cart()
    {
        itemcount=0;
    }
    //add item to cart
     void additem(int id, int qty)
    {
        if(itemcount < 10)
        {
            /*eg itemcount=0 
            additem(1,2)
            then items[0]=id 1 quantity 1
            itemcount=1
            */ 
            items[itemcount] = cartitem(id, qty);
            itemcount++;
        }
        else
        {
            cout<<"Cart is full"<<endl;
        }
    }
    //product array and its size receive
   void viewcart(Product products[], int size)
{
    cout << "\n===== CART =====\n";
    //cart ma vako every item check garxa
    for(int i = 0; i < itemcount; i++)
    {
        int id = items[i].getproductid();
    //every item ko lagi product array ko item check garxa
        for(int j = 0; j < size; j++)
        {
            if(products[j].getId() == id)
            {
                cout << "Name: " << products[j].getName() << endl;
                cout << "Price: " << products[j].getPrice() << endl;
                cout << "Quantity: " << items[i].getproductquantity() << endl;

                cout << endl;
            }
        }
    }
}

//calculate total price
double totalprice(Product products[], int size)
{
    double total = 0;

    for(int i = 0; i < itemcount; i++)
    {
        int id = items[i].getproductid();

        for(int j = 0; j < size; j++)
        {
            if(products[j].getId() == id)
            {
                double price = products[j].getPrice();
                int quantity = items[i].getproductquantity();

                double itemTotal = price * quantity;

                total = total + itemTotal;
            }
        }
    }

    return total;
}
//remove items from cart
void removeitem(int id)
{
    for(int i = 0; i < itemcount; i++)
    {
        if(items[i].getproductid() == id)
        {
            //shift next item to left
            for(int j = i; j < itemcount - 1; j++)
            {
                items[j] = items[j + 1];
            }

            itemcount--;
                
            cout << "Item removed successfully\n";
            return;
        }
    }

    cout << "Item not found\n";
}
};

