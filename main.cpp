/*#include <iostream>
#include <string>
#include <vector>

using namespace std;
//Щербинина Д.В
// Группа: АБ - 120
// Шифровки:
// Шифр Цезаря (5.1)
// Двойная табличная перестановка(5.18)
// «Матричная шифровка»(5.4)

int main()
//шифр Цезаря
{
    string s;
    int k;
    cin >> s;
    cin >> k;

    for (auto& c : s)
    {
        if (c >= 'a' && c <= 'z')
            c = ((c - 'a' + k) % 26) + 'a';
        else if (c >= 'A' && c <= 'Z')
            c = ((c - 'A' + k) % 26) + 'A';
    }

    cout << s << endl;
    return 0;
}*/






