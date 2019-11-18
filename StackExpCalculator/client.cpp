//Name      :   client.cpp
//Author    :   Naoki Lucas
//Date      :   10/30/2019
//Desc      :   Stack calculator

#include <iostream>
#include <string>
#include "Stack/LinkedStack.h"

LinkedStack<int> numberStack = LinkedStack<int>();
bool resultStored = false;
int result = NULL;//since this is/can-be zero, I need a bool to flag when a result is actually is stored 

//defined below main
//
///Takes a string input and does what it needs to 
void processInput(std::string str);

int main()
{   
    std::cout << "Enter the expression: ";

    std::string concat = "";

    std::cin.unsetf(std::ios_base::skipws);//stops skipping white space

    char input = ' ';
    while(input != '\\' || !resultStored)//if this character is found & a result is stored, this begins termination
    {
        if(input == '\\')//if this char and result wasn't stored:
        {
            std::cout << "missing operands (must pop a result! [^])" << std::endl;
        }
        std::cin >> input;//per char
        if(input == ' ' || input == '\n')//this is our delimiter in a way
        {
            processInput(concat);//process the put-together string
            concat = "";
        }
        else
        {
            concat += input;//builds up the string for input
        }
    }
    std::cout << "result: " << result << std::endl;
    return 0;
}

//insteading of throwing this into a while loop, 
//I decided to move this into it's own function call
void processInput(std::string str)
{
    if(str == "" || str == "\\")return;//incase you're like me and put a white space just before you hit enter for some reason

    ///this popped bool is to replace the popped element in the case a 2nd doesn't exist
    bool popped = false;
    int val1;//needed to create val here since I can't instantiate in each case & need it outside of try/catch

    //technically if you have something like 'blah+' the program will run with it.
    //I could check the size of the string to ensure it is indeed just one char,
    //but honestly I don't see this scenario needing attention
    switch (str.back())
    {
    case '+':
        popped = false;
        val1 = NULL;
        //try/catch is because I expect my stack to throw if I request a number when the stack is empty
        //and I am using that to handle some operations
        try
        {
            val1 = numberStack.top();
            popped = true;
            int val2 = numberStack.top();
            numberStack.push(val1 + val2);
        }
        catch(const std::exception& e)
        {
            if(popped)//if true, then one value is popped but needs to be put back
                numberStack.push(val1);
            std::cout << "missing operands" << std::endl;
        }
        break;
    
    case '-':
        popped = false;
        val1 = NULL;
        try
        {
            val1 = numberStack.top();
            popped = true;
            int val2 = numberStack.top();
            numberStack.push(val1 - val2);
        }
        catch(const std::exception& e)
        {
            if(popped)
                numberStack.push(val1);
            std::cout << "missing operands" << std::endl;
        }
        break;
    
    case '*':
        popped = false;
        val1 = NULL;
        try
        {
            val1 = numberStack.top();
            popped = true;
            int val2 = numberStack.top();
            numberStack.push(val1 * val2);
        }
        catch(const std::exception& e)
        {
            if(popped)
                numberStack.push(val1);
            std::cout << "missing operands" << std::endl;
        }
        break;
    
    case '/':
        popped = false;
        val1 = NULL;
        try
        {
            val1 = numberStack.top();
            popped = true;
            int val2 = numberStack.top();
            numberStack.push(val1 / val2);
        }
        catch(const std::exception& e)
        {
            if(popped)
                numberStack.push(val1);
            std::cout << "missing operands" << std::endl;
        }
        break;
    
    case '%':
        popped = false;
        val1 = NULL;
        try
        {
            val1 = numberStack.top();
            popped = true;
            int val2 = numberStack.top();
            numberStack.push(val1 % val2);
        }
        catch(const std::exception& e)
        {
            if(popped)
                numberStack.push(val1);
            std::cout << "missing operands" << std::endl;
        }
        break;
    case '^':
        val1 = NULL;
        try
        {
            val1 = numberStack.top();
            std::cout << val1 << std::endl;
            resultStored = true;
            result = val1;
        }
        catch(const std::exception& e)
        {
            if(popped)
                numberStack.push(val1);
            std::cout << "missing operands" << std::endl;
        }
        break;

    case '<':
        //kinda weird, but since I only grab the back char, I check to make sure the original string is "<<"
        if((str.length() == 2) && (str.front() == '<'))
        {
            std::cout << numberStack << std::endl;
        }
        else
        {
            //error with input
            std::cout << "invalid input" << std::endl;
        }
        break;
    
    default:
        //this is all scenarios that don't end with any of operator characters
        try
        {   
            ///parses input to an integer
            int val = std::stoi(str);
            numberStack.push(val);
        }
        catch(const std::exception& e)
        {
            std::cout << "invalid input" << std::endl;
        }
        break;
    }
}