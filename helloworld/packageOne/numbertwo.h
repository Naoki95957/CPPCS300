#include <string>

class no2
{
    public:
        int myNumber;

        no2(int x);
        ~no2();
        void print();

    private:
    
    void no_secretPrint()
    {
        std::cout << std::string("My number is ") + std::to_string(no2::myNumber) << std::endl;
    }
};