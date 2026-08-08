#include <iostream>
#include <string>

using namespace std;

class admin
{
private:
    string username;
    string password;
public:

    admin()
    {
        username = "admin";
        password = "1234";
    }


    bool login(string u, string p)
    {
        if(username == u && password == p)
        {
            return true;
        }

        return false;
    }

    void addProduct(...);

    void removeProduct(...);

    void updateProduct(...);

    void viewOrders();
};
