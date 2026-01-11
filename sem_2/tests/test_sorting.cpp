#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/binary_insertion_sort.h"
#include "../include/shaker_sort.h"
#include <string>
#include <vector>
#include <algorithm>

TEST_CASE("Sorting Algorithms: Edge Cases") {
    std::vector<int> empty_vec;
    std::vector<int> single_vec = {42};
    std::vector<int> sorted_vec = {1, 2, 3, 4, 5};
    std::vector<int> reverse_vec = {5, 4, 3, 2, 1};

    SECTION("Binary Insertion Sort") {
        binary_insertion_sort(empty_vec);
        REQUIRE(empty_vec.empty());

        binary_insertion_sort(single_vec);
        REQUIRE(single_vec[0] == 42);

        binary_insertion_sort(reverse_vec);
        REQUIRE(std::is_sorted(reverse_vec.begin(), reverse_vec.end()));
    }

    SECTION("Shaker Sort") {
        shaker_sort(empty_vec);
        REQUIRE(empty_vec.empty());

        shaker_sort(single_vec);
        REQUIRE(single_vec[0] == 42);

        shaker_sort(reverse_vec);
        REQUIRE(std::is_sorted(reverse_vec.begin(), reverse_vec.end()));
    }
}
