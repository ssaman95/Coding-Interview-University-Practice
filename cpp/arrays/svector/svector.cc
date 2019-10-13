#include <iostream>
#include <memory>
#include <cstdio>
#include "svector.h"

namespace as {

//const int kMinCapacity = 16;
//const int kGrowthFactor = 2;
//const int kShrinkFactor = 4;

SVector::SVector(int capacity) : size_(0) {
    if (capacity < 1) {
        std::cout << "Can't make array of that size" << std::endl;
        exit(EXIT_FAILURE);
    }

    int true_capacity = DetermineCapacity(capacity);

    capacity_ = true_capacity;
    data_ = std::unique_ptr<int[]>(new int[true_capacity]);
}

SVector::~SVector() {}

int SVector::DetermineCapacity(int capacity) const {
    int true_capacity = kMinCapacity;

    while (capacity > true_capacity / kGrowthFactor) {
        true_capacity *= kGrowthFactor;
    }

    return true_capacity;
}

int SVector::GetSize() const { return size_; }

bool SVector::IsEmpty() const { return size_ == 0; }

int SVector::GetCapacity() const { return capacity_; }

void SVector::DebugString() const {
    std::cout << "Size: " << size_ << std::endl;
    std::cout << "Capacity: " << capacity_ << std::endl;
    std::cout << "Items: " << std::endl;

    for (int i = 0; i < size_; ++i) {
        printf("%d: %d", i, data_[i]);
        std::cout << std::endl;
    }
}

void SVector::Push(int item) {
    ResizeForSize(size_ + 1);

    data_[size_++] = item;
}

void SVector::ResizeForSize(int candidate_size) {
    if (size_ < candidate_size && size_ == capacity_) {
        IncreaseSize();
    } else if (size_ > candidate_size && size_ < capacity_ / kShrinkFactor) {
        DecreaseSize();
    }
}

void SVector::IncreaseSize() {
    int old_capacity = capacity_;
    int new_capacity = DetermineCapacity(old_capacity);

    std::unique_ptr<int[]> new_data(new int[new_capacity]);

    for (int i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
    }

    data_ = std::move(new_data);
    capacity_ = new_capacity;
}

void SVector::DecreaseSize() {
    int old_capacity = capacity_;
    int new_capacity = old_capacity / kGrowthFactor;

    if (new_capacity < kMinCapacity) {
        new_capacity = kMinCapacity;
    }

    if (new_capacity != old_capacity) {
        std::unique_ptr<int[]> new_data(new int[new_capacity]);

        for (int i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }

        data_ = std::move(new_data);
        capacity_ = new_capacity;
    }
}

int SVector::GetValueAt(int index) const {
    if (index < 0 || index >= size_) {
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    return data_[index];
}

int SVector::Pop() {
    if (size_ == 0) {
        std::cout << "Nothing to pop" << std::endl;
        exit(EXIT_FAILURE);
    }

    ResizeForSize(size_ - 1);

    int popped_value = data_[size_ - 1];

    --size_;

    return popped_value;
}

void SVector::Insert(int index, int value) {
    if (index < 0 || index >= size_) {
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    ResizeForSize(size_ + 1);

    for (int i = size_; i > index; --i) {
        data_[i] = data_[i - 1];
    }

    data_[index] = value;

    ++size_;
}

void SVector::Prepend(int value) { Insert(0, value); }

void SVector::Delete(int index) {
    if (index < 0 || index >= size_) {
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    ResizeForSize(size_ - 1);

    for (int i = index; i < size_ - 1; ++i) {
        data_[i] = data_[i + 1];
    }

    --size_;
}

void SVector::Remove(int value) {
    for (int i = 0; i < size_; ++i) {
        if (data_[i] == value) {
            Delete(i);
            --i;
        }
    }
}

int SVector::Find(int value) const {
    int found_index = -1;

    for (int i = 0; i < size_; ++i) {
        if (data_[i] == value) {
            found_index = i;
            break;
        }
    }

    return found_index;
}


} // namespace as
