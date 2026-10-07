#ifndef MOVIEGROUP_H
#define MOVIEGROUP_H

#include "Movie.h"

#define MAX_MOVIES 64

class MovieGroup 
{
    public: 
        MovieGroup();
        MovieGroup(MovieGroup&);
        ~MovieGroup();
        void add(Movie*);
        void print();
    
    private: 
        Movie* movies[MAX_MOVIES];
        int    numMovies;
};

#endif;