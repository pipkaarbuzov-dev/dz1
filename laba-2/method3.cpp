#include "method3.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

static void rev3(char* s, char* e) {
    while (s < e) { char t = *s; *s++ = *e; *e-- = t; }
}

void process3(char* str) {
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
        rev3(str, str + len - 1);
        curr = str;
        while (*curr) {
            while (*curr && isspace(*curr)) curr++;
            if (*curr) { char* s = curr; while (*curr && !isspace(*curr)) curr++; rev3(s, curr - 1); }
        }
    } else {
        int l1 = e1 - p1 + 1, ln = en - pn + 1;
        rev3(p1, en); rev3(p1, p1 + ln - 1); rev3(en - l1 + 1, en);
        if (p1 + ln < en - l1) rev3(p1 + ln, en - l1);
    }
}

void method3() {
    cout << "Метод 3 (Файлы): введите строку: ";
    char* str = (char*)malloc(1); str[0] = '\0';
    int len = 0; char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        char* ns = (char*)malloc(len + 2);
        if (str) { memcpy(ns, str, len); free(str); }
        ns[len] = c; ns[len+1] = '\0'; str = ns; len++;
    }

    FILE* f = fopen("input.txt", "w");
    if (f) { fputs(str, f); fclose(f); }
    free(str);

    // Чтение из файла динамически (увеличение на 1)
    FILE* f2 = fopen("input.txt", "r");
    if (!f2) return;
    char* str2 = (char*)malloc(1); str2[0] = '\0';
    int len2 = 0;
    while ((c = fgetc(f2)) != EOF) {
        char* ns = (char*)malloc(len2 + 2);
        if (str2) { memcpy(ns, str2, len2); free(str2); }
        ns[len2] = c; ns[len2+1] = '\0'; str2 = ns; len2++;
    }
    fclose(f2);

    process3(str2);
    FILE* f3 = fopen("output.txt", "w");
    if (f3) { fputs(str2, f3); fclose(f3); }
    free(str2);
    cout << "Готово. Результат в output.txt" << endl;
}
