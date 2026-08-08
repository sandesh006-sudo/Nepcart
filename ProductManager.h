#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cctype>
#include <filesystem>
#include<vector>
#include "Product.h"

using namespace std;

class ProductManager{
    const string PRODUCT_FILE;
    // ProductManager has-a Product
    vector<Product> products;
    public:
    ProductManager():PRODUCT_FILE("products.txt"){
        loadProducts();
    }

    // to lowercase a string
    string lower(string str){
        for(char& c : str){
            c = tolower(c);
        }
        return str;
    }

    void loadProducts()
    {
        ifstream fin(PRODUCT_FILE);
        if(!fin.is_open()){
            return;
        }
        string line;
        while(getline(fin, line)){
            stringstream ss(line);
            string s_id;
            string s_name;
            string s_category;
            string s_price;
            string s_quantity;

            getline(ss, s_id, '|');
            getline(ss, s_name, '|');
            getline(ss, s_category, '|');
            getline(ss, s_price, '|');
            getline(ss, s_quantity);

            Product p(
                stoi(s_id),
                s_name,
                s_category,
                stod(s_price),
                stoi(s_quantity)
            );
            products.push_back(p);
        }
        fin.close();
    }

    void addProduct(){
        int id;
        string name;
        string category;
        double price;
        int quantity;
        while(true){
            cout << "Product ID: ";
            cin >> id;
            if(!idExists(id))
                break;
            cout << "Product with that ID already exists! Enter ID again!\n";
        }
        cout<<"Product name: ";getline(cin >> ws, name);
        cout<<"Product category: ";getline(cin >> ws, category);
        cout<<"Product price: ";cin>>price;
        cout<<"Product quantity: ";cin>>quantity;
        Product p(id,name,category,price,quantity);
        products.push_back(p);
        saveProducts();
        cout<<"Product added successfully!\n";
    }

    void deleteProduct(){
        int id;
        cout << "Enter Product ID to delete: ";
        cin >> id;

        for(int i = 0; i < products.size(); i++){
            if(products[i].getId() == id){
                products.erase(products.begin() + i);
                saveProducts();

                cout << "Product with ID " << id << " deleted successfully!\n";
                return;
            }
        }
        cout << "Product with ID " << id << " doesn't exist!\n";
    }


    void updateProduct(){
        int id;
        cout<<"Enter ID of product to update: ";
        cin>>id;
        int i;
        for(i=0;i<products.size();i++){
            if(id==products[i].getId())
                break;
        }
        if(i==products.size()){
            cout<<"Product with ID "<<id<<" doesn't exist!\n";
            return;
        }
        string name;
        string category;
        double price;
        int quantity;
        int choice;
        while(true){
            cout<<"WHAT TO CHANGE?\n";
            cout<<"1. Name\n";
            cout<<"2. Category\n";
            cout<<"3. Price\n";
            cout<<"4. Quantity\n";
            cin>>choice;
            if(choice>=1 && choice<=4)
                break;
        }
        switch(choice){
            case 1:
                cout<<"Product name: ";
                getline(cin >> ws, name);
                products[i].setName(name);
                break;
            case 2:
                cout<<"Product category: ";
                getline(cin >> ws, category);
                products[i].setCategory(category);
                break;
            case 3:
                cout<<"Product price: ";
                cin>>price;
                products[i].setPrice(price);
                break;  
            case 4:
                cout<<"Product quantity: ";
                cin>>quantity;
                products[i].setQuantity(quantity);
                break;
        }
        saveProducts();
    }

    void searchByID(){
        int id;
        cout << "Enter Product ID: ";
        cin >> id;

        for(const Product& p : products){
            if(p.getId() == id){
                cout << "\nProduct found!\n";
                p.display();
                return;
            }
        }
        cout << "Product with ID " << id<< " doesn't exist!\n";
    }

    void searchByName(){
        string name;
        cout << "Enter Product name: ";
        getline(cin >> ws, name);

        for(const Product& p : products)
        {
            if(lower(p.getName())== lower(name)){
                cout << "\nProduct found!\n";
                p.display();
                return;
            }
        }
        cout << "Product with name " << name << " doesn't exist!\n";
    }

    void displayAll(){
        if(products.empty()){
            cout << "No products available.\n";
            return;
        }

        cout << "\n===== ALL PRODUCTS =====\n";
        for(const Product& p : products){
            p.display();
            cout << "------------------------\n";
        }
    }

    void saveProducts(){
        ofstream f(PRODUCT_FILE,ios::trunc);
        if(!f.is_open()){
            cout << "Cannot open products file.\n";
            return;
        }
        for(const Product& p : products){
            f << p.getId() << '|'
                << p.getName() << '|'
                << p.getCategory() << '|'
                << p.getPrice() << '|'
                << p.getQuantity() << '\n';
        }
        f.close();
    }

    bool idExists(int id){
        for(const Product& p : products){
            if(p.getId() == id)
                return true;
        }
        return false;
    }
};
