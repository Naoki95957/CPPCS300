#include <fstream>
#include <iostream>
#include <algorithm>
#include "SpellChecker.h"

SpellChecker::SpellChecker(std::string dictionaryFile, int size)
:size(size)
{
    table = new LinkedList<std::string>[size];

    //begin inserting words:
    std::string str;
    std::ifstream file(dictionaryFile);
    
    while(std::getline(file, str))
    {
        int key = hashFunc(str);
        table[key].insertLast(str);
    }
    file.close();
}

void SpellChecker::checkSpelling(std::string testFile)
{
    LinkedList<std::string> badWords = LinkedList<std::string>();
    std::string str;
    std::ifstream file(testFile);
    
    while(std::getline(file, str))
    {
        std::string concat = "";
        for(int i = 0; i < str.size() + 1; ++i)
        {
            if(i < str.size() && str[i] != 32)
            {
                concat += str[i];
            }
            else
            {
                int key = hashFunc(concat);
                bool contains = false;
                for(int i = 0; i < table[key].size(); ++i)
                {
                    if(table[key].get(i) == concat)
                    {
                        contains = true;
                    }
                }
                if(!contains)
                {
                    badWords.insertLast(concat);
                }
                concat = "";
            }
        }
    }

    for(int j = 0; j < badWords.size(); ++j)
    {
        std::cout << badWords.get(j) << std::endl;
    }
    file.close();
}

int SpellChecker::countWordsBeginWith(std::string findMe)
{
    int key = hashFunc(findMe);
    int count = 0;
    for(int i = 0; i < table[key].size(); ++i)
    {
        if(std::string::npos != table[key].get(i).find(findMe))
        {
            ++count;
        }
    }
    return count;
}

SpellChecker::~SpellChecker()
{
    delete []  table;
}