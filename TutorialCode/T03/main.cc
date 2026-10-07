#include <iostream>
using namespace std;

#include "MovieGroup.h"

void initMovies(MovieGroup&);


int main()
{
  MovieGroup movies1;
  initMovies(movies1);

  cout << "Movie Group 1:" << endl;
  movies1.print();

  MovieGroup movies2(movies1);

  movies2.add(new Movie("The GodFather", 2014));
  movies2.add(new Movie("The Matrix", 1999));
  movies2.add(new Movie("Aliens", 1986));

  cout << endl << "Movie Group 1" << endl;
  movies1.print();

  cout << endl << "Movie Group 2" << endl;
  movies2.print();


  return 0;
}

void initMovies(MovieGroup& mg)
{
  Movie* m;

  m = new Movie("E.T. The Extra-Terrestrial", 1982);
  mg.add(m);
  m = new Movie("Metropolis", 1927);
  mg.add(m);
  m = new Movie("Gravity", 2013);
  mg.add(m);
  m = new Movie("Arrival", 2016);
  mg.add(m);
  m = new Movie("Star Wars: The Last Jedi", 2017);
  mg.add(m);
  m = new Movie("Alien", 1979);
  mg.add(m);
  m = new Movie("War for the Planet of the Apes", 2017);
  mg.add(m);
  m = new Movie("Wall-E", 2008);
  mg.add(m);
  m = new Movie("Star Trek", 2009);
  mg.add(m);
  m = new Movie("Terminator", 1984);
  mg.add(m);
  m = new Movie("Invasion of the Body Snatchers", 1956);
  mg.add(m);
  m = new Movie("The Day the Earth Stood Still", 1951);
  mg.add(m);
  m = new Movie("Jurassic Park", 1993);
  mg.add(m);
  m = new Movie("Back to the Future", 1985);
  mg.add(m);
  m = new Movie("Blade Runner", 1982);
  mg.add(m);
}

