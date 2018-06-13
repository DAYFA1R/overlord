#ifndef APP_H
#define APP_H

#include <string>
#include <vector>

using namespace std;

class App {
  vector<string> projectList;
  vector<string> arguments;
  string primaryCommand;

public:
  App(int totalArgs, char** argValues);
  void init();
  string getPrimaryCommand();
};

#endif