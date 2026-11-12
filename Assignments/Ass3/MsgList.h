#ifndef MSGLIST_H
#define MSGLIST_H

#include "defs.h"
#include "Msg.h"

/*
  Class:   MsgList
  Purpose: Collection class storing Msg pointers in a doubly linked list
           without a tail and without dummy nodes. The list is kept in
           descending order by date and time.

  Members:
    head         pointer to the first node
    size         number of messages in the list
    Node         private nested class holding a Msg pointer and the links
    getSize()    getter for the size
    add()        inserts a message in its sorted position
    copySubset() adds the messages of another list that have the given
                 phone number as source or destination (the messages are shared)
    copySubset() overload: same, but matches only the source (C_SENDER) or
                 only the destination (C_RECEIVER)
    cleanup()    deallocates the nodes and the messages
    print()      prints the list forward, then backward
  Destructor:    deallocates the nodes only
*/

class MsgList
{
  class Node
  {
    public:
      Msg*  data;
      Node* prev;
      Node* next;
  };

  public:
    MsgList();
    ~MsgList();
    int getSize();
    void add(Msg*);
    void copySubset(string, MsgList&);
    void copySubset(string, MsgList&, SubscriberType);
    void cleanup();
    void print();

  private:
    Node* head;
    int   size;
};

#endif
