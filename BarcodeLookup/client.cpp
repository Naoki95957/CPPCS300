/**
 *  Naoki Lucas
 *  Nov. 17th 2019
 *  Client program
 * */

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "Structures/BinarySearchTree.h"
#include "Objects/Product.h"

///Aquire a file and fill binaryTree
void fileToTree(std::string fileName, BinarySearchTree<Product>& tree);

int main(){

    std::cout << "Building UPC tree..." << std::endl;

    BinarySearchTree<Product> productTree = BinarySearchTree<Product>();
    fileToTree("./Grocery_UPC_Database.csv", productTree);

    std::cout << "Done!" << "\n" << std::endl;

    std::cout << "Search for products or quit with \'q\' or \'Q\'" << "\n";

    //This is a fake product, and is only being used to search for the 12 digit upc
    bool quit = false;

    while(!quit)
    {
        //use this to obtain information when searching for product
        Product mockProduct = Product("","","","",true);
        std::cout << "UPC Code: ";
        std::string input = "";
        std::getline(std::cin, input);

        //exit if user wanted to quit
        if(input == "q" || input == "Q")
        {
            quit = true; 
            continue;
        }
        //else:
        //begin testing input
        bool pass = false;
        //I use try/catch expecting it to fail except when an input is valid
        try
        {
            int str_size = input.size();
            if(str_size == 12)//fixed size since all barcodes must be size of 12/14
            {
                std::stoull(input);//if it can parse it, it is a valid number
                mockProduct.setUpc12(input);
                pass = true;
            }
        }
        catch(const std::exception& e){/* ignored */}

        //resulting action after input testing
        if(!pass)
        {
            std::cout << "Please enter a valid 12 digit number" << "\n";
        }
        else
        {
            //Testing process time
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
            }
        }

        std::cout << "-------------------" << std::endl;
    }
    
    return 0;
}

static void fileToTree(std::string fileName, BinarySearchTree<Product>& tree)
{
    std::string str;
    std::ifstream file(fileName);
    
    std::getline(file, str);//skip the first line (since it's just metadata)

    while(std::getline(file, str))
    { 
        //read each line into line string

        //we know there is a consistent 4 commas or 
        //5 values per row in the format that follows:
        //id, upc14, upc12, brand, name
        std::string split_string [] = {"", "", "", "", ""};
        std::string delimiter = ",";
        //per each column
        for(int i = 0; i < 5; ++i)
        {   
            //in the event the string is empty
            if(str.empty())
            {
                split_string[i] = "";
                continue;
            }
            //collect a substring from the start pos to the first case of our delimiter
            std::string split = str.substr(0, str.find(delimiter));
            //assign that to our current column
            split_string[i] = split;
            //if there is no more text after this substring, end the loop
            if(split.size() + delimiter.size() >= str.size())
            {
                i = 5;
                continue;
            }
            //this is where the trick happens:
            //we truncate the string using the leading text from our substring and delimiter
            str = str.substr(split.size() + delimiter.size(), str.size() - 1);
        }
        //we insert each our strings into an object
        tree.insert(Product(split_string[2], split_string[1], split_string[3], split_string[4]));
    }
    file.close();
}