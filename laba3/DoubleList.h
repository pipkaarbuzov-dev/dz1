#pragma once
#include <iterator>

template <typename T>
class DoubleList {
public:
    struct Element {
        T data;
        Element* next;
        Element* prev;
        Element(T value) : data(value), next(nullptr), prev(nullptr) {}
    };

    class Iterator {
    private:
        Element* current;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(Element* node) : current(node) {}

        T& operator*() const { return current->data; }
        Element* getNode() const { return current; }

        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);

        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

private:
    Element* head;
    Element* tail;
    size_t count;

public:
    DoubleList();
    ~DoubleList();

    void push_front(T data);
    void push_back(T data);
    void insert(int index, T data);
    void pop_front();
    void pop_back();
    void remove(T data);
    
    size_t size() const;
    bool empty() const;
    T& front();
    T& back();
    void clear();

    Iterator begin();
    Iterator end();
    Iterator last(); // Вспомогательный метод для получения итератора на хвост
};

#include "DoubleList.cpp"
