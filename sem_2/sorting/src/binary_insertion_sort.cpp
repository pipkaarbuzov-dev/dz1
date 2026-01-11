#ifndef BINARY_INSERTION_SORT_CPP
#define BINARY_INSERTION_SORT_CPP

#include <vector>

template<typename T>
int find_insertion_point(const std::vector<T>& arr, int left, int right, const T& key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

template<typename T>
void binary_insertion_sort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int pos = find_insertion_point(arr, 0, i - 1, key);

        for (int j = i - 1; j >= pos; j--) {
            arr[j + 1] = arr[j];
        }
        arr[pos] = key;
    }
}

#endif
