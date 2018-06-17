#include "app.h"
#include "globals.h"
#include <unistd.h>
#include <iostream>
#include <fstream>

App::App(int totalArgs, char** argValues) {
  // Determine path to config and Load YAML from it
  // if (getenv("TESTING") == "true") {
  //   configPath = string("test/.overlord.yaml");
  // }
  //  else {
  configPath = string(getenv("HOME")) += "/.overlord.yaml";
  // }
  config = YAML::LoadFile(configPath);

  // Loop through args and retain as type string (from char*)
  if (totalArgs > 1) {
    // Start loop at 1 because index 0 is just the executable (boring)
    for (int currentArg = 1; currentArg < totalArgs; ++currentArg) {
      this->arguments.push_back(string(argValues[currentArg]));
    }

    // check if the first arg is the UID of an already declared project
    this->activeProjectIndex = this->lookupProjectByUID(this->arguments.at(0));

    // if UID was found
    if (this->activeProjectIndex >= 0) {
      // Set it as the session's active project
      this->activeProject = this->config["projects"][this->activeProjectIndex];

      // if a command was passed with UID
      if (totalArgs > 2) {
        // use the second passed arg for delegation
        this->primaryCommand = this->arguments.at(1);
      } else {
        cout << "\033[1;35moverlord \033[1;32m(success):\033[0m \033[1m Project \033[1;36m" << this->activeProject["uid"] << "\033[1;37m found!\033[0m" <<endl;
      }
    }

    // Otherwise
    else {
      // Check if current directory is the directory of a declared project
      // OR
      // Check if the current directory is a child of a declared project
      this->activeProjectIndex = this->lookupProjectByChildDir();
      // if directory was found
      if (this->activeProjectIndex >= 0) {
        // Set it as the session's active project
        this->activeProject = this->config["projects"][this->activeProjectIndex];
      }
      // use the first arg passed for delegation
      this->primaryCommand = this->arguments.at(0);
    }
  } else {
    // Default to help command if no args passed
    this->primaryCommand = "help";
  }
}

void App::init() {
  this->delegateCommand();
}

signed int App::lookupProjectByChildDir() {
  // Get the total amount of projects listed in overlord.yaml
  int totalProjects = this->config["projects"].size();

  // Iterate through each project
  for (int project = 0; project < totalProjects; ++project) {
    string thisProjectDir = this->config["projects"][project]["dir"].as<string>();
    string currentDir = global::getCurrentWorkingDirectory();
    
    // If a project's directory is a substring of the current directory
    if (currentDir.find(thisProjectDir) != string::npos) {
      return project;
    }
  }

  // Otherwise, show the user an error about their path
  cout << "\033[1;35moverlord \033[1;31m(error):\033[0m \033[1mCurrent directory is not a descendent of any known project\033[0m" << endl;
  return -1;
}

signed int App::lookupProjectByUID(string passedArg) {
  int totalProjects = this->config["projects"].size();

  for (int project = 0; project < totalProjects; ++project) {
    string thisProjectUID = this->config["projects"][project]["uid"].as<string>();

    if (thisProjectUID == passedArg) {
      return project;
    }
  }
  return -1;
}

string App::getPrimaryCommand() {
  return this->primaryCommand;
}

int App::delegateCommand() {
  // General Commands
  if (this->primaryCommand == "help" || this->primaryCommand == "h") {
    cout << "help" << endl;
    // return;
  }

  // List
  if (this->primaryCommand == "ls" || this->primaryCommand == "l") {
    cout << "list" << endl;
    // return;
  }

  // Initialize project
  if (this->primaryCommand == "init" || this->primaryCommand == "i") {
    cout << "\033[1;35moverlord \033[1;33m(warning):\033[0m \033[1m CLI initializer coming soon. Please edit \".overlord.yaml\" in your home directory to configure your projects. Thanks! \033[0m" <<endl;
    return 0;
  }

  // Active Project Commands
  if (this->activeProjectIndex >= 0) {
    // Build
    if (this->primaryCommand == "build" || this->primaryCommand == "b") {
      cout << "build" << endl;
      // return;
    }

    // Run
    if (this->primaryCommand == "run" || this->primaryCommand == "r") {
      return this->runProject();
    }

    // Edit
    if (this->primaryCommand == "edit" || this->primaryCommand == "e") {
      cout << "edit" << endl;
      // return;
    }
  }

  return 1;
}

int App::runProject() {
  string runCommand = this->activeProject["run"].as<string>();
  cout << "\033[1;35moverlord \033[1;32m(success):\033[0m \033[1m Executing \033[1;36m" << runCommand << "\033[0m" <<endl;
  system(runCommand.c_str());
  return 0;
}