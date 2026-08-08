#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Product.h"
#include "utilities.h"

using namespace std;

class ProductManager
{
private:
    const string PRODUCT_FILE;

    vector<Product> products;

public:
    ProductManager() : PRODUCT_FILE("products.txt")
    {
        loadProducts();
    }

    // ================= LOAD PRODUCTS =================

    void loadProducts()
    {
        ifstream fin(PRODUCT_FILE);

        if (!fin.is_open())
            return;

        string line;

        while (getline(fin, line))
        {
            if (line.empty())
                continue;

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
                stoi(s_quantity));

            products.push_back(p);
        }

        fin.close();
    }

    // ================= ADD PRODUCT =================

    void addProduct()
    {
        int id;
        string name;
        string category;
        double price;
        int quantity;

        while (true)
        {
            cout << "Product ID: ";
            id = getInt();

            if (!idExists(id))
                break;

            cout << "Product with that ID already exists!"
                 << " Enter ID again!\n";
        }

        cout << "Product name: ";
        getline(cin >> ws, name);

        cout << "Product category: ";
        getline(cin >> ws, category);

        cout << "Product price: ";
        cin >> price;

        cout << "Product quantity: ";
        quantity = getInt();

        Product p(
            id,
            name,
            category,
            price,
            quantity);

        products.push_back(p);

        saveProducts();

        cout << "Product added successfully!\n";
    }

    // ================= DELETE PRODUCT =================

    void deleteProduct()
    {
        int id;

        cout << "Enter Product ID to delete: ";
        id = getInt();

        for (int i = 0; i < products.size(); i++)
        {
            if (products[i].getId() == id)
            {
                products.erase(products.begin() + i);

                saveProducts();

                cout << "Product with ID "
                     << id
                     << " deleted successfully!\n";

                return;
            }
        }

        cout << "Product with ID "
             << id
             << " doesn't exist!\n";
    }

    // ================= UPDATE PRODUCT =================

    void updateProduct()
    {
        int id;

        cout << "Enter ID of product to update: ";
        id = getInt();

        int i;

        for (i = 0; i < products.size(); i++)
        {
            if (id == products[i].getId())
                break;
        }

        if (i == products.size())
        {
            cout << "Product with ID "
                 << id
                 << " doesn't exist!\n";

            return;
        }

        string name;
        string category;
        double price;
        int quantity;
        int choice;

        while (true)
        {
            cout << "\nWHAT TO CHANGE?\n";
            cout << "1. Name\n";
            cout << "2. Category\n";
            cout << "3. Price\n";
            cout << "4. Quantity\n";

            choice = getInt();

            if (choice >= 1 && choice <= 4)
                break;

            cout << "Invalid choice!\n";
        }

        switch (choice)
        {
        case 1:

            cout << "Product name: ";
            getline(cin >> ws, name);

            products[i].setName(name);

            break;

        case 2:

            cout << "Product category: ";
            getline(cin >> ws, category);

            products[i].setCategory(category);

            break;

        case 3:

            cout << "Product price: ";
            cin >> price;

            products[i].setPrice(price);

            break;

        case 4:

            cout << "Product quantity: ";
            quantity = getInt();

            products[i].setQuantity(quantity);

            break;
        }

        saveProducts();
    }

    // ================= FIND PRODUCT =================

    Product *findByID(int id)
    {
        for (Product &p : products)
        {
            if (p.getId() == id)
                return &p;
        }

        return nullptr;
    }

    // ================= SEARCH BY ID =================

    void searchByID()
    {
        int id;

        cout << "Enter Product ID: ";
        id = getInt();

        Product *product = findByID(id);

        if (product != nullptr)
        {
            cout << "\nProduct found!\n";

            product->display();

            return;
        }

        cout << "Product with ID "
             << id
             << " doesn't exist!\n";
    }

    // ================= SEARCH BY NAME =================

    void searchByName()
    {
        string name;

        cout << "Enter Product name: ";
        getline(cin >> ws, name);

        for (const Product &p : products)
        {
            if (lower(p.getName()) == lower(name))
            {
                cout << "\nProduct found!\n";

                p.display();

                return;
            }
        }

        cout << "Product with name "
             << name
             << " doesn't exist!\n";
    }

    // ================= DISPLAY ALL =================

    void displayAll()
    {
        if (products.empty())
        {
            cout << "No products available.\n";
            return;
        }

        cout << "\n===== ALL PRODUCTS =====\n";

        for (const Product &p : products)
        {
            p.display();

            cout << "------------------------\n";
        }
    }

    // ================= SAVE PRODUCTS =================

    void saveProducts()
    {
        ofstream f(
            PRODUCT_FILE,
            ios::trunc);

        if (!f.is_open())
        {
            cout << "Cannot open products file.\n";
            return;
        }

        for (const Product &p : products)
        {
            f << p.getId() << '|'
              << p.getName() << '|'
              << p.getCategory() << '|'
              << p.getPrice() << '|'
              << p.getQuantity()
              << '\n';
        }

        f.close();
    }

    // ================= CHECK ID =================

    bool idExists(int id)
    {
        for (const Product &p : products)
        {
            if (p.getId() == id)
                return true;
        }

        return false;
    }
};