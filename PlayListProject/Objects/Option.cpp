//Name      :   Option.cpp
//Author    :   Naoki Lucas
//Date      :   10/02/2019
//Desc      :   Option object to simplify some code
#include "Option.h"

void Option::executeOption() const
{
    (*pMyOption)();
    return;
}

bool Option::testTrigger(std::string triggerStr) const
{
    return (Option::triggerStr == triggerStr);
}

std::string Option::getTrigger() const
{
    return triggerStr;
}

std::string Option::getOptionName() const
{
    return optionName;
}

std::ostream& operator<<(std::ostream& out, const Option& option)
{
    out << "(" << option.getTrigger() << ") "
        << option.getOptionName() << "\n";
    return out;
}