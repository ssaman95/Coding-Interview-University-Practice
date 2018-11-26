#include <iostream>
#include <memory>
#include <cassert>
#include "svector.h"
#include "svector_test.h"


namespace as {

void SVectorTest::RunTests() const {
    std::cout << "Testing..." << std::endl;
    TestSize();
    TestIsEmpty();
    TestCapacity();
    TestGetValueAt();
    TestPop();
    TestInsert();
    TestDelete();
    TestRemove();
    TestFind();
    std::cout << "Finishing..." << std::endl;
}

void SVectorTest::TestSize() const {
    as::SVector tester(3);
    assert(tester.GetSize() == 0);

    int items_to_add = 5;
    for (int i = 0; i < items_to_add; ++i) {
        tester.Push(i + 1);
    }
    assert(tester.GetSize() == items_to_add);
}

void SVectorTest::TestIsEmpty() const {
    as::SVector tester(3);
    assert(tester.IsEmpty());
}

void SVectorTest::TestCapacity() const {
    as::SVector tester(4);

    // test increasing size
    assert(tester.GetCapacity() == as::kMinCapacity);
    for (int i = 0; i < 17; ++i) {
        tester.Push(i + 1);
    }
    assert(tester.GetCapacity() == as::kMinCapacity * 2);
    for (int j = 0; j < 20; ++j) {
        tester.Push(j + 1);
    }
    assert(tester.GetCapacity() == as::kMinCapacity * 4);

    // test decreasing size
    for (int k = 0; k < 30; ++k) {
        tester.Pop();
    }
    assert(tester.GetCapacity() == as::kMinCapacity * 2);

    for (int k = 0; k < 7; ++k) {
        tester.Pop();
    }
    assert(tester.GetCapacity() == as::kMinCapacity);
}

void SVectorTest::TestGetValueAt() const {
    as::SVector tester(3);
    tester.Push(4);
    tester.Push(9);
    tester.Push(12);
    assert(tester.GetValueAt(0) == 4);
    assert(tester.GetValueAt(1) == 9);
    assert(tester.GetValueAt(2) == 12);
}

void SVectorTest::TestPop() const {
    as::SVector tester(1);
    tester.Push(3);

    int popped = tester.Pop();
    assert(popped == 3);
    tester.Push(9);
    tester.Push(8);

    assert(tester.GetSize() == 2);
    int popped2 = tester.Pop();
    assert(popped2 == 8);
    assert(tester.GetSize() == 1);
}

void SVectorTest::TestInsert() const {
    as::SVector tester(3);
    tester.Push(5);
    tester.Push(7);
    tester.Push(9);
    tester.Insert(0, 4);
    assert(tester.GetValueAt(0) == 4);
    assert(tester.GetValueAt(1) == 5);
    assert(tester.GetValueAt(2) == 7);
    assert(tester.GetValueAt(3) == 9);
    tester.Insert(3, 8);
    assert(tester.GetValueAt(3) == 8);
    assert(tester.GetValueAt(4) == 9);
}

void SVectorTest::TestPrepend() const {
    as::SVector tester(3);
    tester.Push(9);
    tester.Push(8);
    tester.Push(7);
    tester.Prepend(6);
    assert(tester.GetSize() == 4);
    assert(tester.GetValueAt(0) == 6);
    assert(tester.GetValueAt(1) == 9);
    assert(tester.GetValueAt(3) == 7);
}

void SVectorTest::TestDelete() const {
    as::SVector tester(1);
    tester.Push(5);
    tester.Delete(0);
    assert(tester.GetSize() == 0);

    tester.Push(9);
    tester.Push(10);
    tester.Push(11);
    tester.Delete(1);
    assert(tester.GetSize() == 2);
    assert(tester.GetValueAt(0) == 9);
    assert(tester.GetValueAt(1) == 11);
}

void SVectorTest::TestRemove() const {
    as::SVector tester(5);
    tester.Push(50);
    tester.Push(2);
    tester.Push(50);
    tester.Push(4);
    tester.Push(50);
    tester.Remove(50);
    assert(tester.GetSize() == 2);
    assert(tester.GetValueAt(0) == 2);
    assert(tester.GetValueAt(1) == 4);
}

void SVectorTest::TestFind() const {
    as::SVector tester(3);
    tester.Push(4);
    tester.Push(7);
    tester.Push(11);
    assert(tester.Find(5) == -1);
    assert(tester.Find(4) == 0);
    assert(tester.Find(7) == 1);
    assert(tester.Find(11) == 2);
}

};
