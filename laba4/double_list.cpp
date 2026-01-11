#ifndef DOUBLE_LIST_CPP
#define DOUBLE_LIST_CPP

#include "double_list.h"

template <typename T>
DoubleList<T>::DoubleList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
DoubleList<T>::~DoubleList() { clear(); }

template <typename T>
void DoubleList<T>::push_back(T data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}

template <typename T>
void DoubleList<T>::push_front(T data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    count++;
}

template <typename T>
void DoubleList<T>::pop_back() {
    if (!tail) return;
    Node* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
    count--;
}

template <typename T>
void DoubleList<T>::pop_front() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
    count--;
}

template <typename T>
void DoubleList<T>::clear() {
    while (head) pop_front();
}

template <typename T>
int DoubleList<T>::size() const { return count; }

template <typename T>
bool DoubleList<T>::empty() const { return count == 0; }

// ---------------------------------------------------------
// Реализация сортировок (Лаба 4)
// ---------------------------------------------------------

// 1. Пузырьковая сортировка (Bubble Sort)
template <typename T>
void DoubleList<T>::bubbleSort() {
    if (count < 2) return;

    for (int i = 0; i < count - 1; i++) {
        Node* current = head;
        for (int j = 0; j < count - i - 1; j++) {
            if (current->data > current->next->data) {
                // Меняем значения местами
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
            current = current->next;
        }
    }
}

// 2. Сортировка выбором (Selection Sort)
template <typename T>
void DoubleList<T>::selectionSort() {
    if (count < 2) return;

    Node* i_node = head;
    while (i_node) {
        Node* min_node = i_node;
        Node* j_node = i_node->next;

        // Ищем минимум в оставшейся части списка
        while (j_node) {
            if (j_node->data < min_node->data) {
                min_node = j_node;
            }
            j_node = j_node->next;
        }

        // Если нашли элемент меньше текущего - меняем местами
        if (min_node != i_node) {
            T temp = i_node->data;
            i_node->data = min_node->data;
            min_node->data = temp;
        }

        i_node = i_node->next;
    }
}

#endif
