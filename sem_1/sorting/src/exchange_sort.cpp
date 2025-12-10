#include "exchange_sort.h"

template<typename T>
void exchangeSort(std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template void exchangeSort<int>(std::vector<int>& arr);
template void exchangeSort<double>(std::vector<double>& arr);