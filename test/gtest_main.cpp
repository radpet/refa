#include <stdio.h>
#include "gtest/gtest.h"

#include "state-machine/utils/state-test.cpp"
#include "state-machine/utils/transition-test.cpp"

int main(int argc, char **argv) {
    printf("Running tests good luck from gtest_main.cpp\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
