#include "selection_sort.h"

template<typename T>
void selectionSort(std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}

// Явное инстанцирование
template void selectionSort<int>(std::vector<int>& arr);
template void selectionSort<double>(std::vector<double>& arr);