#include "ReadFilteredWords.h"
#include "ReadWords.h"
#include "filters/LetterAndPunctFilter.h"
#include "filters/UpperLowerFilter.h"
#include "filters/DigitsFilter.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool sortingDirection(pair<int, string> i, pair<int, string> j) { return i.first > j.first; }

vector<pair<int, string>> sortMap(map<string, int> &entries) {
    vector<pair<int, string>> sortedEntries;
    for (pair<string, int> pair: entries){
        sortedEntries.emplace_back(pair.second, pair.first);
    }
    sort(sortedEntries.begin(), sortedEntries.end(), sortingDirection);
    return sortedEntries;
}

void translateMap(map<string, int> entries){
    int amount = 9;
    for(pair<int, string> entry : sortMap(entries)){
        if (!entry.second.empty()){
            cout << entry.second << ": occurred " << entry.first << " times" << endl;
            if (amount-- == 0) break;
        }
    }
}

int main(){
    cout << "Please enter your file name: ";
    string file;
    getline(cin, file);
    cout << endl;
    UpperLowerFilter upperLowerFilter = UpperLowerFilter(file.c_str());
    DigitsFilter digitsFilter = DigitsFilter(file.c_str());
    LetterAndPunctFilter letterAndPunctFilter = LetterAndPunctFilter(file.c_str());

    map<string, int> upperLowerWordsList;
    map<string, int> digitsWordsList;
    map<string, int> letterPunctWordsList;

    string word = " ";
    while (!word.empty()) {
        word = upperLowerFilter.getNextFilteredWord();
        if (word != " ") {
            if (upperLowerWordsList.count(word) > 0) {
                upperLowerWordsList.at(word)++;
            } else {
                upperLowerWordsList.insert(pair<string, int>(word, 1));
            }
        }

        word = digitsFilter.getNextFilteredWord();
        if (word != " ") {
            if (digitsWordsList.count(word) > 0) {
                digitsWordsList.at(word)++;
            } else {
                digitsWordsList.insert(pair<string, int>(word, 1));
            }
        }

        word = letterAndPunctFilter.getNextFilteredWord();
        if (word != " ") {
            if (letterPunctWordsList.count(word) > 0){
                letterPunctWordsList.at(word)++;
            }else{
                letterPunctWordsList.insert(pair<string, int>(word, 1));
            }
        }
    }
    upperLowerFilter.close();

    //Upper and Lower Words
    cout << "Words with both Upper and Lower characters:- " << endl;
    cout << "Total occurrences: " << upperLowerWordsList.size() << endl;
    translateMap(upperLowerWordsList);

    cout << endl << "Words with at least two digits:- " << endl;
    cout << "Total occurrences: " << digitsWordsList.size() << endl;
    translateMap(digitsWordsList);

    cout << endl << "Words with at least one punctuation and one letter:- " << endl;
    cout << "Total occurrences: " << letterPunctWordsList.size() << endl;
    translateMap(letterPunctWordsList);
}