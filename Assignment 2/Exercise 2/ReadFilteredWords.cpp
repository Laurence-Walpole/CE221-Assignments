#include "ReadFilteredWords.h"

using namespace std;

string ReadFilteredWords::getNextFilteredWord(){
    while (isNextWord()){
        string word = getNextWord();
        return (filter(word) ? word : " ");
    }
    return "";
}