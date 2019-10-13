#include <iostream>
#include <memory>
#include "svector.h"
#include "svector_test.h"

int main() {
    as::SVectorTest tester;
    std::cout << "Beginning Tests" << std::endl;
    tester.RunTests();
    std::cout << "Testing done" << std::endl;

    return EXIT_SUCCESS;
}
