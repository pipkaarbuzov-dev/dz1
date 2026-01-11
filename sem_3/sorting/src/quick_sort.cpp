#ifndef QUICK_SORT_CPP
#define QUICK_SORT_CPP

#include <vector>
#include <algorithm>

template<typename T>
void quick_sort_recursive(std::vector<T>& arr, int left, int right) {
    int i = left, j = right;
    T pivot = arr[left + (right - left) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) quick_sort_recursive(arr, left, j);
    if (i < right) quick_sort_recursive(arr, i, right);
}

template<typename T>
void quick_sort(std::vector<T>& arr) {
    if (!arr.empty()) {
        quick_sort_recursive(arr, 0, arr.size() - 1);
    }
}

#endif
