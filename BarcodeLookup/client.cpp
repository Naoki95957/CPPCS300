#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "Structures/BinarySearchTree.h"
#include "Objects/Product.h"

///Aquire a file and fill binaryTree
void fileToTree(std::string fileName, BinarySearchTree<Product>& tree);

int main(){
    BinarySearchTree<Product> productTree = BinarySearchTree<Product>();
    fileToTree("./Grocery_UPC_Database.csv", productTree);

    Product mockProduct = Product("","","","",true);
    bool pass = false;
    while(!pass)
    {
        std::cout << "UPC Code: ";
        std::string input = "";
        std::getline(std::cin, input);
        try
        {
            int str_size = input.size();
            std::stoull(input);//if it can parse it, it is a valid number
            mockProduct.setUpc12(input);
            pass = str_size == 12;
        }
        catch(const std::exception& e)
        {   
        }
        if(!pass)
        {
            std::cout << "Please enter a valid 12 digit number" << std::endl;
        }
    }
    clock_t t;
    t = clock();
    bool result = productTree.search(mockProduct);
    t = clock() - t;
    if(!result)
    {
        std::cout << "Not found" << "\n";
    }
    else
    {
        std::cout << mockProduct.getName() << "\n";
        std::cout << "Lookup time: " << t << " miliseconds" << "\n";
        std::cout << CLOCKS_PER_SEC << " clocks per second" << "\n";
        std::cout << "time: " << t*1.0/CLOCKS_PER_SEC << " seconds" << std::endl;
    }
    
    return 0;
}

void fileToTree(std::string fileName, BinarySearchTree<Product>& tree)
{
    std::string str;
    std::ifstream file(fileName);
    std::getline(file, str);//skip the first line (since it's just metadata)
    while(std::getline(file, str))
    { 
        //read each line into line string

        //we know there is a consistent 4 commas or 5 values
        //in the format that follows:
        //id, upc14, upc12, brand, name
        std::string split_string [] = {"", "", "", "", ""};
        std::string delimiter = ",";
        for(int i = 0; i < 5; ++i)
        {
            if(str.empty())
            {
                split_string[i] = "";
                continue;
            }
            std::string split = str.substr(0, str.find(delimiter));
            split_string[i] = split;
            if(split.size() + delimiter.size() >= str.size())
            {
                i = 5;
                continue;
            }
            str = str.substr(split.size() + delimiter.size(), str.size() - 1);
        }
        tree.insert(Product(split_string[2], split_string[1], split_string[3], split_string[4]));
    }
    file.close();
}