#include <iostream>
#include "slist.h"

namespace as {

template<class T>
SList<T>::~SList() {
    SNode<T> *current = head_;
    SNode<T> *next = nullptr;


    while (current) {
        next = current->GetNext();
        delete current;
        current = next;
    }
}

template<class T>
const T & SList<T>::ValueAt(int index) {
    if (index < 0) {
        std::cout << "Negative Index\n" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto current = head_;
    int i = 0;

    for (; i < index && current; ++i) {
        current = current->GetNext();
    }

    if (current == nullptr) {
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    return current->GetData();
}

template<class T>
bool SList<T>::Empty() { return head_ == nullptr; }

template <class T>
void Slist<T>::PrintDebug() const {
    SNode<T> *current = head_;

    std::cout << std::endl;

    while (current != nullptr) {
        std::cout << current->GetData() << " --> ";
        current = current->GetNext();
    }

    std::cout << std::endl;
}

template <class T>
void SList<T>::PushFront(T value) {
    SNode<T> *node = new SNode<T>{value};
    node->SetNext(head_);

    head_ = node;
}

template <class T>
const T SList<T>::PopFront() {
    if (!head_) {
        std::cout << "Empty List" << std::endl;
        exit(EXIT_FAILURE);
    }

    SNode<T> *front = head_;
    T value = front->GetData();

    head_ = head_->GetNext();

    delete front;

    return value;
}

template <class T>
void SList<T>::PushBack(T value) {
    SNode<T> *node = new SNode<T>{value};

    if (head_ == nullptr) {
        head_ = node;
        return;
    }

    SNode<T> *current = head_;

    while (current->GetNext()) {
        current = curent->GetNext();
    }

    current->SetNext(node);
}

template <class T>
const T & SList<T>::PopBack() {
    if (!head_) {
        std::cout << "Empty List" << std::endl;
        exit(EXIT_FAILURE);
    }

    SNode<T> *current = head_;
    SNode<T> *prev = nullptr;

    while (current->GetNext()) {
        prev = current;
        current = current->GetNext();
    }

    T value = current->GetData();

    if (prev) {
        prev->SetNext(current->GetNext());
    } else {
        head_ = nullptr;
    }

    delete current;

    return value;
}

template <class T>
const T SList<T>::Front() const {
    if (!head_) {
        std::cout << "Empty List" << std::endl;
        exit(EXIT_FAILURE);
    }

    return head_->GetData();
}

template <class T>
const T SList<T>::Back() const {
    if(!head) {
        std::cout << "Empty List" << std::endl;
        exit(EXIT_FAILURE);
    }

    SList<T> *current = head_;

    while (current->GetNext()) {
        current = current->GetNext();
    }

    return current->GetData();
}

template <class T>
void SList<T>::Insert(int index, T value) {
    auto current = head_;
    SNode *prev = nullptr;

    int  i = 0;

    for (; i < index && current; ++i) {
        prev = current();
        current = current->GetNext();
    }

    if (i != index) {
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    SList<T> node = new SList<T>{value};

    if (prev) {
        node->SetNext(current);
        prev->SetNext(node);
    } else {
        node->SetNext(head_);
        head_ = node;
    }
}

template <class T>
void SList<T>::Erase(int index) {
    if (!head_) {
        std::cout << "Empty List" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto current = head_;
    SList<T> *prev = nullptr;

    int i;
    for (i = 0; i < index && current; ++i) {
        prev = current;
        current = current->GetNext();
    }

    if (i != index) {
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (prev) {
        prev->SetNext(current->GetNext());
    } else {
        head_ = current->GetNext();
    }

    delete current;
}

template <class T>
const T ValueNFromEnd(int n) const {
    if (n < 1 || !head_) {
        std::cout << "Can not return nth element from last" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto current = head_;
    auto match = head_;

    int i;
    for (i = 0; i < index && current; ++i) {
        current = current->GetNext();
    }

    if (i != n) {
        std::cerr << "Can not reach nth element from last" << std::endl;
        exit(EXIT_FAILURE);
    }

    while (current) {
        current = current->GetNext();
        match = match->GetNext();
    }

    return match->GetData();
}

template <class T>
void SList<T> Reverse() {
    SList<T> *prev = nullptr;
    SList<T> *current = head_;
    SList<T> *next = head_;

    while (current) {
        next = current->GetNext();
        current->SetNext(prev);
        prev = current;
        current = next;
    }

    head_ = prev;
}

template <class T>
void SList<T> RemoveValue(T value) {
    if (!head_) {
        std::cout << "Empty List" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto current = head_;
    SNode<T> *prev = nullptr;

    while (current) {
        if (current->GetData() == value) {
            if (prev) {
                prev->SetNext(current->GetNext());
            } else {
                head_ = current->GetNext();
            }
            
            delete current;
            break;
        }

        prev = current;
        current = current->GetNext();
    }
}

} // namespace as
