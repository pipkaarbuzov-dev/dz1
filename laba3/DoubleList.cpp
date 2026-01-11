#ifndef DOUBLELIST_CPP
#define DOUBLELIST_CPP

#include "DoubleList.h"
#include <stdexcept>

// --- Iterator ---
template <typename T>
typename DoubleList<T>::Iterator& DoubleList<T>::Iterator::operator++() {
    if (current) current = current->next;
    return *this;
}

template <typename T>
typename DoubleList<T>::Iterator DoubleList<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    if (current) current = current->next;
    return temp;
}

template <typename T>
typename DoubleList<T>::Iterator& DoubleList<T>::Iterator::operator--() {
    if (current) current = current->prev;
    return *this;
}

template <typename T>
typename DoubleList<T>::Iterator DoubleList<T>::Iterator::operator--(int) {
    Iterator temp = *this;
    if (current) current = current->prev;
    return temp;
}

// --- List ---
template <typename T>
DoubleList<T>::DoubleList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
DoubleList<T>::~DoubleList() { clear(); }

template <typename T>
void DoubleList<T>::clear() {
    while (!empty()) pop_front();
}

template <typename T>
void DoubleList<T>::push_front(T data) {
    Element* newElem = new Element(data);
    if (empty()) {
        head = tail = newElem;
    } else {
        newElem->next = head;
        head->prev = newElem;
        head = newElem;
    }
    count++;
}

template <typename T>
void DoubleList<T>::push_back(T data) {
    Element* newElem = new Element(data);
    if (empty()) {
        head = tail = newElem;
    } else {
        tail->next = newElem;
        newElem->prev = tail;
        tail = newElem;
    }
    count++;
}

template <typename T>
void DoubleList<T>::insert(int index, T data) {
    if (index < 0 || index > count) throw std::out_of_range("Index out of range");
    if (index == 0) { push_front(data); return; }
    if (index == count) { push_back(data); return; }

    Element* curr = head;
    for (int i = 0; i < index; ++i) curr = curr->next;
    
    Element* newElem = new Element(data);
    newElem->next = curr;
    newElem->prev = curr->prev;
    curr->prev->next = newElem;
    curr->prev = newElem;
    count++;
}

template <typename T>
void DoubleList<T>::pop_front() {
    if (empty()) return;
    Element* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
    count--;
}

template <typename T>
void DoubleList<T>::pop_back() {
    if (empty()) return;
    Element* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
    count--;
}

template <typename T>
void DoubleList<T>::remove(T data) {
    Element* curr = head;
    while (curr) {
        if (curr->data == data) {
            Element* toDel = curr;
            curr = curr->next;
            
            if (toDel->prev) toDel->prev->next = toDel->next;
            else head = toDel->next;
            
            if (toDel->next) toDel->next->prev = toDel->prev;
            else tail = toDel->prev;
            
            delete toDel;
            count--;
        } else {
            curr = curr->next;
        }
    }
}

template <typename T>
size_t DoubleList<T>::size() const { return count; }
template <typename T>
bool DoubleList<T>::empty() const { return count == 0; }
template <typename T>
T& DoubleList<T>::front() { return head->data; }
template <typename T>
T& DoubleList<T>::back() { return tail->data; }

template <typename T>
typename DoubleList<T>::Iterator DoubleList<T>::begin() { return Iterator(head); }
template <typename T>
typename DoubleList<T>::Iterator DoubleList<T>::end() { return Iterator(nullptr); }
template <typename T>
typename DoubleList<T>::Iterator DoubleList<T>::last() { return Iterator(tail); }

#endif
