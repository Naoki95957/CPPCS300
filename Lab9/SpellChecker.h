#include <string>
#include "LinkedList.h"

#ifndef SPELLCHECK_H
#define SPELLCHECK_H

class SpellChecker
{
    private:
        LinkedList<std::string> * table;
        int size;
        int hashFunc(std::string word)
        {
            return word[0];
        }
    public:
        SpellChecker(std::string dictionaryFileDir, int size = 256);
        void checkSpelling(std::string fileDir);
        int countWordsBeginWith(std::string delimeter);
        ~SpellChecker();
};

#endif