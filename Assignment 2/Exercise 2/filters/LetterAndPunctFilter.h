#ifndef CE221ASS2_LETTERANDPUNCTFILTER_H
#define CE221ASS2_LETTERANDPUNCTFILTER_H

using namespace std;
#include <string>
#include "../ReadWords.h"
#include "../ReadFilteredWords.h"

class LetterAndPunctFilter: public ReadFilteredWords {
public:
    LetterAndPunctFilter(const char *fname) : ReadFilteredWords(fname) {};

    bool filter(string word);
};

#endif
