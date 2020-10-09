#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Human.h"

using namespace std;

int main()
{
    system("chcp 1251>nul");
    srand(time(0));

    Worker w(25, "Андрей", "мужской", "сварщик");
    w.printInfo();
    w.getAverageIncome();
    cout << endl;
    Retiree r(67, "Петр Иванович","мужской","пенсионер");
    r.printInfo();
    r.getAverageIncome();
    cout << endl;
    Preschooler p(4, "Саша", "мужской", 4);
    p.printInfo();
    p.getSumPrice();
    cout << endl;
    Schoolchild s(12, "Катя", "женский", 2);
    s.printInfo();
    s.getSumPrice();
    cout << endl;
    system("pause>nul");
}
