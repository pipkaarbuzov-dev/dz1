#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/two_phase_merge_sort.h"

TEST_CASE("Two-phase merge sort tests") {
    std::vector<int> v = {5, 3, 8, 1};
    REQUIRE(two_phase_merge_sort(v, 2) == std::vector<int>{1, 3, 5, 8});
    
    std::vector<int> empty;
    REQUIRE(two_phase_merge_sort(empty).empty());
    
    std::vector<int> sorted = {1, 2, 3};
    REQUIRE(two_phase_merge_sort(sorted) == sorted);
}
