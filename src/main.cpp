#include <stdlib.h>  
#include "app.h"

int main(int argc, char** argv) {
  setenv("MODE", "user", true);
  App overlord(argc, argv);
  overlord.init();
  return 0;
}
