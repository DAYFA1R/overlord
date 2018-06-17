#include "globals.h"
#include <stdio.h>
#include <unistd.h>
#define GetCurrentDir getcwd

string global::getCurrentWorkingDirectory() {
  char buffer[FILENAME_MAX];
  char* directory = GetCurrentDir(buffer, FILENAME_MAX);
  return string(directory);
}