#include <iostream>
#include <cmath>
#include <fstream>
#include <bitset>
#include <sstream>
#include <cstring>

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
    znuzhka=bonus*0.25;
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

int vowelsCountInFile(string outputFileName, string ukrWord)
{
    ofstream outputFile(outputFileName, ios::app);
    string vowels[10] = { "а", "е", "є", "и", "і", "ї", "о", "у", "ю", "я" };
    int vowelsCount = 0;
    size_t foundVowel;

    for (int i = 0; i < 10; i++) {
        foundVowel = ukrWord.find(vowels[i]);
        if (foundVowel != string::npos) {
            vowelsCount++;
        }
    }
    outputFile << "Кількість голосних літер з вхідного файлу: " << vowelsCount << endl << endl;
    outputFile.close();
    return vowelsCount;
}

bool findWordInPoem(string outputFileName, string ukrWord)
{
    ofstream outputFile(outputFileName, ios::app);
    string poemVI = { "до щастя не пускає лінощів орава.\n"
                      "у чім воно - ніхто не знає до пуття.\n"
                      "навчитись радісно робити кожну справу\n"
                      "найперше правило щасливого життя\n" };
    size_t foundWord;

    foundWord = poemVI.find(ukrWord);
    if (foundWord != string::npos) {
        outputFile << "Знайдено слово \"" << ukrWord << "\"" << endl << endl;
        outputFile.close();
        return true;
    }
    outputFile << "Cлово \"" << ukrWord << "\" - не знайдено" << endl << endl;
    outputFile.close();
    return false;
}

int consonantsCountInFile(string inputFileName, string ukrWord)
{
    ofstream inputTxtFile(inputFileName, ios::app);
    string vowels[10] = { "а", "е", "є", "и", "і", "ї", "о", "у", "ю", "я" };
    size_t foundConsonants;

    for (int i = 0; i < 10; i++) {
        foundConsonants = ukrWord.find(vowels[i]);
        if (foundConsonants != string::npos) {
            ukrWord.erase(foundConsonants, vowels[i].length());
        }
    }
    inputTxtFile << "Кількість приголосних літер з вхідного файлу: " << ukrWord.length() / 2 << endl << endl;
    inputTxtFile.close();
    return ukrWord.length() / 2;
}

bool timestampInFile(string inputFileName)
{
    ofstream inputFile(inputFileName, ios::app);
    time_t rawtime;
    time(&rawtime);
    inputFile << "Дата та час дозапису інформаціїї: " << ctime(&rawtime) << endl << endl;
    inputFile.close();
    return true;
}

double sCalculationResInFile(const string& outputFileName, float x, float y, float z) {

    double result = s_calculation(x, y, z);


    ofstream outputFile(outputFileName, ios::app);


    if (!outputFile) {
        cerr << "Ошибка открытия файла: " << outputFileName << endl;
        return -1.0;
    }


    outputFile << "Результат выполнения s_calculation: " << result << endl << endl;
    outputFile.close();

    return result;
}

bool decimalToBinary(string outputFileName, unsigned int number)
{
    if (number <= 0) {
        return false;
    }
    ofstream outputFile(outputFileName, ios::app);
    int binaryCels[32];
    int i;
    unsigned int convertedNum = number;

    for(i = 0; convertedNum > 0; i++) {
        binaryCels[i] = convertedNum % 2;
        convertedNum = convertedNum / 2;
    }
    outputFile << "Двійкове представлення числа " << number << " : ";
    for(i = i - 1; i >= 0; i--) {
        outputFile << binaryCels[i];
    }
    outputFile << endl << endl;
    outputFile.close();
    return true;
}

bool authorInfo(string outputFileName)
{
    ofstream outputFile(outputFileName, ios::out);
	outputFile << "====================================================================" << endl
               << " Виконавець:         Карабаш Ліна Олександрівна" << endl
               << " Рік розробки:       2026" << endl
               << " Місто/Країна:       Кропивницький/Україна" << endl
               << " ВНЗ:                Центральноукраїнський Національний Технічний Університет" << endl
               << "====================================================================" << endl << endl;
    outputFile.close();
    return true;
}

