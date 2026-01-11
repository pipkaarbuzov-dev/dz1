#include "method1.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

// Вспомогательная функция для реверса участка памяти
void reverse(char* start, char* end) {
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

void process1(char* str) {
    int len = strlen(str);
    if (len == 0) return;

    bool has_caps = false;
    char *p1 = nullptr, *e1 = nullptr, *pn = nullptr, *en = nullptr;
    int words = 0;

    char* curr = str;
    while (*curr) {
        while (*curr && isspace(*curr)) curr++;
        if (*curr) {
            char* ws = curr;
            bool only_upper = true;
            bool has_alpha = false;
            while (*curr && !isspace(*curr)) {
                if (isalpha(*curr)) {
                    has_alpha = true;
                    if (!isupper(*curr)) only_upper = false;
                }
                curr++;
            }
            char* we = curr - 1;
            words++;
            if (words == 1) { p1 = ws; e1 = we; }
            pn = ws; en = we;
            if (has_alpha && only_upper) has_caps = true;
        }
    }

    if (words < 2) return;

    if (len > 10 && has_caps) {
        // Реверс всех слов
        reverse(str, str + len - 1);
        curr = str;
        while (*curr) {
            while (*curr && isspace(*curr)) curr++;
            if (*curr) {
                char* s = curr;
                while (*curr && !isspace(*curr)) curr++;
                reverse(s, curr - 1);
            }
        }
    } else {
        // Обмен первого и последнего
        int l1 = e1 - p1 + 1, ln = en - pn + 1;
        reverse(p1, en);
        reverse(p1, p1 + ln - 1);
        reverse(en - l1 + 1, en);
        if (p1 + ln < en - l1) reverse(p1 + ln, en - l1);
    }
}

void method1() {
    cout << "Метод 1 (malloc + 1): введите строку: ";
    char c;
    int len = 0;
    char* str = (char*)malloc(1);
    str[0] = '\0';

    while ((c = getchar()) != '\n' && c != EOF) {
        char* newStr = (char*)malloc(len + 2);
        if (str) {
            memcpy(newStr, str, len);
            free(str);
        }
        newStr[len] = c;
        newStr[len + 1] = '\0';
        str = newStr;
        len++;
    }

    process1(str);
    cout << "Результат: " << str << endl;
    free(str);
}

