#include <iostream>
#include <cmath>

using namespace std;

double s_calculation (double x, double y, double z)
{
    double abs_diff = fabs(y-z);
    if (abs_diff ==0)
        {
            cout <<"\nПомилка: знаменник першого дробу дорівнює нулю";
            return NAN;
        }
    double frac_1=x/abs_diff;
    double cubed = pow(frac_1,3);
    //
    double sum_denom_2 = z + x;
    if (sum_denom_2==0)
        {
            cout << "\nПомилка: сума (z + x) дорівнює нулю";
            return NAN;
        }
    double denome_2 = sqrt(fabs(sum_denom_2 * y ));
    if(denome_2==0)
        {
            cout << "\nПомилка: знаменник другого дробу дорівнює нулю";
            return NAN;
        }

    double diff_2 = pow(x,2)+z;
    double frac_2 = diff_2/denome_2;
    //
    const double Pi = 3.14159265358979323846;
    double denome_3 = 2*y + Pi;
    if (denome_3==0)
        {
            cout << "\nПомилка: знаменник третього дробу дорівнює нулю";
            return NAN;
        }

    double diff_3=cos(x*pow(z,2));
    double frac_3= diff_3/denome_3;
    //
    double sum_expr = cubed+frac_2-frac_3;
    if(sum_expr<0)
        {
            cout << "\nПомилка: вираз під коренем від'ємний";
            return NAN;
        }
    double sqrt_expr = sqrt(sum_expr);
    double S = 1 + sqrt_expr;
    return S;
}
