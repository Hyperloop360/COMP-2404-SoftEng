#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

#include "Book.h"


class Movie
{
  public:
    Movie(string="Unknown", string="Unknown", int=120);
    Movie(Movie&);
//    explicit Movie(Book&);
    Movie(Book&);
    ~Movie();
    void print();

  private:
    string title;
    string screenwriter;
    int    duration;
};

#endif
