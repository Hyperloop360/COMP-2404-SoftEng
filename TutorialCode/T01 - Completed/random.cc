#include <iostream>
#include <cstdlib>

/*    Function:  int random(int max)
       Purpose:  generates a random number in the range [0, max)
    Parameters:  in: max
  Return value:  randomly generated number
*/

int random(int max)
{
	double r = ( (double)rand() / ((double)(RAND_MAX)+(double)(1)) ); 
	return (int)(r * max);
}
