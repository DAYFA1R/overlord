#include "gtest/gtest.h"
#include "../src/app.cpp"

namespace {
  // Stub args
  int argc = 2;
  char* argv[] = {
    "bin/ov"
    "list",
    "-r"
  };

  // Create overlord instance with stubbed args
  App overlord(argc, argv);

  // Test if App::primaryCommand is the second value in argv
  TEST(AppConstructor, primaryCommandIsArgAfterExe) {
    // See if both strings are equal
    ASSERT_STREQ(overlord.getPrimaryCommand().c_str(), argv[1]);
  }
}