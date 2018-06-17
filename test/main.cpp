#include "gtest/gtest.h"

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	//setenv("TESTING", "true", true);
	std::cout << "$TESTING";
	return RUN_ALL_TESTS();
}