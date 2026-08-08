#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Order.h"
#include "Cart.h"
#include "Product.h"
#include "ProductManager.h"
#include "utilities.h"

using namespace std;

class OrderManager
{
private:
    const string ORDER_FILE;
    vector<Order> orders;

public:
    // ================= CONSTRUCTOR =================

    OrderManager() : ORDER_FILE("orders.txt")
    {
        loadOrders();
    }

    // ================= LOAD ORDERS =================

    void loadOrders()
    {
        ifstream fin(ORDER_FILE);

        if (!fin.is_open())
            return;

        string line;

        while (getline(fin, line))
        {
            if (line.empty())
                continue;

            stringstream orderStream(line);

            string s_orderId;
            string username;
            string s_total;
            string itemsData;

            getline(orderStream, s_orderId, ';');
            getline(orderStream, username, ';');
            getline(orderStream, s_total, ';');
            getline(orderStream, itemsData);

            int orderId = stoi(s_orderId);
            double total = stod(s_total);

            vector<CartItem> items;

            stringstream itemStream(itemsData);

            string itemData;

            while (getline(itemStream, itemData, '~'))
            {
                if (itemData.empty())
                    continue;

                stringstream productStream(itemData);

                string s_productId;
                string productName;
                string s_price;
                string s_quantity;

                getline(productStream, s_productId, '|');
                getline(productStream, productName, '|');
                getline(productStream, s_price, '|');
                getline(productStream, s_quantity);

                int productId = stoi(s_productId);
                double price = stod(s_price);
                int quantity = stoi(s_quantity);

                Product product(
                    productId,
                    productName,
                    "",
                    price,
                    quantity);

                CartItem item(product, quantity);

                items.push_back(item);
            }

            Order order(
                orderId,
                username,
                items);

            orders.push_back(order);
        }

        fin.close();
    }

    // ================= GENERATE ORDER ID =================

    int generateOrderId()
    {
        int maxId = 0;

        for (const Order &order : orders)
        {
            if (order.getOrderId() > maxId)
                maxId = order.getOrderId();
        }

        return maxId + 1;
    }

    // ================= CREATE ORDER =================

    void createOrder(
        const string &username,
        Cart &cart,
        ProductManager &productManager)
    {
        if (cart.isEmpty())
        {
            cout << "Cannot create order. Cart is empty.\n";
            return;
        }

        // Check stock before creating the order
        for (const CartItem &item : cart.getItems())
        {
            int productId =
                item.getProduct().getId();

            Product *product =
                productManager.findByID(productId);

            if (product == nullptr)
            {
                cout << "Product with ID "
                     << productId
                     << " no longer exists.\n";

                return;
            }

            if (item.getQuantity() > product->getQuantity())
            {
                cout << "Not enough stock for "
                     << product->getName()
                     << ".\n";

                cout << "Available stock: "
                     << product->getQuantity()
                     << endl;

                cout << "Requested quantity: "
                     << item.getQuantity()
                     << endl;

                return;
            }
        }

        // Create order
        int id = generateOrderId();

        Order order(
            id,
            username,
            cart.getItems());

        // Reduce stock
        for (const CartItem &item : cart.getItems())
        {
            Product *product =
                productManager.findByID(
                    item.getProduct().getId());

            if (product != nullptr)
            {
                product->reduceStock(
                    item.getQuantity());
            }
        }

        // Store order
        orders.push_back(order);

        // Save changes
        productManager.saveProducts();
        saveOrders();

        cout << "\nOrder created successfully!\n";
        cout << "Order ID: " << id << endl;
        cout << "Total: $" << order.getTotal() << endl;

        // Empty cart
        cart.clear();
    }

    // ================= DISPLAY USER ORDERS =================

    void displayUserOrders(
        const string &username) const
    {
        bool found = false;

        for (const Order &order : orders)
        {
            if (order.getUsername() == username)
            {
                order.display();
                found = true;
            }
        }

        if (!found)
        {
            cout << "No orders found for "
                 << username
                 << ".\n";
        }
    }

    // ================= DISPLAY ALL ORDERS =================

    void displayAllOrders() const
    {
        if (orders.empty())
        {
            cout << "No orders available.\n";
            return;
        }

        for (const Order &order : orders)
        {
            order.display();

            cout << "============================\n";
        }
    }

    // ================= SAVE ORDERS =================

    void saveOrders()
    {
        ofstream fout(
            ORDER_FILE,
            ios::trunc);

        if (!fout.is_open())
        {
            cerr << "Cannot open orders file.\n";
            return;
        }

        for (const Order &order : orders)
        {
            fout << order.getOrderId()
                 << ';'
                 << order.getUsername()
                 << ';'
                 << order.getTotal()
                 << ';';

            vector<CartItem> items =
                order.getItems();

            for (int i = 0; i < items.size(); i++)
            {
                Product product =
                    items[i].getProduct();

                fout << product.getId()
                     << '|'
                     << product.getName()
                     << '|'
                     << product.getPrice()
                     << '|'
                     << items[i].getQuantity();

                if (i < items.size() - 1)
                    fout << '~';
            }

            fout << '\n';
        }

        fout.close();
    }
};