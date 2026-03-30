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

void bonus_znuzhka (double summa)
{
    int bonus = 0;
    double result, znuzhka;
    if (summa>=100 && summa<200)
    {
        bonus=1;
    }
    else if (summa>=200 && summa<500)
    {
        bonus=5;
    }
    else if (summa>=500 && summa<1000)
    {
        bonus=10;
    }
    else if (summa>=1000 && summa<2500)
    {
        bonus=50;
    }
    else if (summa>=2500 && summa<=5000)
    {
        bonus=150;
    }
    else if (summa>5000)
    {
        bonus=300;
    }
    else if (summa<100)
    {
        bonus=0;
    }
    znuzhka=double(bonus*0.25);
    result = summa - znuzhka;
    cout<<"Кількість бонусів: "<<bonus<<endl;
    cout<<"Сума з урахуванням знижки: "<<result<<endl;
}

double faren_v_cels (double faren)
{
    double cels = double((5.0/9.0)*(faren-32));
    return cels;
}

int processNumber(int N)
{
    bool countOnes = (N & (1 << 4)) != 0;
    int flag =0;
    int count = 0;
    if (N == 0)
        {
        cout <<"Кількість двійкових нулів:"<<endl;
        return countOnes ? 0 : 1;
        }
    int temp = N;
    while (temp > 0)
        {
            int bit = temp % 2;
            if (countOnes)
            {
                count += (bit == 1) ? 1 : 0;
                flag=1;
            }
            else
            {
                count += (bit == 0) ? 1 : 0;
            }
            temp /= 2;
        }
        if (flag ==1)
            cout <<"Кількість двійкових одиниць:"<<endl;
        else
            cout <<"Кількість двійкових нулів:"<<endl;

    return count;
}
