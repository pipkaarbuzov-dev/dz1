#include <iostream>
#include <clocale>
#include "method1.h"
#include "method2.h"
#include "method3.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    while (true) {
        cout << "\nВыберите метод:\n";
        cout << "1 — malloc (по 1 символу)\n";
        cout << "2 — calloc + realloc (блоками по 5)\n";
        cout << "3 — файлы (input.txt -> output.txt)\n";
        cout << "0 — выход\n";
        cout << "> ";
        if (!(cin >> choice)) break;
        getchar();

        if (choice == 0) break;
        switch (choice) {
            case 1: method1(); break;
            case 2: method2(); break;
            case 3: method3(); break;
            default: cout << "Ошибка\n";
        }
    }
    return 0;
}
