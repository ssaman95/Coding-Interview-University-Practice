#ifndef SLIST_H
#define SLIST_H

namespace as {

template<class T>
class SList<T> {

private:
    SNode<T> *head_;

public:
    SList() : head_(nullptr) {}
    ~SList() {}
    const T & ValueAt(int index) const;
    void PrintDebug() const;
    void PushFront(T value);
    const T PopFront();
    void PushBack(T value);
    const T PopBack();
    const T Front() const;
    const T Back() const;
    void Insert(int index, T value);
    void Erase(int index);
    const T ValueNFromEnd(int n) const;
    void Reverse();
    void RemoveValue(T value);

};


} //namespace as

