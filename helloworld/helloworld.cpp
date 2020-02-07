#include <iostream>
#include <string>
#include "part1.cpp"
#include "part2.cpp"
#include "part3.cpp"
#include "my_class.hpp"

void forfun();
void basicPointers();
void pointerNonsense();
void bitwise()
{
    //typecast hackery to bitwise on a float...
    float a = 0;
    int* p = (int*)&a;
    *p = 1 << (1, 8);
    std::cout << a << std::endl;
}

int main()
{   

    return 0;
}

void pointerNonsense()
{
    int a [] = {4, 5, 6};

    for(int i = 0; i < 3; ++i)
    {
        std::cout << "Element " << i << ":" << std::endl;
        std::cout << *(a + i) << std::endl;
        std::cout << *(i + a) << std::endl;
        std::cout << a[i] << std::endl;
        std::cout << i[a] << std::endl;
        std::cout << 0[a + i] << std::endl;
        std::cout << (a + i)[0] << std::endl;
        //And if NULL is by definition 0...
        std::cout << NULL[a + i] << std::endl;
        std::cout << (a + i)[NULL] << std::endl;
        std::cout << std::endl;
    }

    std::cout << "This will also run:" << std::endl;
    //All cout statements bellow are equivalent
    int b = 123;
    int * ptr = &b;

    std::cout << b << std::endl;
    std::cout << *&b << std::endl;
    std::cout << *ptr << std::endl;
    std::cout << ptr[0] << std::endl;
    std::cout << 0[ptr] << std::endl;
    std::cout << (&b)[0] << std::endl;
    std::cout << 0[&b] << std::endl;
    //And if NULL is by definition 0...
    std::cout << NULL[ptr] << std::endl;
    std::cout << ptr[NULL] << std::endl;
    std::cout << NULL[&b] << std::endl;
    std::cout << (&b)[NULL] << std::endl;
}


void basicPointers()
{   
    ///this is a regular int
    int x = 20;
    ///This is a pointer
    int* p = &x;

    
    std::cout<<p<<std::endl;
    std::cout<<*p<<std::endl;

    *p = 10;

    std::cout<<x<<std::endl;
    std::cout<<&x<<std::endl;
}

void forfun()
{
    int arr []= {1, 2, 3, 4, 5};

    std::cout<<"For-each mehtod"<<std::endl;
    for(int y : arr)
    {
        std::cout<<y<<std::endl;
    }

    std::cout<<"Regular old boring for loop"<<std::endl;
    for(int i = 0; i < 5; ++i)
    {
        std::cout<<arr[i]<<std::endl;
    }

    std::cout<<"For with pointers"<<std::endl;
    for(int* p = &arr[0]; p <= &arr[4]; ++p)
    {
        std::cout<<*p<<std::endl;
    }
}