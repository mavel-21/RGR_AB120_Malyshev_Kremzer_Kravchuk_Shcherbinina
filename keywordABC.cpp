#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "keywordABC.h"

using namespace std;

void keywordABC(string line, string keyword, int mode, ofstream& outfile)
{
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector <char> newABC;
    int ind = 0;
    for (size_t i = 0; i < keyword.size(); i++)
    {
        newABC.push_back(toupper(keyword[i]));
    }
    for (char elem : abc)
    {
        if (find(newABC.begin(), newABC.end(), elem) != newABC.end())
            continue;
        else
        {
            newABC.push_back(elem);
        }
    }
    for (size_t i = 0; i < line.size(); i++)
    {
        if (isalpha(line[i]))
        {
            if (mode == 1)
            {
                ind = int(line[i]) - 65;
                if (isupper(line[i])) line[i] = newABC[ind];
                else line[i] = tolower(newABC[ind]);
            }
            else
            {
                auto indIt = find(newABC.begin(), newABC.end(), line[i]);
                ind = indIt - newABC.begin();
                if (isupper(line[i])) line[i] = abc[ind];
                else line[i] = tolower(abc[ind]);
            }
        }
    }
    for (char elem : line)
    {
        outfile << elem;
    }
    outfile << " " << endl;
}