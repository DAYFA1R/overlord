#include "gtest/gtest.h"
#include "yaml-cpp/yaml.h"

// Test this source file
#include "../src/globals.cpp"
#include "../src/app.cpp"

namespace {
  // Test if App::primaryCommand is the second value in argv
  TEST(AppConstructor, primaryCommandIsArgAfterExe) {
    // Local stubs
    int argc = 2;
    char* argv[] = {
      "bin/ov"
      "list",
      "-r"
    };
    
    // Create overlord instance and assert
    App overlord(argc, argv);
    ASSERT_STREQ(overlord.getPrimaryCommand().c_str(), argv[1]);
  }

  TEST(AppConstructor, primaryCommandDefaultsToHelp) {
    // Local stubs
    int argc = 1;
    char* argv[] = {
      "bin/ov"
    };

    // Create overlord instance and assert
    App overlord(argc, argv);
    ASSERT_STREQ(overlord.getPrimaryCommand().c_str(), "help");
  }
}