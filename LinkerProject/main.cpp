#include <iostream>
#include "Lists/LinkedList.cpp"

int main()
{
    LinkedList<double> list = LinkedList<double>();
    list.insertFirst(50);
    list.insertFirst(20.1);
    list.insertFirst(30.1);
    list.insertFirst(40.1);
    list.insertFirst(50.1);
    list.insertFirst(6.10);
    list.insertFirst(7.10);
    list.insertFirst(80.1);


    std::cout << "size: " << list.size() << "\n";
    std::cout << "list: " << list;
    std::cout << "\n";
    std::cout << std::endl;
    
    list.insert(99.99, list.size() - 1);

    std::cout << "size: " << list.size() << "\n";
    std::cout << "list: " << list;
    std::cout << "\n";
    std::cout << std::endl;


    list.move(0, 5);
    
    std::cout << "size: " << list.size() << "\n";
    std::cout << "list: " << list;
    std::cout << "\n";
    std::cout << std::endl;
    
    list.move(0, list.size() - 1);
    
    std::cout << "size: " << list.size() << "\n";
    std::cout << "list: " << list;
    std::cout << "\n";
    std::cout << std::endl;

    return 0;
}