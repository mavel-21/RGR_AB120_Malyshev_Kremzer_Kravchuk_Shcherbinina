#ifndef MAIN_CPP_INTERFACE_H
#define MAIN_CPP_INTERFACE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void inFile(const string& inStr);
bool isEmpty();
void cipherExec(int enc, int mode, string pinAdmin);
void outFile(const string& inStr);
void clearFile();
void getFile();
string getString(const string& mark, int pos_n);
string getKey(const string& mark, int pos_n);
bool checkPincode(const string& pinUser, const string& pinAdmin);

#endif //MAIN_CPP_INTERFACE_H
