#ifndef NATURAL_MERGE_SORT_CPP
#define NATURAL_MERGE_SORT_CPP

#include <vector>
#include <algorithm>

template<typename T>
std::vector<T> natural_merge_sort(const std::vector<T>& input) {
    if (input.empty()) return {};
    std::vector<T> res;
    size_t i = 0;
    while (i < input.size()) {
        std::vector<T> run;
        run.push_back(input[i++]);
        while (i < input.size() && input[i] >= input[i-1]) {
            run.push_back(input[i++]);
        }
        std::vector<T> merged;
        std::merge(res.begin(), res.end(), run.begin(), run.end(), std::back_inserter(merged));
        res = std::move(merged);
    }
    return res;
}
#endif
