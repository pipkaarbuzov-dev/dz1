#include <iostream>
#include <string>
#include "OneList.h"
#include "DoubleList.h"
#include "processor.h"

using namespace std;

// Функция для конвертации string -> List
template <typename ListT>
void stringToList(const string& s, ListT& list) {
    list.clear();
    for (char c : s) {
        list.push_back(c);
    }
}

// Функция для конвертации List -> string (для вывода)
template <typename ListT>
void printList(ListT& list) {
    auto it = list.begin();
    while (it != list.end()) {
        cout << *it;
        it++;
    }
    cout << endl;
}

void testOneList() {
    cout << "\n--- Работа с OneList (Односвязный) ---\n";
    OneList<char> list;
    string input;
    
    cout << "Введите строку: ";
    getline(cin, input);
    if (input.empty()) getline(cin, input); // фикс для буфера
    
    stringToList(input, list);
    
    cout << "Исходный список: ";
    printList(list);
    
    process_string(list);
    
    cout << "Результат:       ";
    printList(list);
}

void testDoubleList() {
    cout << "\n--- Работа с DoubleList (Двухсвязный) ---\n";
    DoubleList<char> list;
    string input;
    
    cout << "Введите строку: ";
    getline(cin, input);
    if (input.empty()) getline(cin, input);
    
    stringToList(input, list);
    
    cout << "Исходный список: ";
    printList(list);
    
    process_string(list);
    
    cout << "Результат:       ";
    printList(list);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    do {
        cout << "\n1. Тест Односвязного списка (OneList)\n";
        cout << "2. Тест Двухсвязного списка (DoubleList)\n";
        cout << "0. Выход\n";
        cout << "> ";
        cin >> choice;

        switch (choice) {
        case 1: testOneList(); break;
        case 2: testDoubleList(); break;
        case 0: break;
        default: cout << "Неверный ввод.\n";
        }
    } while (choice != 0);

    return 0;
}
