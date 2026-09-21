#include "defs.h"

void doubleNum(int& n)
{
  if (checkNum(n))
  {
    n *= 2;
  }
}

bool checkNum(int n)
{
  return (n>=0 && n<=100);
}

