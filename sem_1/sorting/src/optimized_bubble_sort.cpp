#include "optimized_bubble_sort.h"

template<typename T>
void optimizedBubbleSort(std::vector<T>& arr) {
    size_t n = arr.size();
    bool swapped;
    for (size_t i = 0; i < n; ++i) {
        swapped = false;
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

template void optimizedBubbleSort<int>(std::vector<int>& arr);
template void optimizedBubbleSort<double>(std::vector<double>& arr);