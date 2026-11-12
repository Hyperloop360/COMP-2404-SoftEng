#include "SubArray.h"

SubArray::SubArray() : size(0)
{
  for (int i = 0; i < MAX_ARR_SIZE; ++i)
    elements[i] = NULL;
}

int SubArray::getSize() { return size; }

Subscriber* SubArray::get(int index)
{
  if (index < 0 || index >= size)
    return NULL;
  return elements[index];
}

void SubArray::add(Subscriber* sub)
{
  if (sub == NULL || size >= MAX_ARR_SIZE)
    return;
  elements[size++] = sub;
}

void SubArray::cleanup()
{
  for (int i = 0; i < size; ++i) {
    delete elements[i];
    elements[i] = NULL;
  }
  size = 0;
}
