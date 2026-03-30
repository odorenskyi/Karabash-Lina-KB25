#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include "ModulesKarabash.h"

using namespace std;

const char* pib (void)
{
    return "\n Карабаш Ліна Олександрівна \xA9";
}

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout<<pib()<<endl;
    char choice;
    char exit_choice;
    do
    {
        cout << "\n========== ГОЛОВНЕ МЕНЮ ==========" << endl;
        cout << "j - Виконати s_calculation()" << endl;
        cout << "z - Розрахунок бонусів та знижки " << endl;
        cout << "x - Конвертація Фаренгейт -> Цельсій" << endl;
        cout << "c - Бітові операції " << endl;
        cout << "----------------------------------" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;
        switch (choice) {
            case 'j':{
                cout << "\n--- Виклик s_calculation ---" << endl;
                double x, y, z;
                cout << "\nВведіть число X: " << endl;
                cin>>x;
                cout << "Введіть число Y: " << endl;
                cin>>y;
                cout << "Введіть число Z: " << endl;
                cin>>z;
                cout <<"Результат роботи функції s_calculation: "<< s_calculation(x, y, z)<<endl;
                break;
            }

            case 'z': {
                double summa;
                int flag = 0;
                do {
                    cout << "\nВведіть суму покупки: ";
                    cin >> summa;
                    if (summa<0){
                        cout << "\nСума покупки не може бути менше нуля!!!\n";
                        flag=1;
                    }
                    else
                        flag =0;
                }
                while (flag == 1);
                bonus_znuzhka(summa);
                cout<<endl;
                break;
            }

            case 'x': {
                double faren;
                cout << "\nВведіть температуру у Фаренгейтах: ";
                cin >>faren;
                cout << "Результат у Цельсіях: " << faren_v_cels(faren)<< endl;
                break;
            }

            case 'c': {
                int n;
                cout << "\nВведіть натуральне число N (0-51950): ";
                cin >> n;
                cout << "Результат: " << processNumber(n) << endl;
                break;
            }

            default:{
                cout << "\a";
                cout << "!!! Помилка: невірний символ !!!" << endl;
                break;
            }
        }
        cout << "\n----------------------------------" << endl;
        cout << "Вийти з програми? (v, V, A - так / інше - повторити): ";
        cin >> exit_choice;
    }
    while (exit_choice != 'v' && exit_choice != 'V' && exit_choice != 'A');
    return 0;
}
