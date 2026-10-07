#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

class Movie
{
  public:
    Movie(string="", int=0);
    Movie(Movie&);
    ~Movie();
    void print();
    int  getYear();

  private:
    string title;
    int    year;
};

#endif
