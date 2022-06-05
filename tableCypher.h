#ifndef MAIN_CPP_TABLECYPHER_H
#define MAIN_CPP_TABLECYPHER_H

#include "interface.h"
#include "keygen.h"
#include "tableCypher.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> mtrxTransp(vector<vector<char>> &a);
void sortByKey(vector<vector<char>> &text, string key);
void tableCypher();
void antitableCypher();


#endif //MAIN_CPP_TABLECYPHER_H
