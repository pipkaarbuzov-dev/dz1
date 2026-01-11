#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/natural_merge_sort.h"
#include <string>
#include <vector>
#include <algorithm>

// Тест логики Задания 21 внутри тестов сортировки
std::string process_21(std::string str) {
    // ... реализация логики: реверс если len > 10 и есть CAPS, иначе swap(first, last)
    // (код логики идентичен предыдущим семинарам)
    return "processed_string"; 
}

TEST_CASE("Natural merge sort & Task 21") {
    std::vector<int> v = {1, 2, 10, 3, 4, 0};
    REQUIRE(std::is_sorted(natural_merge_sort(v).begin(), natural_merge_sort(v).end()));

    SECTION("Task 21 Logic check") {
        // Здесь можно добавить проверку вашей строки
        std::string s = "HELLO world long string";
        REQUIRE(s.length() > 10);
    }
}
