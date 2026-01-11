#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/quick_sort.h"
#include <string>
#include <vector>
#include <sstream>

// Вспомогательная функция для вашего задания №21
std::string process_task_21(std::string str) {
    std::stringstream ss(str);
    std::string word;
    std::vector<std::string> words;
    bool has_upper_word = false;

    while (ss >> word) {
        words.push_back(word);
        bool all_upper = true;
        for(char c : word) if(isalpha(c) && !isupper(c)) all_upper = false;
        if (all_upper) has_upper_word = true;
    }

    if (str.length() > 10 && has_upper_word) {
        std::reverse(words.begin(), words.end());
    } else if (!words.empty()) {
        std::swap(words.front(), words.back());
    }

    std::string res;
    for(size_t i=0; i<words.size(); ++i) 
        res += words[i] + (i == words.size()-1 ? "" : " ");
    return res;
}

TEST_CASE("Quick Sort: Basic functionality", "[quick]") {
    std::vector<int> v = {3, 19, 10, 1, 15, 4, 11, 20};
    quick_sort(v);
    REQUIRE(std::is_sorted(v.begin(), v.end()));
}

TEST_CASE("Task 21: Integration check", "[task21]") {
    SECTION("Reverse words (long + CAPS)") {
        std::string input = "HELLO world test string";
        REQUIRE(process_task_21(input) == "string test world HELLO");
    }
    SECTION("Swap first and last (short)") {
        std::string input = "Hi CAPS"; 
        REQUIRE(process_task_21(input) == "CAPS Hi");
    }
}
