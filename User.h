#include <iostream>
#include <string>

using namespace std;

class user
{
private:
    string username;
    string password;

public:

    user(string u="", string p="")
    {
        username = u;
        password = p;
    }

    string getusername()
    {
        return username;
    }

    string getpassword()
    {
        return password;
    }
};
