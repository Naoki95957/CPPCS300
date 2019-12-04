#include "AuthenticationController.h"
#include "Constants.h"
#include <algorithm>
typedef AuthenticationController AuthC;

AuthC::AuthenticationController(int table1Size, int table2Size)
{
    table1 = std::vector<user>(table1Size);
    table2 = std::vector<std::string>(table2Size);
    allUsers = std::vector<std::string>(1);
    
    for(user & person : table1)
    {
        person.username = "EMPTY";
        person.password = "EMPTY";
    }
    for (std::string & active : table2)
    {
        active = "EMPTY";
    }
}

int AuthC::addUser(std::string username, std::string pass)
{
    bool found = false;
    for(int j = 0; j < allUsers.size(); ++j)
    {
        if(allUsers[j]._Equal(username.c_str()))
        {
            found = true;
            break;
        }
    }
    if(!found)
    {
        allUsers.push_back(username);
    }


    for(int i = 0; i < table1.size(); ++i)
    {
        int key = hashFunction(username, table1.size(), i);
        if(key < 0)
        {
            continue;
        }
        if(table1[key].username == "EMPTY" || (table1[key].username._Equal(username) && !table1[key].password._Equal(pass)))
        {
            table1[key].username = username;
            table1[key].password = pass;
            //check the load factor
            double sum = 0;
            for(int j = 0; j < table1.size(); ++j)
            {
                if(table1[j].username != ("EMPTY"))
                {
                    ++sum;
                }
            }
            if(sum / (double) table1.size() >= MAX_LOAD_FACTOR)
            {
                expandTable(table1);
            }
            return 1;
        }
    }
    return 0;
}

int AuthC::delUser(std::string username)
{
    for(int i = 0; i < table1.size(); ++i)
    {
        int key = hashFunction(username, table1.size(), i);

        if(table1[key].username._Equal(username))
        {
            table1[key].username = "DELETED";
            table1[key].password = "DELETED";
            return 1;
        }   
    }
    return 0;
}

int AuthC::changePass(std::string username, std::string oldpass, std::string newpass)
{
    for(int i = 0; i < table1.size(); ++i)
    {
        int key = hashFunction(username, table1.size(), i);
        if(table1[key].username._Equal(username) && table1[key].password._Equal(oldpass))
        {
            table1[key].password = newpass;
            return 1;
        }
    }
    return 0;
}

int AuthC::login(std::string username, std::string pass)
{
    int loginIndex = 0;
    for(; loginIndex < table2.size(); ++loginIndex)
    {
        if(table2[loginIndex]._Equal(username))
        {
            //std::cerr << "Already logged on" << std::endl;
            return 0;
        }
        else if(table2[loginIndex]._Equal("EMPTY"))
        {
            //keeps the index value
            break;
        }
        else if((double)loginIndex / (double)table2.size() >= MAX_LOAD_FACTOR)
        {
            expandTable(table2);
            login(username, pass);
        }
    }
    //check password from user
    for(int i = 0; i < table1.size(); ++i)
    {
        int key = hashFunction(username, table1.size(), ++i);
        if(table1[key].username._Equal(username) && table1[key].password._Equal(pass))
        {
            table2[loginIndex] = table1[key].username;
            return 1;
        }
    }
    return 0;
}

int AuthC::logout(std::string username)
{
    int loginIndex = 0;
    for(; loginIndex < table2.size(); ++loginIndex)
    {
        if(table2[loginIndex]._Equal(username))
        {
            //found the user
            table2[loginIndex] = "EMPTY";
            return 1;
        }
    }
    return 0;
}

float AuthC::printActiveUsers()
{
    float count = 0;
    for(std::string users : table2)
    {
        if(users._Equal("EMPTY"))
        {
            //assignment makes that anything after the first empty will all be empty
            break;
        }
        std::cout << users << "\n";
        ++count;
    }
    std::cout << std::endl;
    return count / table2.size();
}

float AuthC::printPasswords()
{
    float count = 0;
    for(user persons : table1)
    {
        if(!persons.password._Equal("EMPTY"))
        {
            std::cout << persons.password << "\n";
            ++count;
        }
    }
    std::cout << std::endl;
    return count / table1.size();
}