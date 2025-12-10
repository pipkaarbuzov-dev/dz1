#include "bubble_sort.h"

template<typename T>
void bubbleSort(std::vector<T>& arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template void bubbleSort<int>(std::vector<int>& arr);
template void bubbleSort<double>(std::vector<double>& arr);