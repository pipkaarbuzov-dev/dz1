#include "insertion_sort.h"

template<typename T>
void insertionSort(std::vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        T key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

template void insertionSort<int>(std::vector<int>& arr);
template void insertionSort<double>(std::vector<double>& arr);