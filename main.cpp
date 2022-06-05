#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string> 
#include "Header.h"
//Щербинина Д.В
// Группа: АБ - 120
// Шифровки:
// Шифр Цезаря (5.1)
// Двойная табличная перестановка(5.18)
// «Тарабарская грамота»(5.20)

//	шифровки используют латинский алфавит!!!!!

int main() {
    string dialogStr; // диалоговая строка
    string pinAdmin = "0000"; // дефолтный пинкод
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
        }
        else if (dialogStr == "pin") { // команда ввода пинкода
            cout << "Enter pinAdmin: ";
            getline(cin, pinAdmin); // ввод пинкода
            cout << "    [PINCODE SET]" << endl << endl;
        }
        else if (dialogStr == "clear") { // команда очистки файла
            clearFile(); // обращение к функции очистки файла
            cout << "    [THE FILE HAS BEEN CLEARED]" << endl << endl;
        }
        else if (dialogStr == "get") { // команда получения содержимого файла
            cout << "    [FILE CONTENTS]" << endl;
            getFile(); // обращение к функции получения содержимого файла
            cout << endl;
        }
        else if (dialogStr == "cipher") {
            string cipher_str;
            int cipher;
            cout
                << "\t1. Gronsfeld cipher\n\t2. Encryption using the square of Polybius\n\t3. Simple table permutation\n\t4. Caesar cirher\n\t5. Double Table permutation\n\t6. Tarabarskaya Gramota\n\tAny other character: go back\nChoose encryption (1-6): ";
            getline(cin, cipher_str);
            if (cipher_str == "1" || cipher_str == "2" || cipher_str == "3" || cipher_str == "4" || cipher_str == "5" || cipher_str == "6") cipher = cipher_str[0] - '0';
            else {
                cout << "   [GO BACK]" << endl << endl;
                continue;
            }
            switch (cipher) {
               /*case 1: // шифровка Гронсфельда
                {
                    cout << endl << "    [Gronsfeld cipher]" << endl << endl;
                    if (pinAdmin == "0000") { // проверка того, задан ли пинкод
                        cout << "    [Pincode not set!]" << endl;
                        break;
                    }
                    string pinUser; // пинкод
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        Gronsfeld();
                    }
                    else cout << "    [Pincode is not correct!]" << endl;
                    break;
                }
                case 2:
                    break;
                case 3:
                    break;*/
            case 4:
            {
                cout << endl << "    [Caesar cirher]" << endl << endl;
                if (pinAdmin == "0000") { // проверка того, задан ли пинкод
                    cout << "    [Pincode not set!]" << endl;
                    break;
                }
                string pinUser; // пинкод
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    Caesar();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }

            case 5:
            {
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
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }

            case 6:
            {
                cout << endl << "    [Tarabarskaya gramota]" << endl << endl;
                if (pinAdmin == "0000") { // проверка того, задан ли пинкод
                    cout << "    [Pincode not set!]" << endl;
                    break;
                }
                string pinUser; // пинкод
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    Tarab();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }

            default:
                break;
            }
        }
        else if (dialogStr == "decrypt") {
            //if (checkString("Gronsfeld: ")) antiGronsfeld();
            if (checkString("Caesar: ")) {
                UnCaesar(); break;
            }
            if (checkString("DoubleTable ")) {
                UnDoubleTable();
                break;
            }
            if (checkString("Tarabarskaya: ")) {
                UnTarab();
                break;
            }
        }
        else if (dialogStr == "help") { // команда вызова списка команд
            cout << "    [COMMANDS]" << endl;
            cout << "input -- Writing a line to a file;" << endl;
            cout << "get -- Displaying the contents of a file;" << endl;
            cout << "clear -- Cleaning up the contents of a file;" << endl;
            cout << "pin -- Pincode setting;" << endl;
            cout << "cipher -- Choice of encryption" << endl;
            cout << "stop -- Stop program;" << endl << endl;

        }
        else if (dialogStr == "stop") { // остановка программы
            cout << "    [The program has been stopped]" << endl;
            break;
        }
        else { // команды не существует
            cout << endl << "[ERROR_217][THIS COMMAND DOES NOT EXIST][ERROR_217]" << endl << endl;
        }
    }
    return 0;
}








