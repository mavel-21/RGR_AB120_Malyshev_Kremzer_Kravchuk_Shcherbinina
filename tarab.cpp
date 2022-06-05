#include "tarab.h"
#include "interface.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void Tarab() {
    string word = getString("Phrase: ", 8);
    int k = word.size();
    string stOut = "";
    for (int i = 0; i < k; i++) {
        if (word[i] <= 'a' && word[i] >= 'z' || word[i] <= 'A' && word[i] >= 'Z') {
            continue;
        }
        if (word[i] >= 'a' && word[i] <= 'z')
            switch (word[i]) {
                case 'b': word[i] = 'n'; break;
                case 'c': word[i] = 'p'; break;
                case 'd': word[i] = 'q'; break;
                case 'f': word[i] = 'r'; break;
                case 'g': word[i] = 's'; break;
                case 'h': word[i] = 't'; break;
                case 'j': word[i] = 'v'; break;
                case 'k': word[i] = 'w'; break;
                case 'l': word[i] = 'x'; break;
                case 'm': word[i] = 'z'; break;

                case 'n': word[i] = 'b'; break;
                case 'p': word[i] = 'c'; break;
                case 'q': word[i] = 'd'; break;
                case 'r': word[i] = 'f'; break;
                case 's': word[i] = 'g'; break;
                case 't': word[i] = 'h'; break;
                case 'v': word[i] = 'j'; break;
                case 'w': word[i] = 'k'; break;
                case 'x': word[i] = 'l'; break;
                case 'z': word[i] = 'm'; break;
            }
        else
            switch (word[i]) {
                case 'B': word[i] = 'N'; break;
                case 'C': word[i] = 'P'; break;
                case 'D': word[i] = 'Q'; break;
                case 'F': word[i] = 'R'; break;
                case 'G': word[i] = 'S'; break;
                case 'H': word[i] = 'T'; break;
                case 'J': word[i] = 'V'; break;
                case 'K': word[i] = 'W'; break;
                case 'L': word[i] = 'X'; break;
                case 'M': word[i] = 'Z'; break;

                case 'N': word[i] = 'B'; break;
                case 'P': word[i] = 'C'; break;
                case 'Q': word[i] = 'D'; break;
                case 'R': word[i] = 'F'; break;
                case 'S': word[i] = 'G'; break;
                case 'T': word[i] = 'H'; break;
                case 'V': word[i] = 'J'; break;
                case 'W': word[i] = 'K'; break;
                case 'X': word[i] = 'L'; break;
                case 'Z': word[i] = 'M'; break;
            }
        stOut += word[i];
    }
    inFile("Phrase: " + stOut);
}

void antiTarab() {
    string word = getString("Phrase: ", 8);
    int k = word.size();
    string stOut = "";
    for (int i = 0; i < k; i++) {
        if (word[i] <= 'a' && word[i] >= 'z' || word[i] <= 'A' && word[i] >= 'Z') {
            continue;
        }
        if (word[i] >= 'a' && word[i] <= 'z')
            switch (word[i]) {
                case 'b': word[i] = 'n'; break;
                case 'c': word[i] = 'p'; break;
                case 'd': word[i] = 'q'; break;
                case 'f': word[i] = 'r'; break;
                case 'g': word[i] = 's'; break;
                case 'h': word[i] = 't'; break;
                case 'j': word[i] = 'v'; break;
                case 'k': word[i] = 'w'; break;
                case 'l': word[i] = 'x'; break;
                case 'm': word[i] = 'z'; break;

                case 'n': word[i] = 'b'; break;
                case 'p': word[i] = 'c'; break;
                case 'q': word[i] = 'd'; break;
                case 'r': word[i] = 'f'; break;
                case 's': word[i] = 'g'; break;
                case 't': word[i] = 'h'; break;
                case 'v': word[i] = 'j'; break;
                case 'w': word[i] = 'k'; break;
                case 'x': word[i] = 'l'; break;
                case 'z': word[i] = 'm'; break;
            }
        else
            switch (word[i]) {
                case 'B': word[i] = 'N'; break;
                case 'C': word[i] = 'P'; break;
                case 'D': word[i] = 'Q'; break;
                case 'F': word[i] = 'R'; break;
                case 'G': word[i] = 'S'; break;
                case 'H': word[i] = 'T'; break;
                case 'J': word[i] = 'V'; break;
                case 'K': word[i] = 'W'; break;
                case 'L': word[i] = 'X'; break;
                case 'M': word[i] = 'Z'; break;

                case 'N': word[i] = 'B'; break;
                case 'P': word[i] = 'C'; break;
                case 'Q': word[i] = 'D'; break;
                case 'R': word[i] = 'F'; break;
                case 'S': word[i] = 'G'; break;
                case 'T': word[i] = 'H'; break;
                case 'V': word[i] = 'J'; break;
                case 'W': word[i] = 'K'; break;
                case 'X': word[i] = 'L'; break;
                case 'Z': word[i] = 'M'; break;
            }
        stOut += word[i];
    }
    inFile("Phrase: " + stOut);
}