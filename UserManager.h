#include <iostream>
#include "User.h"

using namespace std;

class usermanager
{
private:
    user users[10];
    int usercount;

public:

    usermanager()
    {
        usercount = 0;
    }


    void registeruser(string username, string password)
    {
        if(usercount < 10)
        {
            users[usercount] = user(username, password);
            usercount++;

            cout << "Registration successful.\n";
        }
        else
        {
            cout << "User limit reached.\n";
        }
    }


    bool login(string username, string password)
    {
        for(int i = 0; i < usercount; i++)
        {
            if(users[i].getusername() == username &&
               users[i].getpassword() == password)
            {
                return true;
            }
        }

        return false;
    }
};
