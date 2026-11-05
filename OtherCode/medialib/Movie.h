// Movie.h -- demonstrates CONVERSION CONSTRUCTORS
#ifndef MOVIE_H
#define MOVIE_H
#include "Book.h"

class Movie {
  public:
    // CONVERSION CONSTRUCTOR: one parameter of a type OTHER than
    // "reference to Movie". It builds a Movie from an int.
    // (Also acts as the default ctor thanks to the default argument.)
    // Not 'explicit' -> may be called IMPLICITLY:  Movie m = 120;
    Movie(int minutes = 0);

    // 'explicit' disables IMPLICIT calls (accidental conversions),
    // explicit calls such as Movie m(book); still work.
    explicit Movie(const Book& source);

    ~Movie();

    const char* getTitle()   const;
    int         getMinutes() const;

  private:
    char title[64];
    int  minutes;
};

#endif
