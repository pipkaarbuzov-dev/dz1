#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/shell_sort.h"
#include <algorithm>

TEST_CASE("Shell Sort: Basic functionality", "[shell]") {
    std::vector<int> v = {5, 2, 9, 1, 5, 6};
    shell_sort(v);
    REQUIRE(std::is_sorted(v.begin(), v.end()));
}

TEST_CASE("Shell Sort: Edge cases", "[shell]") {
    SECTION("Empty vector") {
        std::vector<int> v;
        shell_sort(v);
        REQUIRE(v.empty());
    }
    SECTION("Single element") {
        std::vector<double> v = {3.14};
        shell_sort(v);
        REQUIRE(v[0] == 3.14);
    }
}

TEST_CASE("Shell Sort: Variant cases", "[shell]") {
    std::vector<int> v = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // Обратный порядок
    shell_sort(v);
    REQUIRE(std::is_sorted(v.begin(), v.end()));
}
