#include "catch.hpp"
#include <string>
#include <vector>
#include <sstream>

// Логика вашего задания №21
std::string process_string_task_21(std::string str) {
    if (str.empty()) return "";
    
    // Разбиваем на слова
    std::stringstream ss(str);
    std::string word;
    std::vector<std::string> words;
    bool has_all_caps = false;

    while (ss >> word) {
        words.push_back(word);
        // Проверка на заглавное слово
        bool all_caps = true;
        bool has_alpha = false;
        for(char c : word) {
            if(isalpha(c)) {
                has_alpha = true;
                if(!isupper(c)) all_caps = false;
            }
        }
        if (has_alpha && all_caps) has_all_caps = true;
    }

    if (str.length() > 10 && has_all_caps) {
        // Условие выполнено: реверс слов
        std::string result = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i] + (i == 0 ? "" : " ");
        }
        return result;
    } else {
        // Условие не выполнено: меняем первое и последнее
        if (words.size() > 1) {
            std::swap(words.front(), words.back());
        }
        std::string result = "";
        for (size_t i = 0; i < words.size(); i++) {
            result += words[i] + (i == words.size() - 1 ? "" : " ");
        }
        return result;
    }
}

TEST_CASE("Task 21 Logic Tests") {
    SECTION("Condition met: Length > 10 and HAS ALL CAPS word") {
        std::string input = "Мама мыла КРАСИВУЮ раму";
        std::string expected = "раму КРАСИВУЮ мыла Мама";
        REQUIRE(process_string_task_21(input) == expected);
    }

    SECTION("Condition NOT met: Short string") {
        std::string input = "HELLO world"; // Длина 11, но допустим проверяем логику замены
        // Если длина <= 10 или нет CAPS слов:
        REQUIRE(process_string_task_21("Hi WORLD") == "WORLD Hi");
    }

    SECTION("Condition NOT met: No CAPS word") {
        std::string input = "simple sentence without caps";
        // Должно поменять "simple" и "caps"
        REQUIRE(process_string_task_21(input) == "caps sentence without simple");
    }
}
