#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include "ModulesKarabash.h"

using namespace std;

const char* pib (void)
{
    return "\n  арабаш Ћ≥на ќлександр≥вна \xA9";
}

int logica (signed char a, signed char b)
{
    if (abs(a - 22) <= (b + 5))
        return 1;
    else
        return 0;
}

void calculat (double x, double y, double z)
{
    printf("„исло х в дес€тков≥й систем≥ численн€: %f\n", x);
    printf("„исло y в дес€тков≥й систем≥ численн€: %f\n", y);
    printf("„исло z в дес€тков≥й систем≥ численн€: %f\n", z);
    printf("„исло х в ш≥стнадц€тков≥й систем≥ численн€: %a\n", x);
    printf("„исло y в ш≥стнадц€тков≥й систем≥ численн€: %a\n", y);
    printf("„исло z в ш≥стнадц€тков≥й систем≥ численн€: %a\n", z);

    double result = s_calculation(x, y, z);
    if (isnan(result))
        cout<<result<<endl;
    else
        cout <<"„исло S = "<<result<<endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double x, y, z;
    signed char a, b;
    cout << "\n¬вед≥ть число X: " << endl;
    cin>>x;
    cout << "¬вед≥ть число Y: " << endl;
    cin>>y;
    cout << "¬вед≥ть число Z: " << endl;
    cin>>z;
    cout << "¬вед≥ть символ a: " << endl;
    cin>>a;
    cout << "¬вед≥ть символ b: " << endl;
    cin>>b;
    cout<<pib()<<endl;
    cout<<"„исловий результат обчисленн€ лог≥чного виразу: "<<logica(a, b)<<endl;
    calculat(x, y, z);
    return 0;
}
