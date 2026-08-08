#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "User.h"
#include "utilities.h"

using namespace std;

class UserManager
{
private:
    const string USER_FILE;
    vector<User> users;

public:
    UserManager() : USER_FILE("users.txt")
    {
        loadUsers();
    }

    // ================= LOAD USERS =================

    void loadUsers()
    {
        ifstream fin(USER_FILE);

        if (!fin.is_open())
            return;

        string line;

        while (getline(fin, line))
        {
            stringstream ss(line);

            string username;
            string password;

            getline(ss, username, '|');
            getline(ss, password);

            if (!username.empty())
            {
                users.push_back(
                    User(username, password));
            }
        }

        fin.close();
    }

    // ================= CHECK USERNAME =================

    bool usernameExists(const string &username)
    {
        for (const User &user : users)
        {
            if (user.getUsername() == username)
                return true;
        }

        return false;
    }

    // ================= REGISTER =================

    bool registerUser()
    {
        string username;
        string password;

        cout << "\n========== REGISTER ==========\n";

        cout << "Username: ";
        cin >> username;

        if (usernameExists(username))
        {
            cout << "Username already exists!\n";
            return false;
        }

        cout << "Password: ";
        cin >> password;

        users.push_back(
            User(username, password));

        saveUsers();

        cout << "Registration successful!\n";

        return true;
    }

    // ================= LOGIN =================

    bool login(string &loggedInUsername)
    {
        string username;
        string password;

        cout << "\n========== LOGIN ==========\n";

        cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        for (const User &user : users)
        {
            if (user.getUsername() == username &&
                user.getPassword() == password)
            {
                loggedInUsername = username;

                cout << "Login successful!\n";

                return true;
            }
        }

        cout << "Invalid username or password!\n";

        return false;
    }

    // ================= SAVE USERS =================

    void saveUsers()
    {
        ofstream fout(USER_FILE, ios::trunc);

        if (!fout.is_open())
        {
            cerr << "Cannot open users file.\n";
            return;
        }

        for (const User &user : users)
        {
            fout << user.getUsername()
                 << '|'
                 << user.getPassword()
                 << '\n';
        }

        fout.close();
    }
};