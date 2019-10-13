#ifndef SVECTOR_TEST_H
#define SVECTOR_TEST_H

namespace as {

class SVectorTest {
public:
    void RunTests() const;
    void TestSize() const;
    // Tests increases and decreases in capacity based on number of items stored.
    void TestCapacity() const;
    void TestIsEmpty() const;
    void TestGetValueAt() const;
    void TestPop() const;
    void TestInsert() const;
    void TestPrepend() const;
    void TestDelete() const;
    void TestRemove() const;
    void TestFind() const;
};

} // namespace as

#endif
