#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include "tableCypher.cpp"

using namespace std;

vector<vector<char>> mtrxTransp(vector<vector<char>> &a);

void sortByKey(vector <vector<char>> &text, string key);

void tableCypherEncode(string line, string keyword, ofstream& outfile);

void tableCypherDecode(string line, string keyword, ofstream& outfile);
