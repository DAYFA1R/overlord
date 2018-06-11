#include "app.h"

int main(int argc, char** argv) {
  App overlord(argc, argv);
  overlord.init();
  return 0;
}

// Placeholder until Makefile exists
// g++ -o ov src/main.cpp src/app.cpp -I./include -L./lib -lyaml-cpp