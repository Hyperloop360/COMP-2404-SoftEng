#include <iostream> 
using namespace std;

#include "MovieGroup.h"

MovieGroup::MovieGroup()
{
  numMovies = 0;
}

MovieGroup::MovieGroup(MovieGroup& souce)
{
    numMovies = 0;

    for (int i = 0; i < souce.numMovies; i++)
    {
        Movie* m = new Movie(*souce.movies[i]);
        add(m);
    }
}

MovieGroup::~MovieGroup()
{
  for (int i = 0; i < numMovies; i++)
  {
    delete movies[i];
  }
}

void MovieGroup::add(Movie* m)
{
    if (numMovies >= MAX_MOVIES){
        cout << "Error: movie group is full, cannot add movie" << endl;
        delete m;
        return;
    }

    // find input point ascending by year 
    int ip = 0;
    while (ip < numMovies && m->getYear() > movies[ip]->getYear())
        ++ip;

    // shift elements starting at the end
    for (int i = numMovies; i > ip; --i)
        movies[i] = movies[i-1];
    
    movies[ip] = m;
    ++numMovies;
}

void MovieGroup::print()
{
  for (int i = 0; i < numMovies; i++){
    movies[i]->print();
  }
}