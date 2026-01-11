#ifndef BINARY_INSERTION_SORT_H
#define BINARY_INSERTION_SORT_H

#include <vector>

// Сортировка вставками с бинарным поиском места вставки
template <typename T>
void binary_insertion_sort(std::vector<T>& arr);

#include "../src/binary_insertion_sort.cpp"

#endif
