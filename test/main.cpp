#include "gtest/gtest.h"

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	setenv("MODE", "test", true);

	// const char* myenvvar = getenv("MODE");
	// std::cout << myenvvar;
	return RUN_ALL_TESTS();
}