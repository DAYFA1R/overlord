#ifndef APP_H
#define APP_H

#include <string>
#include <vector>

using namespace std;

class App {
  // Variables
  vector<string> projectList;
  vector<string> arguments;
  string primaryCommand;
  
  // Methods
  void delegateCommand();

public:
  App(int totalArgs, char** argValues);
  void init();
  string getPrimaryCommand();
};

#endif