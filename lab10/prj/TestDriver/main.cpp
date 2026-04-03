#include <iostream>
#include <fstream>
#include <string>
#include "ModulesKarabash.h"

using namespace std;

int main() {
    // Налаштування кодування для коректного відображення кирилиці (Windows)
    system("chcp 1251 > nul");

    string inputFileName = "Input.txt";
    string outputFileName = "Output.txt";

    // --- МАСИВИ ДАНИХ ДЛЯ ТЕСТУВАННЯ ---

    // 5 слів для Завдань 10.1 та 10.2
    string testWords[5] = {"Привіт", "Щастя", "Сонце", "правило", "небо"};

    // 5 наборів даних для Завдання 10.3
    double x_vals[5] = {1.0, 1.2, 24.5, 2.0, 1.0};
    double y_vals[5] = {2.0, 2.0, 13.7, 5.0, 2.0};
    double z_vals[5] = {3.0, 3.0, 11.8, 3.0, 1.0};
    unsigned int b_vals[5] = {10, 8, 7, 5, 9};

    cout << "=== ЗАПУСК КОМПЛЕКСНОГО ТЕСТУВАННЯ (БЕЗ ВЕКТОРІВ) ===" << endl;

    // 1. Записуємо авторську інформацію (очищує Output.txt перед початком)
    authorInfo(outputFileName);

    // 2. ЦИКЛ ДЛЯ ЗАВДАНЬ 10.1 ТА 10.2 (Обробка слів)
    cout << "\n--- Етап 1: Робота зі словами ---" << endl;
    for (int i = 0; i < 5; i++) {
        // Оновлюємо вхідний файл поточним словом з масиву
        ofstream inFile(inputFileName);
        if (inFile.is_open()) {
            inFile << testWords[i];
            inFile.close();
        }

        cout << "Оброблено слово #" << i + 1 << ": " << testWords[i] << endl;

        // Викликаємо ваші функції (вони мають працювати в режимі ios::app)
        vowelsCountInFile(outputFileName, testWords[i]);
        findWordInPoem(outputFileName, testWords[i]);
        consonantsCountInFile(outputFileName, testWords[i]);
        timestampInFile(outputFileName);
    }

    // 3. ЦИКЛ ДЛЯ ЗАВДАННЯ 10.3 (Математичні розрахунки)
    cout << "\n--- Етап 2: Математичні розрахунки та двійковий код ---" << endl;
    for (int j = 0; j < 5; j++) {
        cout << "Набір #" << j + 1 << ": x=" << x_vals[j]
             << ", y=" << y_vals[j] << ", z=" << z_vals[j]
             << ", b=" << b_vals[j] << endl;

        // Розрахунок s_calculation та запис результату
        sCalculationResInFile(outputFileName, (float)x_vals[j], (float)y_vals[j], (float)z_vals[j]);

        // Переведення числа b у двійкову систему
        decimalToBinary(outputFileName, b_vals[j]);
    }

    cout << "\n======================================" << endl;
    cout << "Тестування завершено! Результати збережено в: " << outputFileName << endl;

    return 0;
}
