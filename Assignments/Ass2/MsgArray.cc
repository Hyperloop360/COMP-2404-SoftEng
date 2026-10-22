#include <iostream>
using namespace std;

#include "MsgArray.h"

MsgArray::MsgArray() { size = 0; }

MsgArray::MsgArray(const MsgArray &other) {
  size = 0;
  for (int i = 0; i < other.size; ++i)
    add(other.elements[i]);
}

MsgArray::~MsgArray() {}

void MsgArray::cleanup() {
  for (int i = 0; i < size; ++i) {
    delete elements[i];
  }
  size = 0;
}

bool MsgArray::add(Msg *msg) {
  if (size >= MAX_ARR_SIZE)
    return false;

  int index = size;
  for (int i = 0; i < size; ++i) {
    if (msg->greaterThan(elements[i])) {
      index = i;
      break;
    }
  }

  for (int i = size; i > index; --i) {
    elements[i] = elements[i - 1];
  }

  elements[index] = msg;
  size++;
  return true;
}

bool MsgArray::add(MsgArray &other) {
  bool success = true;
  for (int i = 0; i < other.size; ++i) {
    if (!add(other.elements[i])) {
      success = false;
    }
  }
  return success;
}

int MsgArray::getSize() const { return size; }

Msg *MsgArray::get(int index) const {
  if (index >= 0 && index < size) {
    return elements[index];
  }
  return nullptr;
}
void MsgArray::print() const {
  if (size == 0) {
    cout << "No messages" << endl;
    return;
  }
  for (int i = 0; i < size; ++i) {
    elements[i]->print();
    cout << endl;
  }
}
