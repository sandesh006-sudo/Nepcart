#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// to get valid integer input
int getInt()
{
    string input;

    while (true)
    {
        getline(cin >> ws, input);

        try
        {
            return stoi(input);
        }
        catch (const invalid_argument &)
        {
            cout << "Please enter a valid number: ";
        }
        catch (const out_of_range &)
        {
            cout << "Number is too large: ";
        }
    }
}

// to get valid double input
double getDouble()
{
    string input;

    while (true)
    {
        getline(cin >> ws, input);

        try
        {
            return stod(input);
        }
        catch (const invalid_argument &)
        {
            cout << "Please enter a valid number: ";
        }
        catch (const out_of_range &)
        {
            cout << "Number is too large: ";
        }
    }
}

// to lowercase a string
string lower(string str)
{
    for (char &c : str)
    {
        c = tolower(c);
    }
    return str;
}