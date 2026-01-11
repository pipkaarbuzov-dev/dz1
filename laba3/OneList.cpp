#ifndef ONELIST_CPP
#define ONELIST_CPP

#include "OneList.h"
#include <stdexcept>

// --- Реализация Итератора ---

template <typename T>
typename OneList<T>::Iterator& OneList<T>::Iterator::operator++() {
    if (current) current = current->next;
    return *this;
}

template <typename T>
typename OneList<T>::Iterator OneList<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    if (current) current = current->next;
    return temp;
}

template <typename T>
typename OneList<T>::Iterator& OneList<T>::Iterator::operator--() {
    // В односвязном списке для шага назад нужно искать элемент с самого начала
    if (current == list_ref->head) {
        // Нельзя уйти за начало
        return *this;
    }
    
    if (current == nullptr) { 
        // Если мы в end(), то предыдущий - это tail
        current = list_ref->tail;
        return *this;
    }

    // Ищем элемент, чей next указывает на current
    Element* temp = list_ref->head;
    while (temp && temp->next != current) {
        temp = temp->next;
    }
    current = temp;
    return *this;
}

template <typename T>
typename OneList<T>::Iterator OneList<T>::Iterator::operator--(int) {
    Iterator temp = *this;
    --(*this);
    return temp;
}

// --- Реализация Списка ---

template <typename T>
OneList<T>::OneList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
OneList<T>::~OneList() {
    clear();
}

template <typename T>
void OneList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
void OneList<T>::push_front(T data) {
    Element* newElem = new Element(data);
    if (empty()) {
        head = tail = newElem;
    } else {
        newElem->next = head;
        head = newElem;
    }
    count++;
}

template <typename T>
void OneList<T>::push_back(T data) {
    Element* newElem = new Element(data);
    if (empty()) {
        head = tail = newElem;
    } else {
        tail->next = newElem;
        tail = newElem;
    }
    count++;
}

template <typename T>
void OneList<T>::insert(int index, T data) {
    if (index < 0 || index > count) throw std::out_of_range("Index out of range");
    if (index == 0) {
        push_front(data);
        return;
    }
    if (index == count) {
        push_back(data);
        return;
    }

    Element* prev = head;
    for (int i = 0; i < index - 1; ++i) {
        prev = prev->next;
    }
    Element* newElem = new Element(data);
    newElem->next = prev->next;
    prev->next = newElem;
    count++;
}

template <typename T>
void OneList<T>::pop_front() {
    if (empty()) return;
    Element* temp = head;
    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete temp;
    count--;
}

template <typename T>
void OneList<T>::pop_back() {
    if (empty()) return;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Element* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    count--;
}

template <typename T>
void OneList<T>::remove(T data) {
    while (!empty() && head->data == data) {
        pop_front();
    }
    if (empty()) return;

    Element* current = head;
    while (current->next != nullptr) {
        if (current->next->data == data) {
            Element* toDelete = current->next;
            current->next = toDelete->next;
            if (toDelete == tail) tail = current;
            delete toDelete;
            count--;
        } else {
            current = current->next;
        }
    }
}

template <typename T>
size_t OneList<T>::size() const { return count; }

template <typename T>
bool OneList<T>::empty() const { return count == 0; }

template <typename T>
T& OneList<T>::front() { return head->data; }

template <typename T>
T& OneList<T>::back() { return tail->data; }

template <typename T>
typename OneList<T>::Iterator OneList<T>::begin() {
    return Iterator(head, this);
}

template <typename T>
typename OneList<T>::Iterator OneList<T>::end() {
    return Iterator(nullptr, this);
}

#endif
