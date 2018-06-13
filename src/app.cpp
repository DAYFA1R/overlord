#include "app.h"

#include <iostream>
#include "yaml-cpp/yaml.h"

App::App(int totalArgs, char** argValues) {
  // Loop through args and retain as type string (from char*)
  if (totalArgs > 1) {
    // Start loop at 1 because index 0 is just the executable (boring)
    for (int currentArg = 1; currentArg < totalArgs; ++currentArg) {
      arguments.push_back(string(argValues[currentArg]));
    }
    // Set the first argument as the command 
    primaryCommand = arguments.at(0);
  } else {
    // Default to help command if no args passed
    primaryCommand = "help";
  }
  
  // Read from master file in home directory
}

void App::init() {
  // Testing init || TODO: remove this later
  cout << "Active Command: " << this->primaryCommand << "\n";
}

string App::getPrimaryCommand() {
  return this->primaryCommand;
}