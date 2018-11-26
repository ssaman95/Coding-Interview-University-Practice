#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "hash_object.h"

namespace as {

class HashTable {

private:
    HashObject *data_;
    int size_;

    int Hash(const std::string);

public:
    explicit HashTable(const int size);
    ~HashTable();
    HashTable(const HashTable &) = delete;
    HashTable &operator=(const HashTable &) = delete;

    void Add(HashObject *object);
    bool Exists(const std::string key);
    const std::string Get(const std::string key);
    void Remove(const std::string key);
    void Print();
};

} // namespace as

#endif
