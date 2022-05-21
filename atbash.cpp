#include <iostream>
#include <string>
#include <fstream>
#include "atbash.h"

using namespace std;

void atbash(string line, int mode, ofstream& outfile)
{
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cab = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    int strSize = line.size(), ind = 0;
    for (int i = 0; i < strSize; i++)
    {
        if (isalpha(line[i]))
        {
            if (isupper(line[i]))
            {
                ind = int(line[i]) - 65;
                if (mode == 1) line[i] = cab[ind];
                else line[i] = abc[ind];
            }
            else
            {
                ind = int(line[i]) - 97;
                if (mode == 1) line[i] = tolower(cab[ind]);
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