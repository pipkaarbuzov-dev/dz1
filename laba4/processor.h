#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "double_list.h"
#include <cctype>

// Вспомогательная функция: реверс диапазона значений
template <typename Iterator>
void reverse_range(Iterator start, Iterator end) {
    if (start == end) return;
    Iterator last = end; 
    --last; // end указывает "за" последний элемент, сдвигаем на реальный последний

    // Пока итераторы не встретятся
    while (start != last) { 
        // Обмен значений
        auto temp = *start;
        *start = *last;
        *last = temp;

        ++start;
        if (start == last) break; // Проверка на встречу посередине
        --last;
    }
}

// Вспомогательная: проверка на разделитель (пробел)
bool is_delim(char c) {
    return std::isspace(static_cast<unsigned char>(c));
}

// ОСНОВНАЯ ФУНКЦИЯ ЗАДАНИЯ
void process_task(DoubleList<char>& list) {
    if (list.empty()) return;

    // 1. Анализ строки: длина и наличие заглавного слова
    int len = list.size();
    bool has_caps_word = false;

    auto it = list.begin();
    while (it != list.end()) {
        if (!is_delim(*it)) {
            bool all_upper = true;
            bool has_alpha = false;
            
            // Читаем слово целиком
            while (it != list.end() && !is_delim(*it)) {
                if (std::isalpha((unsigned char)*it)) {
                    has_alpha = true;
                    if (!std::isupper((unsigned char)*it)) all_upper = false;
                }
                ++it;
            }
            if (has_alpha && all_upper) has_caps_word = true;
        } else {
            ++it;
        }
    }

    // 2. Выполнение условий
    if (len > 10 && has_caps_word) {
        // Условие 1: Реверс всех слов
        // Сначала переворачиваем всю строку: "HELLO WORLD" -> "DLROW OLLEH"
        reverse_range(list.begin(), list.end());

        // Потом переворачиваем каждое слово обратно: "DLROW" -> "WORLD"
        auto start = list.begin();
        while (start != list.end()) {
            if (is_delim(*start)) {
                ++start;
                continue;
            }
            auto end = start;
            while (end != list.end() && !is_delim(*end)) ++end;
            
            reverse_range(start, end);
            start = end;
        }

    } else {
        // Условие 2: Поменять местами первое и последнее слово
        
        // Границы первого слова
        auto first_start = list.begin();
        while (first_start != list.end() && is_delim(*first_start)) ++first_start;
        if (first_start == list.end()) return; // Пустая строка или только пробелы

        auto first_end = first_start;
        while (first_end != list.end() && !is_delim(*first_end)) ++first_end;

        // Границы последнего слова (ищем с конца или полным проходом)
        auto scan = first_end;
        auto last_start = list.end();
        bool found_second = false;

        while (scan != list.end()) {
            if (!is_delim(*scan)) {
                last_start = scan; // Нашли начало нового слова
                found_second = true;
                while (scan != list.end() && !is_delim(*scan)) ++scan;
            } else {
                ++scan;
            }
        }

        if (!found_second) return; // Только одно слово

        // Чтобы поменять слова разной длины, проще всего использовать
        // "Метод трех реверсов" для обмена блоков, но в рамках учебного задания
        // надежнее пересобрать список через временные буферы (так понятнее работает)
        
        DoubleList<char> result;
        auto ptr = last_start; // 1. Последнее слово
        while (ptr != list.end() && !is_delim(*ptr)) { result.push_back(*ptr); ++ptr; }
        
        result.push_back(' '); // Разделитель (упрощенно)

        ptr = first_end; // 2. Середина
        while (ptr != last_start) { result.push_back(*ptr); ++ptr; }

        if (result.back() != ' ') result.push_back(' ');

        ptr = first_start; // 3. Первое слово
        while (ptr != first_end) { result.push_back(*ptr); ++ptr; }

        // Заменяем исходный список
        list.clear();
        for (auto x : result) list.push_back(x);
    }
}

#endif
