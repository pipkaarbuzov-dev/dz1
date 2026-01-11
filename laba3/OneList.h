#pragma once
#include <iterator>
#include <iostream>

template <typename T>
class OneList {
public:
    // Структура элемента списка
    struct Element {
        T data;
        Element* next;
        Element(T value) : data(value), next(nullptr) {}
    };

    // Класс итератора
    class Iterator {
    private:
        Element* current;
        OneList<T>* list_ref; // Ссылка на список нужна для реализации operator--
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(Element* node, OneList<T>* list) : current(node), list_ref(list) {}

        T& operator*() const { return current->data; }
        Element* getNode() const { return current; }

        // Операторы перемещения
        Iterator& operator++();    // ++it
        Iterator operator++(int);  // it++
        Iterator& operator--();    // --it (сложная операция для односвязного)
        Iterator operator--(int);  // it--

        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

private:
    Element* head;
    Element* tail;
    size_t count;

public:
    OneList();
    ~OneList();

    // Основные методы по заданию
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

    // Методы для итераторов
    Iterator begin();
    Iterator end();
};

// Подключаем реализацию шаблона (необходимо для C++)
#include "OneList.cpp"
