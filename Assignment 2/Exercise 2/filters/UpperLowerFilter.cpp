#include "UpperLowerFilter.h"

using namespace std;

bool UpperLowerFilter::filter(string word){
    bool lower = false, upper = false;
    for (char i : word) {
        if (!upper) upper = isupper(i);
        if (!lower) lower = islower(i);
    }
    return (lower && upper);
}