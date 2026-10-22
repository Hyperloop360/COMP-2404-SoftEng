#ifndef CONTROL_H
#define CONTROL_H

#include "Telco.h"
#include "View.h"

/**
 *Class: Control
 *Purpose: Manages the program control flow, user interaction via View,
 and holds the main Telco object
 */

class Control {
public:
  Control();
  ~Control();

  void launch();

private:
  Telco *telco;
  View view;

  void initData(Telco *t);
  void initSubscribers(Telco *t);
  void initMsgs(Telco *t);
};

#endif
