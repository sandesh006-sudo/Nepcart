# 🛒 Nepcart

**Nepcart** is a console-based e-commerce system developed in **C++** as a group project for studying and applying **Object-Oriented Programming (OOP)** concepts.

The system provides separate functionality for customers and administrators, including product management, user authentication, shopping carts, order processing, stock management, and file-based data persistence.

---

## ✨ Features

### 👤 Customer

* User registration
* User login
* Browse available products
* Search products by ID
* Search products by name
* Add products to cart
* Remove products from cart
* View cart and total price
* Place orders
* View previous orders
* Automatic stock reduction after placing an order

### 🔐 Admin

* Admin login
* Add products
* Update product information
* Delete products
* Search products
* Display all products
* Manage product stock
* View all orders

### 📦 Product Management

* Unique product IDs
* Product names and categories
* Product prices
* Product quantities
* Input validation
* Case-insensitive product name searching
* Stock validation before ordering

### 💾 File Handling

Nepcart uses text files to persist data between program executions:

* `products.txt` — stores product information
* `users.txt` — stores registered user information
* `orders.txt` — stores completed orders

---

## 🧱 Project Structure

```text
Nepcart/
│
├── Main.cpp
│
├── Product.h
├── ProductManager.h
│
├── User.h
├── UserManager.h
│
├── CartItem.h
├── Cart.h
│
├── Order.h
├── OrderManager.h
│
├── utilities.h
│
├── products.txt
├── users.txt
└── orders.txt
```

---

## 🏗️ Class Structure

```text
                    ProductManager
                          │
                          │ manages
                          ▼
                       Product
                          ▲
                          │
                          │ contains
                          │
                      CartItem
                          │
                          │ contains
                          ▼
                         Cart
                          │
                          │ checkout
                          ▼
                        Order
                          │
                          │ manages
                          ▼
                    OrderManager


                    UserManager
                          │
                          │ manages
                          ▼
                         User
```

---

## 🧠 OOP Concepts Used

The project demonstrates several C++ and OOP concepts:

* **Encapsulation** — class data members are private and accessed through public member functions.
* **Abstraction** — individual classes handle specific responsibilities such as products, users, carts, and orders.
* **Composition** — `Cart` contains `CartItem` objects, while `Order` contains purchased `CartItem` objects.
* **Classes and Objects** — real-world entities are represented using C++ classes.
* **Constructors** — default and parameterized constructors are used for object initialization.
* **Const Member Functions** — getter and display functions that don't modify objects use `const`.
* **STL Vectors** — `vector` is used to dynamically store collections of objects.
* **File Handling** — `ifstream` and `ofstream` are used for persistent data storage.
* **Exception Handling** — exceptions from functions such as `stoi()` are handled during input validation.
* **References and Pointers** — references and pointers are used when working with objects and searching for products.

---

## 🔄 Order Process

```text
              Login
                │
                ▼
         Browse Products
                │
                ▼
        Add Products to Cart
                │
                ▼
            View Cart
                │
                ▼
          Place Order
                │
        ┌───────┴────────┐
        ▼                ▼
   Check Stock      Create Order
        │                │
        ▼                │
  Reduce Stock           │
        │                │
        ▼                ▼
 Save Products       Save Order
        │                │
        └───────┬────────┘
                ▼
           Clear Cart
```

---

## 📄 Data Storage

Nepcart uses a simple delimiter-based text format instead of a database.

### Products

```text
ID|Name|Category|Price|Quantity
```

Example:

```text
101|Mechanical Keyboard|Accessories|75.99|10
```

### Users

```text
Username|Password
```

### Orders

Orders can contain multiple products, so multiple delimiters are used to organize the data.

```text
OrderID;Username;Total;ProductID|Name|Price|Quantity~ProductID|Name|Price|Quantity
```

Where:

* `;` separates major order information.
* `~` separates different products in an order.
* `|` separates information belonging to a product.

---

## 🛠️ Technologies

* **C++**
* **Object-Oriented Programming**
* **C++ Standard Template Library (STL)**
* **File Handling**
* **Git**
* **GitHub**

---

## ▶️ How to Run

### Clone the repository

```bash
git clone <repository-url>
cd Nepcart
```

### Compile

```bash
g++ Main.cpp -o Nepcart
```

### Run

```bash
./Nepcart
```

> If the project is later split into multiple `.cpp` files, include those source files in the compilation command as well.

---

## 👥 Group Members

This project was developed collaboratively by:

| Name               | Role      |
| ------------------ | --------- |
| **Sabal Khadka**   | Developer |
| **Sandesh Kattel** | Developer |
| **Sujal Shrestha** | Developer |
| **Sudip Dhakal**   | Developer |
| **Sujit Acharya**  | Developer |

All members contributed to the development and implementation of the project.

---

## 🎓 Project Context

Nepcart was developed as an **academic group project** to apply concepts learned in **Object-Oriented Programming using C++**.

The primary focus of the project is demonstrating:

* Object-oriented design
* Class relationships
* Encapsulation and abstraction
* File handling
* Data management
* Input validation
* Collaborative development using Git and GitHub

---

## 📌 Project Status

**Completed — Academic OOP Group Project**

Nepcart is intended as an educational project and is not designed as a production-ready e-commerce platform.
