#ifndef MAIN_CPP_POLYBIUSSQUARE_H
#define MAIN_CPP_POLYBIUSSQUARE_H

#include <string>
#include <vector>
#include "interface.h"

using namespace std;
void square();
int charToPolybius(char c, const vector <pair<char, pair<int, int>>>& vec);
void PolybiusSquare();
char PolybiusToChar(char first, char second, const vector<pair<char, pair<int, int>>>& vec);
void antiPolybiusSquare();

#endif //MAIN_CPP_POLYBIUSSQUARE_H
