#include <iostream>

#include "ProductManager.h"
#include "UserManager.h"
#include "Cart.h"
#include "OrderManager.h"
#include "admin.h"
#include "utilities.h"

using namespace std;

int main()
{
    ProductManager productManager;
    UserManager userManager;
    OrderManager orderManager;
    Admin admin;

    while (true)
    {
        cout << "\n================================\n";
        cout << "           NEPCART\n";
        cout << "================================\n";
        cout << "1. Customer Register\n";
        cout << "2. Customer Login\n";
        cout << "3. Admin Login\n";
        cout << "4. Display Products\n";
        cout << "5. Exit\n";
        cout << "Choice: ";

        int choice = getInt();

        // =========================================
        // CUSTOMER REGISTER
        // =========================================

        if (choice == 1)
        {
            userManager.registerUser();
        }

        // =========================================
        // CUSTOMER LOGIN
        // =========================================

        else if (choice == 2)
        {
            string loggedInUsername;

            if (!userManager.login(loggedInUsername))
                continue;

            // Each login has its own cart
            Cart cart;

            while (true)
            {
                cout << "\n================================\n";
                cout << "          CUSTOMER MENU\n";
                cout << "================================\n";

                cout << "Logged in as: "
                     << loggedInUsername << "\n\n";
                cout << "1. Display Products\n";
                cout << "2. Search Product by ID\n";
                cout << "3. Search Product by Name\n";
                cout << "4. Add Product to Cart\n";
                cout << "5. View Cart\n";
                cout << "6. Remove from Cart\n";
                cout << "7. Place Order\n";
                cout << "8. View My Orders\n";
                cout << "9. Logout\n";

                cout << "Choice: ";

                int userChoice = getInt();

                // -----------------------------------------
                // DISPLAY PRODUCTS
                // -----------------------------------------

                if (userChoice == 1)
                {
                    productManager.displayAll();
                }

                // -----------------------------------------
                // SEARCH BY ID
                // -----------------------------------------

                else if (userChoice == 2)
                {
                    productManager.searchByID();
                }

                // -----------------------------------------
                // SEARCH BY NAME
                // -----------------------------------------

                else if (userChoice == 3)
                {
                    productManager.searchByName();
                }

                // -----------------------------------------
                // ADD PRODUCT TO CART
                // -----------------------------------------

                else if (userChoice == 4)
                {
                    int id;

                    cout << "Product ID: ";
                    id = getInt();

                    Product *product =
                        productManager.findByID(id);

                    if (product == nullptr)
                    {
                        cout << "Product not found!\n";
                        continue;
                    }

                    int quantity;

                    cout << "Quantity: ";
                    quantity = getInt();

                    if (quantity <= 0)
                    {
                        cout << "Invalid quantity!\n";
                        continue;
                    }

                    if (quantity > product->getQuantity())
                    {
                        cout << "Not enough stock available!\n";
                        cout << "Available stock: "
                             << product->getQuantity()
                             << '\n';

                        continue;
                    }

                    cart.addItem(
                        *product,
                        quantity);
                }

                // -----------------------------------------
                // VIEW CART
                // -----------------------------------------

                else if (userChoice == 5)
                {
                    cart.displayCart();
                }

                // -----------------------------------------
                // REMOVE FROM CART
                // -----------------------------------------

                else if (userChoice == 6)
                {
                    int id;

                    cout << "Product ID: ";
                    id = getInt();

                    cart.removeItem(id);
                }

                // -----------------------------------------
                // PLACE ORDER
                // -----------------------------------------

                else if (userChoice == 7)
                {
                    if (cart.isEmpty())
                    {
                        cout << "Your cart is empty!\n";
                        continue;
                    }

                    orderManager.createOrder(
                        loggedInUsername,
                        cart,
                        productManager);
                }

                // -----------------------------------------
                // VIEW MY ORDERS
                // -----------------------------------------

                else if (userChoice == 8)
                {
                    orderManager.displayUserOrders(
                        loggedInUsername);
                }

                // -----------------------------------------
                // LOGOUT
                // -----------------------------------------

                else if (userChoice == 9)
                {
                    cout << "Logged out successfully!\n";
                    break;
                }

                else
                {
                    cout << "Invalid choice!\n";
                }
            }
        }

        // =========================================
        // ADMIN LOGIN
        // =========================================

        else if (choice == 3)
        {
            if (!admin.login())
                continue;

            while (true)
            {
                cout << "\n================================\n";
                cout << "            ADMIN MENU\n";
                cout << "================================\n";
                cout << "1. Add Product\n";
                cout << "2. Update Product\n";
                cout << "3. Delete Product\n";
                cout << "4. Search Product by ID\n";
                cout << "5. Search Product by Name\n";
                cout << "6. Display All Products\n";
                cout << "7. Display All Orders\n";
                cout << "8. Logout\n";

                cout << "Choice: ";

                int adminChoice = getInt();

                // -----------------------------------------
                // ADD PRODUCT
                // -----------------------------------------

                if (adminChoice == 1)
                {
                    productManager.addProduct();
                }

                // -----------------------------------------
                // UPDATE PRODUCT
                // -----------------------------------------

                else if (adminChoice == 2)
                {
                    productManager.updateProduct();
                }

                // -----------------------------------------
                // DELETE PRODUCT
                // -----------------------------------------

                else if (adminChoice == 3)
                {
                    productManager.deleteProduct();
                }

                // -----------------------------------------
                // SEARCH BY ID
                // -----------------------------------------

                else if (adminChoice == 4)
                {
                    productManager.searchByID();
                }

                // -----------------------------------------
                // SEARCH BY NAME
                // -----------------------------------------

                else if (adminChoice == 5)
                {
                    productManager.searchByName();
                }

                // -----------------------------------------
                // DISPLAY PRODUCTS
                // -----------------------------------------

                else if (adminChoice == 6)
                {
                    productManager.displayAll();
                }

                // -----------------------------------------
                // DISPLAY ALL ORDERS
                // -----------------------------------------

                else if (adminChoice == 7)
                {
                    orderManager.displayAllOrders();
                }

                // -----------------------------------------
                // LOGOUT
                // -----------------------------------------

                else if (adminChoice == 8)
                {
                    cout << "Admin logged out successfully!\n";
                    break;
                }

                else
                {
                    cout << "Invalid choice!\n";
                }
            }
        }

        // =========================================
        // DISPLAY PRODUCTS
        // =========================================

        else if (choice == 4)
        {
            productManager.displayAll();
        }

        // =========================================
        // EXIT
        // =========================================

        else if (choice == 5)
        {
            cout << "\n\nThank you for using Nepcart!\n";
            return 0;
        }

        else
        {
            cout << "Invalid choice!\n";
        }
    }
};
