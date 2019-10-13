#ifndef SVECTOR_H
#define SVECTOR_H


namespace as {

static const int kMinCapacity = 16;
static const int kGrowthFactor = 2;
static const int kShrinkFactor = 4;

class SVector {
private:
    int capacity_{kMinCapacity};
    int size_{0};
    std::unique_ptr<int[]> data_;
    int DetermineCapacity(int capacity)const;
    void ResizeForSize(int candidate_size);
    void IncreaseSize();
    void DecreaseSize();

public:
    SVector(int capacity);
    SVector(const SVector &other) = default;
    ~SVector();
    int GetSize() const;
    bool IsEmpty() const;
    // Returns the capacity of the vector.
    int GetCapacity() const;
    // Prints out public information about the vector.
    void DebugString() const;
    // Appends the given value to the end of the vector.
    void Push(int value);
    // Returns the value stored at the given index
    int GetValueAt(int index) const;
    // Returns the last item in the vector, and removes it.
    int Pop();
    // Inserts the given value at the given index, shifting
    // current and trailing items to the right.
    void Insert(int index, int value);
    // Prepends the given value to the vector, shifting trailing
    // items to the right.
    void Prepend(int value);
    // Deletes item at index, shifting all trailing elements left.
    void Delete(int index);
    // Removes all instances of value from the vector.
    void Remove(int value);
    // Looks for value and returns first index with that value, -1 if not found.
    int Find(int value) const;
};

}
#endif
