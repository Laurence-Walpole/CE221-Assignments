#ifndef CE221ASS2_DIGITSFILTER_H
#define CE221ASS2_DIGITSFILTER_H

using namespace std;
#include <string>
#include "../ReadWords.h"
#include "../ReadFilteredWords.h"


class DigitsFilter: public ReadFilteredWords {
public:
    DigitsFilter(const char *fname) : ReadFilteredWords(fname) {};

    bool filter(string word);
};


#endif
