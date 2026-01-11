#include "method2.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

static void rev(char* s, char* e) {
    while (s < e) { char t = *s; *s++ = *e; *e-- = t; }
}

void process2(char* str) {
    int len = strlen(str);
    if (len == 0) return;
    bool has_caps = false;
    char *p1 = nullptr, *e1 = nullptr, *pn = nullptr, *en = nullptr;
    int words = 0;
    char* curr = str;
    while (*curr) {
        while (*curr && isspace(*curr)) curr++;
        if (*curr) {
            char* ws = curr; bool upper = true, alpha = false;
            while (*curr && !isspace(*curr)) {
                if (isalpha(*curr)) { alpha = true; if (!isupper(*curr)) upper = false; }
                curr++;
            }
            words++;
            if (words == 1) { p1 = ws; e1 = curr - 1; }
            pn = ws; en = curr - 1;
            if (alpha && upper) has_caps = true;
        }
    }
    if (words < 2) return;
    if (len > 10 && has_caps) {
        rev(str, str + len - 1);
        curr = str;
        while (*curr) {
            while (*curr && isspace(*curr)) curr++;
            if (*curr) { char* s = curr; while (*curr && !isspace(*curr)) curr++; rev(s, curr - 1); }
        }
    } else {
        int l1 = e1 - p1 + 1, ln = en - pn + 1;
        rev(p1, en); rev(p1, p1 + ln - 1); rev(en - l1 + 1, en);
        if (p1 + ln < en - l1) rev(p1 + ln, en - l1);
    }
}

void method2() {
    const int BLOCK = 5;
    int cap = BLOCK, len = 0;
    char* str = (char*)calloc(cap, 1);
    cout << "Метод 2 (realloc по 5): введите строку: ";
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (len + 1 >= cap) { cap += BLOCK; str = (char*)realloc(str, cap); }
        str[len++] = c;
        str[len] = '\0';
    }
    process2(str);
    cout << "Результат: " << str << endl;
    free(str);
}
