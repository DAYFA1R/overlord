#include "gtest/gtest.h"

TEST(SomeSuite, FirstTest) {
	ASSERT_EQ(6, 6);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}