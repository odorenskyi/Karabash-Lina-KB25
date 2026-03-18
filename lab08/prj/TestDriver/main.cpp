#include <iostream>
#include <cmath>
#include <cstdio>
#include "ModulesKarabash.h"
#include <Windows.h>

using namespace std;


void test (void)
{
    double x [10]={1, 1.2, 24.5, -24.5, 2, 1, -1, 3, 0.5, -2};
    double y [10] = {2, 2, 13.7, 13.7, 5, 2, 4, 3, 1, 1.5};
    double z [10] = {3, 3, 11.8, 11.8, 3, 1, 2, 6, 0.2, 0};
    double expected [10] = {2.5943, 2.81305, 47.59912, NAN, 2.5329, 2.3872, 2.1973, 2.96104, 1.7665, NAN };
    const double EPS = 1e-4;
    int i;
    for (i =0; i<10; i++)
    {
        double result = s_calculation(x[i], y[i], z[i]);
        if (isnan(expected[i]))
        {
            if (isnan(result))
                printf("\nTest case #%02d PASSED\n", i + 1);
            else
                printf("\nTest case #%02d FAILED \n", i + 1);
        }
        else
        {
            if (fabs(result - expected[i]) < EPS)
                printf("Test case #%02d PASSED\n", i + 1);
            else
                printf("Test case #%02d FAILED\n", i + 1);
        }
    }
}

int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    test();
    return 0;
}
