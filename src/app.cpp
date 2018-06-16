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
}

void App::init() {
  this->delegateCommand();
}

string App::getPrimaryCommand() {
  return this->primaryCommand;
}

void App::delegateCommand() {
  if (this->primaryCommand == "help" || this->primaryCommand == "h") {
    cout << "help" << endl;
    return;
  }

  // List
  if (this->primaryCommand == "ls" || this->primaryCommand == "l") {
    cout << "list" << endl;
    return;
  }

  // Initialize project
  if (this->primaryCommand == "init" || this->primaryCommand == "i") {
    cout << "init" << endl;
    return;
  }

  // Build
  if (this->primaryCommand == "build" || this->primaryCommand == "b") {
    cout << "build" << endl;
    return;
  }

  // Run
  if (this->primaryCommand == "run" || this->primaryCommand == "r") {
    cout << "run" << endl;
    return;
  }

  // Edit
  if (this->primaryCommand == "edit" || this->primaryCommand == "e") {
    cout << "edit" << endl;
    return;
  }
}