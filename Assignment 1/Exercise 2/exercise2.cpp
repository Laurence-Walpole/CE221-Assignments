#include "ReadWords.h"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

int main() {
    //Open first file
    cout << "Please enter your large text file name: ";
    string file;
    getline(cin, file);
    cout << endl;
    ReadWords readWords = ReadWords(file.c_str());

    //Open second file
    cout << "Please enter your search text file name: ";
    string file2;
    getline(cin, file2);
    cout << endl;
    ReadWords searchWords = ReadWords(file2.c_str());

    //Define variables for use in the function
    map<string, int> wordList;
    map<string, int> searchList;
    int max = 0;
    int i = 0;

    //Go through main file and find the words
    while (readWords.isNextWord()) {
        string word = readWords.getNextWord();
        if (wordList.count(word) > 0) {
            wordList.at(word)++;
        } else {
            wordList.insert(pair<string, int>(word, 1));
        }
    }

    //Close main file
    readWords.close();
    cout << "Done read words" << endl;

    //Go through second file and find the words
    while (searchWords.isNextWord()){
        string word = searchWords.getNextWord();
        searchList.insert(pair<string, int>(word, 0));
    }

    //Close second file
    searchWords.close();
    cout << "Done search words" << endl;

    //Update values in searchList and set the max
    for (auto& wL : wordList) {
        for (auto& sL : searchList){
            if (wL.first == sL.first) {
                if (max < wL.second){
                    max = wL.second;
                }
                searchList.at(sL.first) = wL.second;
            }
        }
    }

    //Do file saving
    string saveFileName;
    cout << "What do you want your save file to be called? ";
    cin >> saveFileName;
    cout << endl;

    ofstream saveFile;
    saveFile.open(saveFileName);
    string amountOfStars = "Each star represents up to " + to_string(max / 10) + " words";
    cout << amountOfStars << endl;
    saveFile << amountOfStars << endl;

    //Display the output to the user
    for (auto& sL : searchList){
        if (sL.second != 0) {
            string line = sL.first + " ";
            for (int x = 0; x < sL.second; x += (max / 10)) {
                line += "*";
            }
            line += " " + to_string(sL.second);
            cout << line << endl;
            saveFile << line << endl;
        }
        else{
            cout << sL.first << " 0" << endl;
            saveFile << sL.first << " 0" << endl;
        }
    }
    saveFile.close();
}