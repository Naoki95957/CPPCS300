#include <iostream>
#include "LinkedList.cpp"

void sample1();
void sample2();
void sample3();
void sample4();
void sample5();

int main()
{
    sample5();
    return 0;
}

void sample1()
{
    LinkedList list;
    list.insert_last(10);
    list.insert_last(30);
    list.insert_last(10);
    list.insert_last(20);
    list.insert_last(10);
    std::cout << list.countItems(10) << std::endl;
}

void sample2()
{
    LinkedList list;
    list.insert_last(10);
    list.insert_last(30);
    list.insert_last(10);
    list.insert_last(20);
    list.insert_last(10);
    std::cout << list.sum() << std::endl;
}

void sample3()
{
    LinkedList list;
    list.insert_last(10);
    list.insert_last(20);
    list.insert_last(30);
    list.insert_last(40);
    list.insert_last(50);
    list.printMiddle();
}

void sample4()
{
    LinkedList list;
    list.insert_last(10);
    list.insert_last(20);
    list.insert_last(30);
    list.insert_last(40);
    list.insert_last(50);
    list.reverse();
    std::cout << list << std::endl;
    list.reverse();
    std::cout << list << std::endl;
}

void sample5()
{
    LinkedList a;
    LinkedList b;

    a.insert_last(10);
    a.insert_last(20);
    a.insert_last(30);
    a.insert_last(40);
    a.insert_last(50);

    std::cout << a << std::endl;
    b = a;
    a.remove(40);
    std::cout << b << std::endl;
    b = a;
    std::cout << b << std::endl;
    LinkedList c(a);
    std::cout << c << std::endl;
}