#ifndef CE221ASS2_UPPERLOWERFILTER_H
#define CE221ASS2_UPPERLOWERFILTER_H

#include <string>
#include <fstream>
#include "../ReadFilteredWords.h"

using namespace std;

class UpperLowerFilter : public ReadFilteredWords {
public:

    UpperLowerFilter(const char *fname) : ReadFilteredWords(fname){}

    bool filter(string word);
};

#endif