#include <String>

class Product
{   
    bool mockProduct = false;
    //should be char-array with a fixed size of 12
    std::string upc_12;
    //should be char-array with a fixed size of 14
    std::string upc_14;
    //brand name
    std::string brand;
    //product name
    std::string name;

    public:
        Product(std::string upc_12 = "", std::string upc_14 = "", std::string brand = "", 
            std::string name = "", bool mockProduct = false)
        :upc_12(upc_12), upc_14(upc_14), brand(brand), name(name), 
            mockProduct(mockProduct)
        {}

        void setUpc12(std::string new_upc_12)
        {
            upc_12 = new_upc_12;
        }

        std::string getName()
        {
            return name;
        }

        //This particular function is where I get crafty by sorta making this an assignment operation
        void copyOver(Product & p)
        {
            if(mockProduct)
            {
                brand = p.brand;
                name = p.name;
                upc_14 = p.upc_14;
            }
        }
        //comparing just the GS1, GTIN standard (this then relies on the UPC-12 being unique)
        bool operator==(Product & p)
        {   
            copyOver(p);
            return (std::stoull(upc_12) == std::stoull(p.upc_12));
        }

        bool operator<(Product & p)
        {
            return (std::stoull(upc_12) < std::stoull(p.upc_12));
        }

        bool operator>(Product & p)
        {
            return (std::stoull(upc_12) > std::stoull(p.upc_12));
        }
};