#ifndef ONE_PHASE_MERGE_SORT_CPP
#define ONE_PHASE_MERGE_SORT_CPP

#include <vector>
#include <algorithm>

template<typename T>
std::vector<T> one_phase_merge_sort(const std::vector<T>& input, size_t run_size) {
    if (input.empty()) return {};
    // В однофазной сортировке мы сразу формируем и сливаем серии в один проход
    std::vector<T> result;
    for (size_t i = 0; i < input.size(); i += run_size) {
        size_t sz = std::min(run_size, input.size() - i);
        std::vector<T> run(input.begin() + i, input.begin() + i + sz);
        std::sort(run.begin(), run.end());
        std::vector<T> merged;
        std::merge(result.begin(), result.end(), run.begin(), run.end(), std::back_inserter(merged));
        result = std::move(merged);
    }
    return result;
}
#endif
