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
      "bin/ov",
      "ls"
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

  TEST(AppConstructor, initReturnsSuccess) {
    int argc = 2;
    char* argv[] = {
      "bin/ov",
      "init"
    };

    // Create overlord instance and asser
    App overlord(argc, argv);
    ASSERT_EQ(overlord.init(), 0);
  }

  TEST(AppConstructor, listReturnsSuccess) {
    int argc = 2;
    char* argv[] = {
      "bin/ov",
      "ls"
    };

    // Create overlord instance and asser
    App overlord(argc, argv);
    ASSERT_EQ(overlord.init(), 0);
  }

  TEST(AppConstructor, runReturnsSuccess) {
    int argc = 2;
    char* argv[] = {
      "bin/ov",
      "run"
    };

    // Create overlord instance and asser
    App overlord(argc, argv);
    ASSERT_EQ(overlord.init(), 0);
  }

  TEST(AppConstructor, canDetectUID) {
    int argc = 2;
    char* argv[] = {
      "bin/ov",
      "ov"
    };

    // Create overlord instance and asser
    App overlord(argc, argv);
    ASSERT_STREQ(overlord.getActiveProjectUID().c_str(), argv[1]);
  }

  TEST(AppConstructor, buildReturnsSuccess) {
    int argc = 2;
    char* argv[] = {
      "bin/ov",
      "build"
    };

    // Create overlord instance and asser
    App overlord(argc, argv);
    ASSERT_EQ(overlord.init(), 0);
  }

  TEST(AppConstructor, editReturnsSuccess) {
    int argc = 2;
    char* argv[] = {
      "bin/ov",
      "edit"
    };

    // Create overlord instance and asser
    App overlord(argc, argv);
    ASSERT_EQ(overlord.init(), 0);
  }
}