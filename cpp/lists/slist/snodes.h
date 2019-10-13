#ifndef SNODE_H
#define SNODE_H

namespace as {

template <class T>
class SNode<T> {

private:
    T data_;
    SNode<T> *next_;

public:
    SNode(const T &value) : data_(value), next_(nullptr) {}
    ~SNode() {}
    // SNode(const SNode &) = delete;
    // SNode &operator=(SNode &) = default;

    const T &GetData() const { return data_; }
    SNode<T> *GetNext() const { return next_; }
    void SetData(int value) { data_ = value; }
    void SetNext(SNode<T> *elem) { next_ = elem; }

};

} // namespace as


#endif
