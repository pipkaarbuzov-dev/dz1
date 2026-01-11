#include <iostream>
#include <string>
#include <ctime>
#include "double_list.h"
#include "processor.h"

using namespace std;

// Функция для печати списка (для char)
void printCharList(DoubleList<char>& lst) {
    for (auto it = lst.begin(); it != lst.end(); ++it) cout << *it;
    cout << endl;
}

// Функция для печати списка (для int)
void printIntList(DoubleList<int>& lst) {
    for (auto it = lst.begin(); it != lst.end(); ++it) cout << *it << " ";
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0)); // Для генерации случайных чисел

    int mode;
    do {
        cout << "\n--- МЕНЮ ---\n";
        cout << "1. Лаба 3: Обработка строки (Ваше задание)\n";
        cout << "2. Лаба 4: Сортировки (на числах)\n";
        cout << "0. Выход\n";
        cout << "> ";
        cin >> mode;

        if (mode == 1) {
            // --- ЛАБА 3 ---
            DoubleList<char> list;
            string input;
            
            // Очистка буфера перед вводом строки
            string dummy; getline(cin, dummy);

            cout << "Введите строку: ";
            getline(cin, input);

            for (char c : input) list.push_back(c);

            cout << "До обработки: ";
            printCharList(list);

            process_task(list);

            cout << "После обработки: ";
            printCharList(list);

        } else if (mode == 2) {
            // --- ЛАБА 4 ---
            DoubleList<int> numbers;
            int n;
            cout << "Введите размер списка чисел: ";
            cin >> n;

            // Заполняем случайными числами
            for (int i = 0; i < n; i++) {
                numbers.push_back(rand() % 100);
            }

            cout << "Исходный список: ";
            printIntList(numbers);

            cout << "Выберите сортировку:\n1 - Пузырьком (Bubble)\n2 - Выбором (Selection)\n> ";
            int sortType;
            cin >> sortType;

            if (sortType == 1) {
                numbers.bubbleSort();
                cout << "После Bubble sort: ";
            } else {
                numbers.selectionSort();
                cout << "После Selection sort: ";
            }
            printIntList(numbers);
        }

    } while (mode != 0);

    return 0;
}
