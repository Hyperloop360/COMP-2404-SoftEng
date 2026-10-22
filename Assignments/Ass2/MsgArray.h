#ifndef MSGARRAY_H
#define MSGARRAY_H

#include "Msg.h"

#define MAX_ARR_SIZE 64

class MsgArray {
public:
  MsgArray();
  MsgArray(const MsgArray &other);
  ~MsgArray();

  void cleanup();
  bool add(Msg *msg);
  bool add(MsgArray &other);

  int getSize() const;
  Msg *get(int index) const;
  void print() const;

private:
  Msg *elements[MAX_ARR_SIZE];
  int size; // number of elements
};

#endif
