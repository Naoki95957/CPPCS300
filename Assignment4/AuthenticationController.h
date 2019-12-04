#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include <vector>
#include "Constants.h"

#define MAX_LOAD_FACTOR 0.65

//a structure defines user entry
struct user
{        
    std::string username;
    std::string password;
};

class AuthenticationController
{

    std::vector<user> table1;            //a dynamic array that stores registered users
    std::vector<std::string> table2;          //a dynamic array that stores active users (logged in)
    std::vector<std::string> allUsers;

	int registeredTableSize;        //capacity of table1, registered users tabls
	int activeTableSize;            //capacity of table2, active users table
	int regCount;                   //current registered user count
	int activeCount;                //current active users counr

    //double hashing
	int hashFunction(std::string key, int tableSize, int i) 
    {
		int length = key.length();
		int newK = 0;
		for (int j = 0; j < length; ++j)
			newK += (int) key[j];
			// hash function 1 -> (newK % tableSize)
			// hash function 2 -> (newK * tableSize - 1) % tableSize)
		return ((newK % tableSize) + i * ((newK * tableSize - 1) % tableSize)) % tableSize;
	}

    void expandTable(std::vector<user>& table)
    {
        int newSize = 2 * table.size();
        for(int i = 0; i < 1000000; ++i)//I have the first 1M primes...
        {
            if(Constants::primes(i) >= newSize)
            {
                newSize = Constants::primes(i);
                break;
            }
        }
        //we now have the new size
        user blankUser;
        blankUser.username = "EMPTY";
        blankUser.password = "EMPTY";
        std::vector<user> newTable = std::vector<user>(newSize, blankUser);
        //lets go thru and hash all new users
        for(std::string user : allUsers)
        {
            bool inserted = false;
            for(int i = 0; i < table.size() && !inserted; ++i)
            {
                for(int j = 0; j < newTable.size() && !inserted; ++j)
                {
                    //probe for all valid user entries
                    int key = hashFunction(user, table.size(), i);
                    if(key < 0)
                    {
                        break;
                    }
                    if(table[key].username != "EMPTY" || table[key].username != "DELETED")
                    {
                        //probe to insert all said entries into new table
                        int newKey = hashFunction(user, newTable.size(), j);
                        if(newKey < 0)
                        {
                            continue;
                        }
                        if(newTable[newKey].username == "EMPTY")
                        {
                            newTable[newKey] = table[key];
                            inserted = true;
                            break;
                        }
                    }
                }
            }
        }
        table = newTable;
    }

    //this is only used for the active users and I have it done w/out hashing
    void expandTable(std::vector<std::string>& table)
    {
        int newSize = 2 * table.size();
        for(int i = 0; i < 1000000; ++i)
        {
            if(Constants::primes(i) >= newSize)
            {
                newSize = Constants::primes(i);
                break;
            }
        }
        table.resize(newSize, "EMPTY");
    }

  public:
    //initialize the tables
    //Set entries of table 1 to < "EMPTY","EMPTY">
    //Set entries of table 2 to "EMPTY"
	AuthenticationController(int table1Size, int table2Size);


    //register the given user with username and password to 
    //registered users table if not registered
    //return 1 if successful, 0 if not.
	int addUser(std::string username, std::string pass);

    //delete all entries of that user
    //Put <"DELETED","DELETED"> as deleted entry
    //return 1 if the user is registered else just return 0
	int delUser(std::string username);

    //change the password of the given user if user is registered and 
    //oldpassword is equal the current password. While changing the password, 
    //keep the old entries <username,oldpassword> in the table and add 
    //new entry <username,newpassword> To the next empty cell that is 
    //found with the hash function. Last entry addes is the current 
    //password of that user. If operation is successful return 1, else return 0
	int changePass(std::string username, std::string oldpass, std::string newpass);

    //if the user is registered and password is the current 
    //password of given user, log the user in and return 1, 
    //if not do nothing and return 0.
	int login(std::string username, std::string pass);

    //if the given user is logged in, log that user out and retun 1, 
    //if not return 0
    //Put “DELETED” for logged out users. 
	int logout(std::string username);

    //print all logged in users 
    //print “DELETED” for deleted entries, “EMPTY” for empty entries
    //returns load factor.
	float printActiveUsers();

    //print all users and passwords, print “DELETED DELETERED” for deleted entries
    //print “EMPTY EMPTY” for empty entries
    //returns load factor. 
	float printPasswords();
	


};

#endif