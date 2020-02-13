#include "ReadWords.h"
#include <cctype>
#include <cstdlib>
#include <iostream>

#include<bits/stdc++.h>
using namespace std;

/**
 * Goes through a word and removes all punctuation then puts it to lower.
 * @param word
 * @return string
 */
string removePunct(string word) {
    int wordLen = word.size();
    for (int i = 0; i < wordLen; i++){
        if (ispunct(word[i])){
            if (word[i] != ' ') {
                word.erase(i--, 1);
            }
        }
    }
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

ReadWords::ReadWords(const char *fname) {
    wordfile.open(fname);//open file
    if (!wordfile) {
        cout << "Failed to open " << fname << endl;
        exit(1);
    }
    wordfile >> nextword;
    eoffound = false;
}

string ReadWords::getNextWord() {
    string word = nextword;
    wordfile >> nextword;

    if (wordfile.eof())
        eoffound = true;

    word = removePunct(word);
    return word;
}

bool ReadWords::isNextWord() {
    return !eoffound;
}

void ReadWords::close() {
    wordfile.close();
}
