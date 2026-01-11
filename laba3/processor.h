#pragma once
#include <cctype>
#include <iostream>

// Вспомогательная функция для реверса диапазона итераторов
template <typename Iterator>
void reverse_range(Iterator begin, Iterator end) {
    // Внимание: end указывает ЗА последний элемент, поэтому уменьшаем его
    if (begin == end) return;
    Iterator last = end;
    last--; // теперь last указывает на реальный последний элемент

    while (begin != last) {
        // Меняем местами значения
        auto temp = *begin;
        *begin = *last;
        *last = temp;

        begin++;
        if (begin == last) break; // Встретились посередине
        last--;
    }
}

// Основная функция обработки
template <typename ListType>
void process_string(ListType& list) {
    if (list.empty()) return;

    size_t len = list.size();
    bool has_caps_word = false;
    
    // 1. Анализ строки: ищем ЗАГЛАВНОЕ слово
    auto it = list.begin();
    while (it != list.end()) {
        if (std::isspace(*it)) {
            it++;
            continue;
        }
        
        bool is_word_upper = true;
        bool has_alpha = false;
        
        // Проверяем слово
        while (it != list.end() && !std::isspace(*it)) {
            if (std::isalpha(*it)) {
                has_alpha = true;
                if (!std::isupper(*it)) is_word_upper = false;
            }
            it++;
        }
        
        if (has_alpha && is_word_upper) {
            has_caps_word = true;
        }
    }

    // 2. Выполнение задания
    bool condition = (len > 10 && has_caps_word);

    if (condition) {
        // Сценарий 1: Переставить все слова в обратном порядке
        // Метод двойного реверса:
        // 1. Реверс всей строки (HELLO WORLD -> DLROW OLLEH)
        reverse_range(list.begin(), list.end());

        // 2. Реверс каждого слова обратно (DLROW -> WORLD)
        it = list.begin();
        while (it != list.end()) {
            if (std::isspace(*it)) {
                it++;
                continue;
            }
            auto word_start = it;
            while (it != list.end() && !std::isspace(*it)) {
                it++;
            }
            auto word_end = it;
            reverse_range(word_start, word_end);
        }

    } else {
        // Сценарий 2: Поменять местами первое и последнее слово
        // Для списков это сложно делать указателями, проще пересобрать список значений
        
        // Находим границы первого слова
        auto p1_start = list.begin();
        while (p1_start != list.end() && std::isspace(*p1_start)) p1_start++;
        if (p1_start == list.end()) return; // слов нет
        
        auto p1_end = p1_start;
        while (p1_end != list.end() && !std::isspace(*p1_end)) p1_end++;

        // Находим границы последнего слова
        // (Идем с конца, если бы это был DoubleList было бы проще, 
        // но для универсальности пройдемся дважды или сохраним позиции)
        
        // Чтобы не зависеть от типа итератора, соберем слова во временные списки
        ListType wordFirst, wordLast, middle;
        
        auto curr = list.begin();
        int word_count = 0;
        
        // Считаем слова и позиции
        // Упрощенный подход для списков:
        // Создадим копию списка для чтения
        // Это не самый эффективный, но самый надежный способ для Lab с шаблонами
        
        // --- Метод трех реверсов для обмена первого и последнего ---
        // 1. Реверс всей строки: [Last_Rev] ... [First_Rev]
        // 2. Найти новое первое (бывшее последнее) -> реверс его
        // 3. Найти новое последнее (бывшее первое) -> реверс его
        // 4. Реверс середины (между ними)
        // Этот метод работает "на месте" (in-place)
        
        // A. Реверс всей строки
        reverse_range(list.begin(), list.end());
        
        // Теперь структура: [Last_Reversed] [Spaces] [Middle_Reversed] [Spaces] [First_Reversed]
        
        // B. Реверс первого сегмента (это бывшее последнее слово)
        auto w_start = list.begin();
        while (w_start != list.end() && std::isspace(*w_start)) w_start++;
        auto w_end = w_start;
        while (w_end != list.end() && !std::isspace(*w_end)) w_end++;
        reverse_range(w_start, w_end);
        
        // C. Ищем последний сегмент (это бывшее первое слово) в уже перевернутой строке
        // Для этого нужно пройти до конца
        auto scan = list.begin();
        auto last_w_start = scan;
        bool in_word = false;
        
        while (scan != list.end()) {
            if (!std::isspace(*scan)) {
                if (!in_word) {
                    last_w_start = scan; // начало текущего слова
                    in_word = true;
                }
            } else {
                in_word = false;
            }
            scan++;
        }
        // scan теперь end(), last_w_start указывает на начало последнего слова
        reverse_range(last_w_start, list.end());
        
        // D. Реверс середины (между первым и последним словами)
        if (w_end != list.end() && w_end != last_w_start) {
             // w_end указывает на пробел после первого слова
             // last_w_start указывает на начало последнего слова
             // Нам нужно реверсировать всё между ними
             reverse_range(w_end, last_w_start);
        }
    }
}
