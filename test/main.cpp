#include "gtest/gtest.h"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  setenv("MODE", "test", true);
  return RUN_ALL_TESTS();
}