#include <iostream>
#include "Stack/ArrayStack.h"

int main()
{   
    ArrayStack<char> myStack = ArrayStack<char>(100);

    std::cout << "Please input either of these options (up to 100 \'(\' chars): \'(\', \')\', \'q\'" << std::endl;
    
    bool isRunning = true;
    char input = 0;
    //main loop
    while(isRunning)
    {
        //conveniently reads each char 
        std::cin >> input;
        switch (input)
        {
        case '(':
            myStack.push('(');
            break;
        case ')':
            myStack.pop();
            break;
        case 'q':
            isRunning = false;
            break;
        default:
            //std::cout << "Please enter a valid character" << std::endl;//optionally do nothing
            break;
        }
    }
    
    std::cout << (myStack.isEmpty() ? "Balanced" : "Unbalanced") << std::endl;
    return 0;
}