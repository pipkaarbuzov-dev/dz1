#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/one_phase_merge_sort.h"

TEST_CASE("One-phase merge sort tests") {
    std::vector<double> v = {3.1, 1.2, 5.5};
    auto res = one_phase_merge_sort(v, 2);
    REQUIRE(std::is_sorted(res.begin(), res.end()));
}
