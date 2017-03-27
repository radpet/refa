#include <stdio.h>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
	printf("Running tests good luck from gtest_main.cpp\n");
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
