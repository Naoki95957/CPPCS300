#include <iostream>

class part2
{   
    public:
        static void exc1()
        {
            int * a = new int;
            int * b = new int;

            std::cout << "Enter value of A: ";
            std::cin >> *a;
            
            std::cout << "Enter value of B: ";
            std::cin >> *b;

            std::cout << "Value of ptrA is " << *a << "sored in address " << a;
            std::cout << "Value of ptrB is " << *b << "sored in address " << b;

            delete a, b;
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