#include "LetterAndPunctFilter.h"
#include <cctype>
#include <cstdlib>
#include <iostream>

using namespace std;

bool LetterAndPunctFilter::filter(string word){
    bool letter = false, punct = false;
    for (char i : word) {
        if (!letter) letter = (islower(i) || isupper(i));
        if (!punct) punct = ispunct(i);
    }
    return (letter && punct);
}