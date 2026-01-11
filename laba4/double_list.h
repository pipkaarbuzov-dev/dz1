#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <iostream>
#include <iterator>

template <typename T>
class DoubleList {
public:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T val) : data(val), next(nullptr), prev(nullptr) {}
    };

    // --- Итератор для удобного обхода ---
    class Iterator {
        Node* current;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(Node* node) : current(node) {}
        
        T& operator*() { return current->data; }
        Node* getNode() { return current; }
        
        Iterator& operator++() { 
            if (current) current = current->next; 
            return *this; 
        }
        Iterator& operator--() { 
            if (current) current = current->prev; 
            return *this; 
        }
        bool operator!=(const Iterator& other) { return current != other.current; }
        bool operator==(const Iterator& other) { return current == other.current; }
    };

private:
    Node* head;
    Node* tail;
    int count;

public:
    DoubleList();
    ~DoubleList();

    void push_back(T data);
    void push_front(T data);
    void pop_back();
    void pop_front();
    void clear();
    
    int size() const;
    bool empty() const;

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }

    // --- Методы сортировки (Задание Лабы 4) ---
    void bubbleSort();    // Сортировка пузырьком
    void selectionSort(); // Сортировка выбором
};

// Подключаем реализацию, так как это шаблонный класс
#include "double_list.cpp"

#endif
