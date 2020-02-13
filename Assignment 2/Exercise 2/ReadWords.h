/**
 * ReadWords class, the base class for CE221 Assignment 2 (Exercise 2)
 * original version written by Dave Lyons
 * modified by sands
 */

#ifndef _READWORDS_H
#define _READWORDS_H

using namespace std;
#include <string>
#include <iostream>
#include <fstream>

class ReadWords
{   public:

        /**
         * Constructor. Opens the file with the given filename.
         * Program exits with an error message if the file does not exist.
         * @param filename - a C string naming the file to read.
         */
        ReadWords(const char *fname);

        /**
         * Closes the file.
         */
        void close();

        /**
         * Returns a string, being the next word in the file.
         * @return - string - next word.
         */
        string getNextWord();

    protected:
        /**
         * Returns true if there is a further word in the file, 
         * returns false otherwise if we have reached the
         * end of file.
         * @return - bool - !eof
         */
        bool isNextWord();

    private:
        ifstream wordfile;
        bool eoffound;
        string nextword;		

        string fix(string word);

 };

 #endif
