#include <iostream>

class part1
{
    public:
        static void exc1()
        {
            std::cout << "Enter a value of A: ";
            int a, b;
            std::cin >> a;
            
            std::cout << "Enter a value of B: ";
            std::cin >> b;

            std::cout << "Value of ptrA is " << a << " sored in address " << &a << std::endl;
            std::cout << "Value of ptrB is " << b << " sored in address " << &b << std::endl;

        }
        static void exc2()
        {
            int size;

            std::cout << "Enter number of values:";
            std::cin >> size;

            double* values = new double[size];

            std::cout << "Enter values:";
            for(double* ptr = values; ptr < (values + size * sizeof(double)); ptr += sizeof(double))
            {
                std::cin >> *ptr;
                std::cout << " ";
            }

            double* max = values;
            std::cout << "numbers:";
            for(double* ptr = values; ptr < (values + size * sizeof(double)); ptr += sizeof(double))
            {
                std::cout << *ptr << " ";
                if(*ptr > *max)
                {
                    max = ptr;
                }
            }

            std::cout << std::endl << "Maximum number: " << *max << std::endl;

            delete values, size;
            delete max;
        }
};