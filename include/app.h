#ifndef APP_H
#define APP_H

#include <string>
#include <vector>
#include "yaml-cpp/yaml.h"

using namespace std;

class App {
  // Variables
  vector<string> arguments;
  string primaryCommand;
  string configPath;
  YAML::Node config;
  signed int activeProjectIndex = -1;
  YAML::Node activeProject;

  
  // Methods
  int delegateCommand();
  signed int lookupProjectByChildDir();
  signed int lookupProjectByUID(string passedArg);
  int runProject();

public:
  App(int totalArgs, char** argValues);
  int init();
  string getPrimaryCommand();
  string getActiveProjectUID();
};

#endif