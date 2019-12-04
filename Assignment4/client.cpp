#include <iostream>
#include <string>
#include "Constants.h"
#include "AuthenticationController.h"
//I used this for some of my own testing and debugging...
//This is not neccessary in anyway for the other files
int main()
{   
    AuthenticationController ac(100, 100);
    int total = 0;
    for(int i = 0; i < 10000; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            std::string user = "user" + std::to_string(i);
            std::string pass = "pass" + std::to_string(i) + std::to_string(j);
            ac.addUser(user, pass);
            // std::cout << "user " << user << " & pass " << pass << " : " <<  ac.addUser(user, pass) << " with total " << ++total << " users" << std::endl;
        }
    }

    return 0;
}