#ifndef THING_H
#define THING_H

#include <string>

class Thing {
public:
  Thing(int = 0, std::string = "");
  ~Thing();

private:
  int id;
  std::string location;
};

#endif
