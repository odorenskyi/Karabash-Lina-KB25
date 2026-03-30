#include <iostream>
#include <cmath>
#include <cstdio>
#include "ModulesKarabash.h"
#include <Windows.h>
#include <iomanip>

using namespace std;

void test_faren_v_cels() {
    cout << "\n--- TEST: faren_v_cels ---\n";
    double inputs[10] = {32, 212, 68, 98.6, -4, 1000, -40, 50, 77, 100};
    double expected[10] = {0, 100, 20, 37, -20, 537.7778, -40, 10, 25, 37.7778};
    const double EPS = 1e-3;

    for (int i = 0; i < 10; i++) {
        double res = faren_v_cels(inputs[i]);
        if (abs(res - expected[i]) < EPS)
            printf("Case #%02d: PASSED\n", i + 1);
        else
            printf("Case #%02d: FAILED \n", i + 1);
    }
}

void test_processNumber() {
    cout << "\n--- TEST: processNumber ---\n";
    int inputs[10] = {0, 1, 16, 31, 48, 32768, 50000, 32, 17, 25};
    int expected[10] = {1, 0, 1, 5, 2, 15, 6, 5, 2, 3};

    for (int i = 0; i < 10; i++) {
        int res = processNumber(inputs[i]);
        if (res == expected[i])
            printf("Case #%02d: PASSED \n", i + 1);
        else
            printf("Case #%02d: FAILED \n", i + 1);
    }
}

void test_bonus_znuzhka() {
    cout << "\n--- TEST: bonus_znuzhka ---\n";
    double inputs[10] = {100, 199.99, 200, 350, 500, 1000, 2500, 5000.01, 50, 5000};
    // Очікувані бонуси для перевірки (логіка: бонус * 0.25)
    int expected_bonuses[10] = {1, 1, 5, 5, 10, 50, 150, 300, 0, 150};

    for (int i = 0; i < 10; i++) {
        cout << "Test Case #" << i + 1 << ": ";
        bonus_znuzhka(inputs[i]);
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    test_faren_v_cels();
    test_processNumber();
    test_bonus_znuzhka();
    return 0;
}
