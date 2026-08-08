#pragma once
#include <iostream>
#include <string>

using namespace std;

class User
{
private:
    string username;
    string password;

public:
    // Default constructor
    User()
    {
        username = "";
        password = "";
    }

    // Parameterized constructor
    User(string u, string p)
    {
        username = u;
        password = p;
    }

    // Getters
    string getUsername() const
    {
        return username;
    }

    string getPassword() const
    {
        return password;
    }

    // Setters
    void setUsername(string u)
    {
        username = u;
    }

    void setPassword(string p)
    {
        password = p;
    }
};
