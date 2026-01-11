#ifndef SHELL_SORT_CPP
#define SHELL_SORT_CPP

#include <vector>

template<typename T>
void shell_sort(std::vector<T>& arr) {
    int n = arr.size();
    // Используем классическую последовательность шагов n/2, n/4...
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

#endif
