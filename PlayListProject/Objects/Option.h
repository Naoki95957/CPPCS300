//Name      :   Option.h
//Author    :   Naoki Lucas
//Date      :   10/02/2019
//Desc      :   Option object to simplify some code
#include <iostream>
#include <string>

///An option object that takes refrence to a function and gives it a name and trigger
class Option
{
    private:
        ///Function pointer
        void (* pMyOption)(void);
        ///This is the string that it looks to match for the trigger
        std::string triggerStr;
        ///This is the option name for reference
        std::string optionName;
    public:
        ///pass it a void-function pointer and a name for the option
        Option(void (* ptr)(), std::string optionName, std::string triggerStr)
            :pMyOption(ptr), optionName(optionName), triggerStr(triggerStr)
        {}
        ///test if the input matches the trigger
        bool testTrigger(std::string) const;
        ///returns the input trigger
        std::string getTrigger() const;
        ///returns the option name
        std::string getOptionName() const;
        ///run the option
        void executeOption() const;

        ///prints the option
        friend std::ostream& operator<<(std::ostream& out, const Option& option);
};