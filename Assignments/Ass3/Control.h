#ifndef CONTROL_H
#define CONTROL_H

#include "defs.h"
#include "View.h"
#include "Telco.h"

/*
  Class:   Control
  Purpose: Control class that drives the program: it initializes the telco
           data, then repeatedly shows the menu and acts on the user's choice.

  Members:
    view          the View object used to communicate with the end user
    telco         dynamically allocated Telco being managed
    launch()      runs the main menu loop
    initData(), initSubscribers(), initMsgs()   populate the telco
  Destructor:     deallocates the telco
*/

class Control
{
  public:
    Control();
    ~Control();
    void launch();

  private:
    View view;
    Telco* telco;

    void initData(Telco*);
    void initSubscribers(Telco*);
    void initMsgs(Telco*);
};

#endif
