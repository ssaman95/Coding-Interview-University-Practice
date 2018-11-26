#ifndef HASH_OBJECT_H
#define HASH_OBJECT_H

#include <string>

namespace as {

class HashObject {

private:
    std::string key_;
    std::string value_;

public:
    HashObject() {}
    ~HashObject() {}
    HashObject(const HashObject &) = delete;
    HashObject &operator = (const HashObject &) = default;

    std::string &GetValue() { return value_; }
    std::string &GetKey() { return key_; }
    void SetAsDummy() {
        key_ = GetDummyKey();
        value_ = "";
    }
    void SetKey(const std::string key) { key_ = key; }
    void SetValue(const std::string value) { value_ = value; }
    static const std::string GetDummyKey() { return "<Dummy>"; }
    static const std::string GetNullKey() { return "<Null>"; }
};

} // namespace as

#endif
