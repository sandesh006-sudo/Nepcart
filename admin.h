#pragma once

#include <iostream>
#include <string>

using namespace std;

class Admin
{
private:
    const string username = "admin";
    const string password = "admin123";

public:
    bool login()
    {
        string inputUsername;
        string inputPassword;

        cout << "\n========== ADMIN LOGIN ==========\n";

        cout << "Username: ";
        cin >> inputUsername;

        cout << "Password: ";
        cin >> inputPassword;

        if (inputUsername == username &&
            inputPassword == password)
        {
            cout << "Admin login successful!\n";
            return true;
        }

        cout << "Invalid admin credentials!\n";
        return false;
    }
};