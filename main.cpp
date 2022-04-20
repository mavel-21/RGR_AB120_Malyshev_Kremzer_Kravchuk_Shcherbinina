//Список 4 подгруппы:
//A) Кравчук Б.Д.
//B) Кремзер А.Д.
//C) Малышев П.А.
//D) Щербинина Д.В.

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void inFile(string inStr);
void clearFile();
void getFile();

int main() {
    string dialogStr;
    while (true) {
        cout << "Enter a command: ";
        cin >> dialogStr;
        if (dialogStr == "inFile") {
            string str;
            cout << "Enter a string: ";
            cin >> str;
            inFile(str);
            cout << "    [THE FILE HAS BEEN UPDATED]" << endl << endl;
        }
        else if (dialogStr == "clearFile") {
            clearFile();
            cout << "    [THE FILE HAS BEEN CLEARED]" << endl << endl;
        }
        else if (dialogStr == "getFile") {
            cout << "    [FILE CONTENTS]" << endl << endl;
            getFile();
        }
        else if (dialogStr == "help") {
            cout << "    [COMMANDS]" << endl;
            cout << "inFile -- Writing a line to a file;" << endl;
            cout << "getFile -- Displaying the contents of a file;" << endl;
            cout << "clearFile -- Cleaning up the contents of a file;" << endl;
            cout << "stop -- Stop program;" << endl << endl;
        }
        else if (dialogStr == "stop") {
            cout << "    [The program has been stopped]" << endl;
            break;
        }
    }
    return 0;
}

void inFile(string inStr) {
    ofstream file;
    file.open("/home/pavel/Документы/Уник/Информатика/progRgr/encryptions.txt", ofstream::app);
    file << inStr << endl;
    file.close();
}

void clearFile() {
    ofstream file;
    file.open("/home/pavel/Документы/Уник/Информатика/progRgr/encryptions.txt");
    file.close();
}

void getFile() {
    ifstream file;
    string str;
    file.open("/home/pavel/Документы/Уник/Информатика/progRgr/encryptions.txt");
    while (getline (file,str))
    {
        cout<< str << endl;
    }
    file.close();
}