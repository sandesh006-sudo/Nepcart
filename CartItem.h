#pragma once
#include<iostream>
using namespace std;
class cartitem
{
    private:
    int productid;
    int quantity;
    public:
    cartitem(int id=0,int qty=0)
    {
        productid=id;
        quantity=qty;
    }
    int getproductid()
    {
        return productid;
    }
    int getproductquantity()
    {
        return quantity;
    }
};
