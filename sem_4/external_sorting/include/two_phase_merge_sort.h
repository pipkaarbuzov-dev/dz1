#ifndef TWO_PHASE_MERGE_SORT_H
#define TWO_PHASE_MERGE_SORT_H

#include <vector>
#include <string>

template<typename T>
std::vector<T> two_phase_merge_sort(const std::vector<T>& input, size_t run_size = 4);

#include "../src/two_phase_merge_sort.cpp"
#endif
