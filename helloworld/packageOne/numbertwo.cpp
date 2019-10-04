#include <iostream>
#include "numbertwo.h"

no2::no2(int num)
{
    no2::myNumber = num;
    std::cout << "constructor" << std::endl;
}

void no2::print()
{
    no2::no_secretPrint();
}

no2::~no2()
{
    std::cout << "destrcutor" << std::endl;
}
