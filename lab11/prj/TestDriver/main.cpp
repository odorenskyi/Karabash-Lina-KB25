#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "struct_type_project_1.h"
#include "ModulesKarabash.h"

using namespace std;

// Функція для автоматичного створення тестового файлу
void createTestFile(string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        // Формат: Прізвище Ім'я По_батькові Марка Рік Дата Номер Примітки
        file << "Ivanov Petro Mykolaiovych Toyota 2020 12.05.2021 AA1111AA Перша_реєстрація" << endl;
        file << "Petrov Ivan Ivanovych BMW 2018 01.09.2019 BB2222BB Без_приміток" << endl;
        file << "Sydorov Oleg Petrovych Ford 2015 10.10.2015 CC3333CC Потребує_ТО" << endl;
        file.close();
        cout << "[TEST] Тестовий файл '" << filename << "' створено." << endl;
    }
}

// Функція для звільнення динамічної пам'яті (тестування завершення)
void deleteList(Reestr* head) {
    while (head != nullptr) {
        Reestr* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "[TEST] Динамічну пам'ять очищено." << endl;
}

int main() {
    // Налаштування для виведення символів (якщо потрібно)
    setlocale(LC_ALL, "Ukrainian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string testFileName = "test_database.txt";

    cout << "=== МОДУЛЬНЕ ТЕСТУВАННЯ: ModulesKarabash ===\n" << endl;

    // КРОК 1: Підготовка даних
    createTestFile(testFileName);

    // КРОК 2: Тестування функції loadFromTxtFile
    cout << "\n--- Тест 1: Завантаження списку ---" << endl;
    Reestr* head = loadFromTxtFile(testFileName);

    if (head != nullptr) {
        cout << "[PASS] Функція loadFromTxtFile повернула вказівник." << endl;
    } else {
        cout << "[FAIL] Функція loadFromTxtFile повернула nullptr." << endl;
        return 1; // Перериваємо тест
    }

    // КРОК 3: Тестування структури зв'язків
    cout << "\n--- Тест 2: Перевірка зв'язності списку ---" << endl;
    int count = 0;
    Reestr* curr = head;
    while (curr != nullptr) {
        count++;
        cout << "Знайдено запис: " << curr->l_name << " (" << curr->marka << ")" << endl;
        curr = curr->next;
    }
    cout << "Всього знайдено вузлів: " << count << " (Очікувалось: 3)" << endl;

    // КРОК 4: Тестування функції outputRegistry
    // Оскільки там є інтерактивне меню, тестувальник має обрати пункт 1 або 2
    cout << "\n--- Тест 3: Виведення/Запис (outputRegistry) ---" << endl;
    cout << "[INFO] Будь ласка, оберіть дію в меню для перевірки логіки:" << endl;
    outputRegistry(head);

    // КРОК 5: Завершення тесту та очищення пам'яті
    cout << "\n--- Тест 4: Очищення пам'яті ---" << endl;
    deleteList(head);

    cout << "\n=== ТЕСТУВАННЯ ЗАВЕРШЕНО ===" << endl;

    return 0;
}
