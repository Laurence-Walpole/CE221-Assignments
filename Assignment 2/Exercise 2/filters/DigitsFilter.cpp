#include "DigitsFilter.h"
#include <cctype>
#include <cstdlib>
#include <iostream>

using namespace std;

bool DigitsFilter::filter(string word){
    bool hasOneOrMoreDigits = false;
    char prevC = ' ';
    for (char i : word) {
        if (!hasOneOrMoreDigits){
            hasOneOrMoreDigits = (isdigit(i) && isdigit(prevC));
        }
        prevC = i;
    }
    return hasOneOrMoreDigits;
}