#ifndef SUBARRAY_H
#define SUBARRAY_H

#include "defs.h"
#include "Subscriber.h"

/*
  Class:   SubArray
  Purpose: Collection class storing Subscriber pointers in a fixed-capacity array.

  Members:
    elements    the array of subscriber pointers
    size        the number of subscribers stored
    getSize()   getter for the size
    get()       returns the subscriber at the given index, or NULL on error
    add()       adds a subscriber to the end of the array
    cleanup()   deallocates all the subscribers
*/

class SubArray
{
  public:
    SubArray();
    int getSize();
    Subscriber* get(int);
    void add(Subscriber*);
    void cleanup();

  private:
    Subscriber* elements[MAX_ARR_SIZE];
    int size;
};

#endif
