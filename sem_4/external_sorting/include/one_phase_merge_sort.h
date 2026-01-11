#ifndef ONE_PHASE_MERGE_SORT_H
#define ONE_PHASE_MERGE_SORT_H

#include <vector>

template<typename T>
std::vector<T> one_phase_merge_sort(const std::vector<T>& input, size_t run_size = 4);

#include "../src/one_phase_merge_sort.cpp"
#endif
