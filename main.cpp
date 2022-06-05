// Малышев Павел

// Группа: АБ-120

// Шифровки:
//     1. Шифр Гронсфельда (5.7)
//     2. Шифровка с помощью квадрата Полибия (5.8)
//     3. Простая табличная перестановка (5.16)

#include <iostream>
#include <string>
#include "interface.h"
#include "gronsfeld.h"
#include "polybiusSquare.h"
#include "simpleTablePermutation.h"
#include "atbash.h"
#include "keywordABC.h"
#include "tableCypher.h"
#include "Caesar.h"
#include "doubleTable.h"
#include "tarab.h"

using namespace std;

int main() {
    string dialogStr; // диалоговая строка
    string pinAdmin = "1111"; // дефолтный пинкод
    cout << endl << "______________________________Hello______________________________" << endl <<
         "__________To display a list of all commands write: help__________" << endl <<
         "____Set a password, enter a passphrase, and choose encryption____" << endl << endl;

    while (true) {
        cout << "Enter a command: ";
        getline(cin, dialogStr); // ввод команды
        if (dialogStr == "input") { // команда ввода фразы в файл
            string str; // строка
            cout << "Enter a string: ";
            getline(cin, str); // ввод строки (фразы)
            inFile("Phrase: " + str); //запись этой строки (фразы) в файл
            cout << "    [THE FILE HAS BEEN UPDATED]" << endl << endl;
        } else if (dialogStr == "clear") { // команда очистки файла
            clearFile(); // обращение к функции очистки файла
            cout << "    [THE FILE HAS BEEN CLEARED]" << endl << endl;
        } else if (dialogStr == "get") { // команда получения содержимого файла
            cout << "    [FILE CONTENTS]" << endl;
            getFile(); // обращение к функции получения содержимого файла
            cout << endl;
        } else if (dialogStr == "encrypt") {
            string encryption_str;
            int encryption;
            cout
                    << "\t1. Gronsfeld encryption\n\t2. Encryption using the square of Polybius\n\t3. Simple table permutation\n\tAny other character: go back\nChoose encryption (1-3): ";
            getline(cin, encryption_str);
            if (encryption_str == "1" or encryption_str == "2" or encryption_str == "3" or encryption_str == "4" or
                encryption_str == "5" or encryption_str == "6" or encryption_str == "7" or encryption_str == "8" or
                encryption_str == "9")
                encryption = encryption_str[0] - '0';
            else {
                cout << "   [GO BACK]" << endl << endl;
                continue;
            }
            string pinUser; // пинкод, вводимый пользователем
            switch (encryption) {
                case 1: {// шифровка Гронсфельда
                    cout << endl << "    [Gronsfeld encryption]" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        Gronsfeld();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    pinUser = "";
                    break;
                }
                case 2: {
                    cout << endl << "    [Polybius square]" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        square();
                        PolybiusSquare();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    pinUser = "";
                    break;
                }
                case 3: {
                    cout << endl << "    [Simple table permutation]" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        STP();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    pinUser = "";
                    break;
                }
                case 4: {
                    cout << endl << "    [Atbash cipher]" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        atbash();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    break;
                }
                case 5: {
                    cout << endl << "    [Keyword cipher]" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        keywordABC();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    break;
                }
                case 6: {
                    cout << endl << "    [Table cipher with a keyword]" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        tableCypher();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    break;
                }
                case 7: {
                    cout << endl << "    [Caesar]" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        Caesar();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    break;
                }
                case 8: {
                    cout << endl << "    [Double table permutation]" << endl << endl;
                    if (pinAdmin == "0000") { // проверка того, задан ли пинкод
                        cout << "    [Pincode not set!]" << endl;
                        break;
                    }
                    string pinUser; // пинкод
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        DoubleTable();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    break;
                }
                case 9: {
                    cout << endl << "    ['Tarabarskaya gramota']" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        Tarab();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    break;
                }
                default:
                    break;
            }
        } else if (dialogStr == "decrypt") {
            string decryption_str;
            int decryption;
            cout
                    << "\t1. Gronsfeld decryption\n\t2. Decryption using the square of Polybius\n\t3. Simple table permutation\n\tAny other character: go back\nChoose decryption (1-3): ";
            getline(cin, decryption_str);
            if (decryption_str == "1" or decryption_str == "2" or decryption_str == "3" or decryption_str == "4" or
                decryption_str == "5" or decryption_str == "6" or decryption_str == "7" or decryption_str == "8" or
                decryption_str == "9")
                decryption =
                        decryption_str[0] -
                        '0';
            else {
                cout << "   [GO BACK]" << endl << endl;
                continue;
            }
            string pinUser; // пинкод, вводимый пользователем
            switch (decryption) {
                case 1: {// расшифровка Гронсфельда
                    cout << endl << "    [Gronsfeld decryption]" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        antiGronsfeld();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    pinUser = "";
                    break;
                }
                case 2: {
                    cout << endl << "    [Decryption by Polybius square]" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        antiPolybiusSquare();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    pinUser = "";
                    break;
                }
                case 3: {
                    cout << endl << "    [Simple table permutation]" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        antiSTP();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    pinUser = "";
                    break;
                }
                case 4: {
                    cout << endl << "    [Atbash decryption]" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        antiatbash();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    pinUser = "";
                    break;
                }
                case 5: {
                    cout << endl << "    [Keyword decryption]" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        antikeywordABC();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    break;
                }
                case 6: {
                    cout << endl << "    [Table cipher with a keyword]" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        antitableCypher();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    break;
                }
                case 7: {
                    cout << endl << "    [Caesar]" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        antiCaesar();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    break;
                }
                case 8: {
                    cout << endl << "    [Double table permutation]" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        antiDoubleTable();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    break;
                }
                case 9: {
                    cout << endl << "    ['Tarabarskaya gramota']" << endl << endl;
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        antiTarab();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    break;
                }
                default:
                    break;
            }
        } else if (dialogStr == "help") { // команда вызова списка команд
            cout << "    [COMMANDS]" << endl;
            cout << "input -- Writing a line to a file;" << endl;
            cout << "get -- Displaying the contents of a file;" << endl;
            cout << "clear -- Cleaning up the contents of a file;" << endl;
            cout << "pin -- Pincode setting;" << endl;
            cout << "encrypt -- Choice of encryption" << endl;
            cout << "decrypt -- Choice of decryption" << endl;
            cout << "stop -- Stop program;" << endl << endl;

        } else if (dialogStr == "stop") { // остановка программы
            cout << "    [The program has been stopped]" << endl;
            break;
        } else { // команды не существует
            cout << endl << "[ERROR_217][THIS COMMAND DOES NOT EXIST][ERROR_217]" << endl << endl;
        }
    }
    return 0;
}