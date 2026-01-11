#ifndef SHAKER_SORT_CPP
#define SHAKER_SORT_CPP

#include <vector>
#include <algorithm>

template<typename T>
void shaker_sort(std::vector<T>& arr) {
    if (arr.empty()) return;
    int left = 0;
    int right = arr.size() - 1;
    bool swapped = true;

    while (left < right && swapped) {
        swapped = false;
        // Проход слева направо (как в пузырьке)
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        right--;

        // Проход справа налево
        for (int i = right; i > left; i--) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
        left++;
    }
}

#endif
