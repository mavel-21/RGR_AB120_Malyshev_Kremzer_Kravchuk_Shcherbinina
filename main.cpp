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
using namespace std;

int main() {

    int n;
    cin >> n;
    switch (n) {
    case 1:
        Caesar();
        UnCaesar();
        break;
    case 2:
        DoubleTable();
        UnDoubleTable();
        break;
    case 3:
        Tarab();
        UnTarab();
        break;

    }
	return 0;
}






